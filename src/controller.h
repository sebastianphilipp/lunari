//
// Created by Sebastian on 25.10.26.
//

#ifndef SRC_CONTROLLER_H
#define SRC_CONTROLLER_H

#include <controller/gamecontroller.h>

namespace controller
{
class Controller
{
public:
	/* todo */
	Controller() = default;

	GameController& gameController();

private:
	GameController m_gameController;
};
}

#endif //SRC_CONTROLLER_H
