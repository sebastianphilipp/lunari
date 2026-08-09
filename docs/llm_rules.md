# Architecture Rules

## 1. Purpose

This project follows a layered architecture with explicit contracts between layers.

The main goal is to ensure that each layer can access only the operations it actually requires. Interfaces are therefore defined from the perspective of the consuming layer, not from the perspective of the implementation.

This reduces accidental coupling, limits misuse, improves testability, and makes architectural dependencies visible in the type system.

---

## 2. Core Principle: Consumer-Specific Contracts

Every layer must depend on the smallest interface that fully describes its needs.

An interface must not expose operations merely because the underlying implementation supports them.

For example:

- If the logic layer only needs to read game settings, it receives a read-only interface.
- If the GUI layer needs to read and modify game settings, it receives a read/write interface.
- If both layers require exactly the same operations, the contract is forwarded through the intermediate layer instead of being redefined unnecessarily.

This follows the Interface Segregation Principle and enforces least privilege at compile time.

---

## 3. Rule A: Forward Identical Contracts Through Layers

If two adjacent layers require the same interface with the same semantics and the same operations, the interface may be forwarded through the intermediate layer.

The intermediate layer acts as an adapter or relay without changing the contract.

### Example: Key Events

The event layer produces keyboard events.

The logic layer consumes the keyboard-event contract and may forward the same contract to the GUI layer if both layers require the same event semantics.

```text
event::KeyEvent
    implements logic::KeyEvent

logic::Key
    consumes logic::KeyEvent
    implements gui::KeyEvent
```

The forwarding class must not change the meaning of the event unless it is explicitly documented as an adapter.

### Conditions for forwarding

Forward an interface only when all of the following are true:

1. The operations are identical.
2. The semantics are identical.
3. The lifetime expectations are identical.
4. No layer-specific capability must be hidden.
5. No translation of data types or behavior is required.

If any of these conditions is not met, define a separate interface for the consuming layer.

---

## 4. Rule B: Separate Contracts When Layers Need Different Capabilities

If two layers use the same underlying implementation but require different operations, define separate interfaces.

The concrete implementation must implement all required interfaces.

This is preferred over exposing one large interface to every layer.

### Example: Game Settings

The logic layer only requires read access:

```cpp
class GameSettingsReader {
public:
    virtual ~GameSettingsReader() = default;

    virtual common::Difficulty difficulty() const = 0;
    virtual std::string name() const = 0;
};
```

The GUI layer requires read and write access:

```cpp
class GameSettingsEditor {
public:
    virtual ~GameSettingsEditor() = default;

    virtual void setName(std::string name) = 0;
    virtual std::string name() const = 0;

    virtual void setDifficulty(common::Difficulty difficulty) = 0;
    virtual common::Difficulty difficulty() const = 0;
};
```

The implementation provides both contracts:

```cpp
class GameSettings final
    : public logic::GameSettingsReader,
      public gui::GameSettingsEditor {
public:
    void setName(std::string name) override;
    std::string name() const override;

    void setDifficulty(common::Difficulty difficulty) override;
    common::Difficulty difficulty() const override;
};
```

The logic layer cannot modify settings because its contract does not expose setters.

The GUI layer can modify settings because its contract explicitly grants that capability.

---

## 5. Rule C: Implementations May Implement Multiple Interfaces

A concrete class may implement multiple interfaces when it serves multiple layers or roles.

This is valid and encouraged when the interfaces represent distinct capabilities.

Examples:

```text
settings::GameSettings
    implements logic::GameSettings
    implements gui::GameSettings

settings::MapSettings
    implements logic::MapSettings
    implements gui::MapSettings

settings::ScoreboardSettings
    implements logic::ScoreboardSettings
    implements gui::ScoreboardSettings
```

The implementation must not force consumers to depend on all of its capabilities.

Consumers must receive the interface appropriate to their layer.

---

## 6. Rule D: Interfaces Belong to the Consumer

An interface should normally be declared in the layer that consumes it.

This means:

- `logic::GameSettings` describes what the logic layer requires.
- `gui::GameSettings` describes what the GUI layer requires.
- `settings::GameSettings` is the concrete implementation.
- `settings::SettingsFile` describes what the settings layer requires from persistence.
- `ini::SettingsFile` is the concrete persistence implementation.

The implementation depends on the consumer-defined abstraction by implementing it.

This keeps dependency direction stable and prevents high-level layers from depending on low-level implementation details.

---

## 7. Rule E: Do Not Broaden an Interface for Reuse

Do not add methods to an existing interface merely because another layer needs them.

Incorrect:

```cpp
class GameSettings {
public:
    virtual std::string name() const = 0;
    virtual void setName(std::string name) = 0;
};
```

This is incorrect for the logic layer if the logic layer only needs `name()`.

Correct:

```cpp
class GameSettingsReader {
public:
    virtual std::string name() const = 0;
};

class GameSettingsEditor {
public:
    virtual std::string name() const = 0;
    virtual void setName(std::string name) = 0;
};
```

The implementation may implement both interfaces.

---

## 8. Rule F: Shared Data Types Must Be Neutral

Data types shared by multiple layers must be placed in a neutral namespace such as `common` or `domain`.

A shared type must not be owned by a layer that another independent layer should not depend on.

For example, the following types are domain concepts and should not be GUI-owned if both GUI and logic use them:

- `Difficulty`
- `Player`
- `Ghost`
- `GameState`
- `ExitType`
- `ScoreEntry`

Preferred structure:

```text
common or domain
    Difficulty
    Player
    Ghost
    GameState
    ExitType
    ScoreEntry
```

The GUI may render these types, and the logic may produce or modify them, without creating a dependency from logic to GUI.

---

## 9. Rule G: Signals Are Output Contracts

A signal represents an event emitted by an object.

Consumers may subscribe to the signal, but they must not be able to emit it themselves unless that capability is explicitly required.

Prefer connection methods over publicly writable signal objects:

```cpp
class KeyEventSource {
public:
    using Slot = boost::signals2::signal<void(KeyCode)>::slot_type;

    virtual ~KeyEventSource() = default;

    virtual boost::signals2::connection connectKey(const Slot& slot) = 0;
};
```

The concrete implementation owns the actual signal:

```cpp
class SdlKeyEvent final : public KeyEventSource {
public:
    boost::signals2::connection connectKey(const Slot& slot) override {
        return keySignal_.connect(slot);
    }

    void process(const SDL_Event& event);

private:
    boost::signals2::signal<void(KeyCode)> keySignal_;
};
```

Only the event implementation may emit `keySignal_`.

---

## 10. Rule H: Layer Boundaries Must Not Leak Framework Types

Framework-specific types must remain inside the infrastructure or adapter layer that owns them.

Examples:

- `SDL_Event` belongs in the event or SDL adapter layer.
- INI parser types belong in the INI layer.
- Rendering backend types belong in the rendering adapter.

Higher layers must use project-defined types such as:

```text
KeyCode
MouseButton
GameState
ViewType
ExitType
```

This allows infrastructure to be replaced without changing business or application logic.

---

## 11. Rule I: Dependencies Must Point Toward Contracts

Concrete classes must not be referenced across layers when an interface exists.

Incorrect:

```text
gui::Settings -> settings::GameSettings
```

Correct:

```text
gui::Settings -> gui::GameSettings
settings::GameSettings implements gui::GameSettings
```

The application composition root is responsible for constructing concrete implementations and injecting them through their interfaces.

---

## 12. Rule J: The Application Layer Performs Composition

The application layer is responsible for creating and connecting concrete objects.

It may know concrete implementations during startup, but runtime components should depend on interfaces.

Example:

```cpp
settings::GameSettings gameSettings;
settings::MapSettings mapSettings;
event::SdlKeyEvent keyEvents;
logic::GameLogic gameLogic{
    static_cast<logic::GameSettings&>(gameSettings),
    static_cast<logic::MapSettings&>(mapSettings)
};

gui::InGame inGame{
    static_cast<gui::GameSettings&>(gameSettings),
    static_cast<gui::MapSettings&>(mapSettings),
    static_cast<gui::KeyEvent&>(keyEvents)
};
```

The exact syntax may differ, but object creation and dependency wiring should remain centralized.

---

## 13. Decision Guide

Use the following decision process whenever two layers need access to the same implementation.

### Case 1: Both layers need the exact same operations

Forward or reuse the same contract through the layers.

```text
same methods + same semantics
    -> forward the interface
```

### Case 2: One layer needs fewer operations

Define a smaller interface for that layer.

```text
logic needs getters
GUI needs getters and setters
    -> define two interfaces
    -> implementation implements both
```

### Case 3: The method names are similar but semantics differ

Define separate interfaces and use an adapter if necessary.

```text
similar shape + different meaning
    -> separate contracts
```

### Case 4: Data types differ across layers

Define separate interfaces and translate between the data types.

```text
same concept + different representation
    -> adapter or mapper
```

---

## 14. Naming Conventions

Interfaces should be named after the capability or role they provide.

Preferred names:

```text
GameSettingsReader
GameSettingsEditor
ScoreboardReader
ScoreboardWriter
KeyEventSource
GameStateProvider
SettingsStorage
MapSelectionReader
MapSelectionEditor
```

Avoid names that hide the role of the interface:

```text
General
Key
Data
ManagerInterface
SettingsThing
```

A good interface name should explain what the consumer is allowed to do.

---

## 15. Architectural Invariants

The following rules are mandatory:

1. A layer depends only on interfaces that describe its own requirements.
2. Interfaces expose only the operations required by their consumers.
3. Identical contracts may be forwarded through intermediate layers.
4. Different capabilities must be represented by different interfaces.
5. A concrete implementation may implement multiple consumer-specific interfaces.
6. Shared domain types must not be owned by infrastructure or GUI layers.
7. Framework-specific types must not cross architectural boundaries.
8. Signals must be emitted only by their owning implementation.
9. Concrete dependencies are wired only in the application composition root.
10. No layer may gain write access when it only requires read access.

---

## 16. Rationale

This architecture intentionally accepts a larger number of small interfaces.

The additional interfaces are not duplication when they represent different permissions or responsibilities. They are explicit contracts.

The benefits are:

- fewer accidental state changes;
- clearer ownership;
- smaller dependency surfaces;
- easier unit testing;
- simpler mocking;
- safer refactoring;
- better separation between GUI, logic, persistence, and infrastructure;
- compile-time enforcement of allowed operations.

The guiding principle is:

> A consumer should see exactly what it is allowed to use, and nothing more.
