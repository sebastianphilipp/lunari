//
// Created by Sebastian on 25.10.26.
//

#ifndef SRC_STATE_H
#define SRC_STATE_H

#include <state/worldstate.h>
#include <state/playerstate.h>

namespace state
{
class State
{
public:
	WorldState& worldState();
	PlayerState& playerState();

private:
	WorldState m_worldState;
	PlayerState m_playerState;
};
}

#endif //SRC_STATE_H
