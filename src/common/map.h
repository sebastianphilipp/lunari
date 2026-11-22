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

enum eBlock : uint8_t
{
	Wall = 0,
	Chest
};
}

#endif //SRC_COMMON_MAPOBJECT_H
