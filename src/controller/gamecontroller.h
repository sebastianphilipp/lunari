//
// Created by Sebastian on 25.10.26.
//

#ifndef SRC_CONTROLLER_GAMECONTROLLER_H
#define SRC_CONTROLLER_GAMECONTROLLER_H

#include <contracts/gui/gamecontroller.h>

#include <array>

namespace controller
{
class GameController : public gui::GameController
{
public:
	void processKey(SDL_Keycode key) override;

private:
	enum GameEvent : uint8_t
	{
		WALK_LEFT = 0,
		WALK_RIGHT,
		WALK_UP,
		WALK_DOWN,
		INTERACT,
		ATTACK
	};

	struct KeyEventMapEntry
	{
		GameEvent event;
		SDL_Keycode key;
	};

	std::array<KeyEventMapEntry, 6U> m_keyEventMap{{{WALK_LEFT, SDLK_LEFT},
													{WALK_RIGHT, SDLK_RIGHT},
													{WALK_UP, SDLK_UP},
													{WALK_DOWN, SDLK_DOWN},
													{INTERACT, SDLK_E},
													{ATTACK, SDLK_SPACE}
												   }};
};
}

#endif //SRC_CONTROLLER_GAMECONTROLLER_H
