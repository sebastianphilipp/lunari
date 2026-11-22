//
// Created by Sebastian on 25.10.26.
//

#ifndef SRC_COMMON_MAPOBJECT_H
#define SRC_COMMON_MAPOBJECT_H

#include <cstdint>
#include <cstddef>

namespace common
{
static constexpr size_t kBlockTextureHeight{80U};
static constexpr size_t kBlockTextureWidth{80U};

enum eMapObject : uint8_t
{
	Empty = 0,
	Wall,
	Chest
};
}

#endif //SRC_COMMON_MAPOBJECT_H
