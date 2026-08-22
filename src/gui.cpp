//
// Created by Sebastian on 15.08.26.
//

#include "gui.h"

Gui::Gui() : m_menu{m_signal}
{}

ChangeViewSignal& Gui::signal()
{
	return m_signal;
}

Menu& Gui::menu()
{
	return m_menu;
}
