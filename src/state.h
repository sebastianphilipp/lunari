//
// Created by Sebastian on 25.10.26.
//

#ifndef SRC_STATE_H
#define SRC_STATE_H

#include <state/worldstate.h>

namespace state
{
class State
{
public:
	WorldState& worldState();

private:
	WorldState m_worldState;
};
}

#endif //SRC_STATE_H
