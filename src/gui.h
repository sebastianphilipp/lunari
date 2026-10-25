//
// Created by Sebastian on 15.08.26.
//

#ifndef SRC_GUI_H
#define SRC_GUI_H

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <gui/main.h>
#include <gui/menu.h>
#include <gui/game.h>

#include <event.h>
#include <menu.h>
#include <controller.h>
#include <state.h>

namespace gui
{
class Gui
{
public:
	Gui(SDL_Renderer&, TTF_TextEngine&, TTF_Font&, event::Event&, menu::Menu&, controller::Controller&, state::State&);

	Main& main();
	Menu& menu();
	Game& game();

private:
	Main m_main;
	Menu m_menu;
	Game m_game;
};
}


#endif //SRC_GUI_H
