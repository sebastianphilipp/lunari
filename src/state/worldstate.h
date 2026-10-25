//
// Created by Sebastian on 25.10.26.
//

#ifndef SRC_STATE_WORLDSTATE_H
#define SRC_STATE_WORLDSTATE_H

#include <contracts/controller/worldstate.h>

namespace state
{
class WorldState : public controller::WorldState
{
public:
	const WorldMap& map() const override;
private:
	WorldMap m_worldMap{};
};
}

#endif //SRC_STATE_WORLDSTATE_H
