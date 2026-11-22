//
// Created by Sebastian on 25.10.26.
//

#ifndef SRC_CONTRACTS_CONTROLLER_WORLDSTATE_H
#define SRC_CONTRACTS_CONTROLLER_WORLDSTATE_H

#include <common/map.h>

#include <vector>

using WorldMap = std::vector<std::vector<common::eMapObject>>;

namespace controller
{
class WorldState
{
public:
	virtual const WorldMap& map() const = 0;
};
}

#endif //SRC_CONTRACTS_CONTROLLER_WORLDSTATE_H
