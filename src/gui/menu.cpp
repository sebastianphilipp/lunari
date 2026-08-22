//
// Created by Sebastian on 15.08.26.
//

#include "menu.h"

Menu::Menu(SDL_Renderer& renderer, ChangeViewSignal& signal) : m_renderer{renderer},  m_signal{signal}
{}

void Menu::render()
{
}

void Menu::entry()
{
}

void Menu::exit()
{
}

View::eView Menu::type() const
{
	return View::eView::Main;
}
