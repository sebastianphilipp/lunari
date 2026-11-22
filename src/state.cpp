//
// Created by Sebastian on 25.10.26.
//

#include <state.h>

namespace state
{
WorldState& State::worldState()
{
	return m_worldState;
}

PlayerState& State::playerState()
{
	return m_playerState;
}
}
