//
// Created by Sebastian on 15.08.26.
//

#ifndef SRC_GUI_H
#define SRC_GUI_H

#include <contracts/app/view.h>

#include <boost/signals2.hpp>
#include <SDL3/SDL.h>

#include <gui/menu.h>

using ChangeViewSignal = boost::signals2::signal<void(View::eView)>;

class Gui
{
public:
	explicit Gui(SDL_Renderer&);

	ChangeViewSignal& signal();
	Menu& menu();
private:
	ChangeViewSignal m_signal{};

	Menu m_menu;
};


#endif //SRC_GUI_H
