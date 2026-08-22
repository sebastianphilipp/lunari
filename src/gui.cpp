//
// Created by Sebastian on 15.08.26.
//

#include "gui.h"

Gui::Gui(Event& event, SDL_Renderer& renderer) : m_menu{event.key(), renderer}
{}

Menu& Gui::menu()
{
	return m_menu;
}
