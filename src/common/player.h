//
// Created by Sebastian on 25.10.26.
//

#ifndef SRC_COMMON_PLAYER_H
#define SRC_COMMON_PLAYER_H

#include <string>

namespace common
{
struct Player
{
	std::string name;
	size_t posX;
	size_t posY;
	size_t health;
};
}

#endif //SRC_COMMON_PLAYER_H
