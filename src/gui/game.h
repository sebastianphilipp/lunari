//
// Created by Sebastian on 25.10.26.
//

#ifndef SRC_GUI_GAME_H
#define SRC_GUI_GAME_H

#include <contracts/app/view.h>
#include <contracts/gui/keyevent.h>
#include <contracts/gui/gamecontroller.h>
#include <contracts/gui/worldstate.h>

namespace gui
{
class Game : public app::View
{
public:
	Game(SDL_Renderer&, KeyEvent&, GameController&, WorldState&);

	void render() override;
	void entry() override;
	void exit() override;
	[[nodiscard]] common::eView type() const override;
	app::ChangeViewSignal& change() override;

private:
	SDL_Renderer& m_renderer;
	KeyEvent& m_keyEvent;
	GameController& m_gameController;
	WorldState& m_worldState;

	void onKeyDown(SDL_Keycode key);

	app::ChangeViewSignal m_change{};
	boost::signals2::scoped_connection m_keyConnection{};
};
}

#endif //SRC_GUI_GAME_H
