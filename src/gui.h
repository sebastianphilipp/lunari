//
// Created by Sebastian on 15.08.26.
//

#ifndef SRC_GUI_H
#define SRC_GUI_H

#include <contracts/app/view.h>

#include <boost/signals2.hpp>
#include <SDL3/SDL.h>

#include <gui/menu.h>

#include <event.h>

using ChangeViewSignal = boost::signals2::signal<void(View::eView)>;

class Gui
{
public:
	explicit Gui(Event&, SDL_Renderer&);

	Menu& menu();

private:
	Menu m_menu;
};


#endif //SRC_GUI_H
