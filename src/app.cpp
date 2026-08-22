//
// Created by Sebastian on 15.08.26.
//

#include "app.h"

App::App(Gui& gui) : m_manager{gui.signal(), std::vector<View*>{&gui.menu()}}
{}
