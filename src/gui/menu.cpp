//
// Created by Sebastian on 15.08.26.
//

#include "menu.h"

Menu::Menu(ChangeViewSignal& change) : m_change{change}
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
