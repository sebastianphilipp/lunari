//
// Created by Sebastian on 25.10.26.
//

#ifndef SRC_GUI_GAME_H
#define SRC_GUI_GAME_H

#include <contracts/app/view.h>
#include <contracts/gui/keyevent.h>
#include <contracts/gui/gamecontroller.h>
#include <contracts/gui/worldstate.h>
#include <contracts/gui/playerstate.h>

#include <common/map.h>

namespace gui
{
class Game : public app::View
{
public:
	Game(SDL_Renderer&, KeyEvent&, GameController&, WorldState&, PlayerState&);

	void render() override;
	void entry() override;
	void exit() override;
	[[nodiscard]] common::eView type() const override;
	app::ChangeViewSignal& change() override;

private:
	struct DisplayResolution
	{
		int w;
		int h;
	};

	struct WindowSize
	{
		int w;
		int h;
	};

	static constexpr size_t kReferenceWidth{1920U};
	static constexpr size_t kReferenceHeight{1080U};
	static constexpr size_t kReferenceBlocksPerWidth{48U};
	static constexpr size_t kReferenceBlocksPerHeight{27U};
	static constexpr size_t kReferenceBlockSize{40U};

	SDL_Renderer& m_renderer;
	KeyEvent& m_keyEvent;
	GameController& m_gameController;
	WorldState& m_worldState;
	PlayerState& m_playerState;

	void onKeyDown(SDL_Keycode key);

	void drawMap();
	void drawMapObject(common::eMapObject, float, float, float);
	DisplayResolution displayResoultion(bool&) const;
	WindowSize windowSize() const;

	app::ChangeViewSignal m_change{};
	boost::signals2::scoped_connection m_keyConnection{};
};
}

#endif //SRC_GUI_GAME_H
