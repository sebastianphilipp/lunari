//
// Created by Sebastian on 15.08.26.
//

#ifndef SRC_GUI_H
#define SRC_GUI_H

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <gui/main.h>
#include <gui/menu.h>

#include <event.h>
#include <menu.h>

namespace gui
{
class Gui
{
public:
	Gui(SDL_Renderer&, TTF_TextEngine&, TTF_Font&, event::Event&, menu::Menu&);

	Main& main();
	Menu& menu();

private:
	Main m_main;
	Menu m_menu;
};
}


#endif //SRC_GUI_H
