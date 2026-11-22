//
// Created by Sebastian on 04.11.26.
//

#ifndef SRC_CONTRACTS_GUI_TEXTUREHANDLER_H
#define SRC_CONTRACTS_GUI_TEXTUREHANDLER_H

#include <common/map.h>

#include <array>

namespace gui
{
class TextureHandler
{
public:
	[[nodiscard]] virtual const std::array<std::array<uint8_t, common::kBlockTextureWidth>, common::kBlockTextureHeight>& mapObject(const common::eMapObject) const = 0;
};
}

#endif //SRC_CONTRACTS_GUI_TEXTUREHANDLER_H
