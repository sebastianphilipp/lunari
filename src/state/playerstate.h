//
// Created by Sebastian on 25.10.26.
//

#ifndef SRC_STATE_PLAYERSTATE_H
#define SRC_STATE_PLAYERSTATE_H

#include <contracts/gui/playerstate.h>

namespace state
{
class PlayerState : public gui::PlayerState
{
public:
	const common::Player& player() const override;

private:
	common::Player m_player{};
};
}

#endif //SRC_STATE_PLAYERSTATE_H
