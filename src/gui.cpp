//
// Created by Sebastian on 15.08.26.
//

#include "gui.h"

Gui::Gui(SDL_Renderer& renderer, TTF_TextEngine& textEngine, TTF_Font& font, Event& event) : m_menu{renderer,
																									textEngine, font,
																									event.key()}
{}

Menu& Gui::menu()
{
	return m_menu;
}
