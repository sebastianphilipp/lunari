//
// Created by Sebastian on 15.08.26.
//

#include "gui.h"

Gui::Gui(SDL_Renderer& renderer, TTF_TextEngine& textEngine, TTF_Font& font, Event& event) : m_menu{renderer,
		textEngine, font, common::eView::Main, event.key(), m_startMenuLogic}
{}

Menu& Gui::menu()
{
	return m_menu;
}
