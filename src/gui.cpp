//
// Created by Sebastian on 15.08.26.
//

#include "gui.h"

namespace gui
{
Gui::Gui(SDL_Renderer& renderer, TTF_TextEngine& textEngine, TTF_Font& font, event::Event& event,
		 menu::Menu& menu) : m_main{renderer, textEngine, font, event.key()},
							 m_menu{renderer, textEngine, font, common::eView::GeneralSettings, event.key(),
									menu.general()}
{}

Main& Gui::main()
{
	return m_main;
}

Menu& Gui::menu()
{
	return m_menu;
}
}
