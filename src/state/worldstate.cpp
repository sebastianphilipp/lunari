//
// Created by Sebastian on 25.10.26.
//

#include <state/worldstate.h>

namespace state
{
const WorldMap& WorldState::map() const
{
	return m_worldMap;
}
}

