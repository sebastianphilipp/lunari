//
// Created by Sebastian on 25.10.26.
//

#include <controller.h>

namespace controller
{
Controller::Controller(state::State& state) : m_state{state}
{
}

GameController& Controller::gameController()
{
	return m_gameController;
}
}
