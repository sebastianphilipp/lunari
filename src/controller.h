//
// Created by Sebastian on 25.10.26.
//

#ifndef SRC_CONTROLLER_H
#define SRC_CONTROLLER_H

#include <controller/gamecontroller.h>

#include <state.h>

namespace controller
{
class Controller
{
public:
	Controller(state::State&);

	GameController& gameController();

private:
	state::State& m_state;

	GameController m_gameController;
};
}

#endif //SRC_CONTROLLER_H
