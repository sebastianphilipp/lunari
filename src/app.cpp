//
// Created by Sebastian on 15.08.26.
//

#include "app.h"

namespace app
{
App::App(gui::Gui& gui) : m_manager{std::vector<View*>{&gui.main(), &gui.menu()}}
{}

Manager& App::manager()
{
	return m_manager;
}
}
