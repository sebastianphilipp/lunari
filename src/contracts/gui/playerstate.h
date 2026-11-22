//
// Created by Sebastian on 25.10.26.
//

#ifndef SRC_CONTRACTS_GUI_PLAYERSTATE_H
#define SRC_CONTRACTS_GUI_PLAYERSTATE_H

#include <common/player.h>

#include <vector>

namespace gui
{
class PlayerState
{
public:
	[[nodiscard]] virtual const common::Player& player() const = 0;
};
}

#endif //SRC_CONTRACTS_GUI_PLAYERSTATE_H
