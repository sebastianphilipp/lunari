//
// Created by Sebastian on 25.10.26.
//

#include <state/playerstate.h>

namespace state
{
const common::Player& PlayerState::player() const
{
	return m_player;
}
}
