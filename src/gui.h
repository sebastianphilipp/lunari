//
// Created by Sebastian on 15.08.26.
//

#ifndef SRC_GUI_H
#define SRC_GUI_H

#include <contracts/app/view.h>

#include <boost/signals2.hpp>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <gui/menu.h>

#include <event.h>

using ChangeViewSignal = boost::signals2::signal<void(View::eView)>;

class Gui
{
public:
	Gui(SDL_Renderer&, TTF_TextEngine&, TTF_Font&, Event&);

	Menu& menu();

private:
	Menu m_menu;
};


#endif //SRC_GUI_H
