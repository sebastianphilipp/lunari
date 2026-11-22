//
// Created by Sebastian on 04.11.26.
//

#ifndef SRC_CONTRACTS_GUI_TEXTUREHANDLER_H
#define SRC_CONTRACTS_GUI_TEXTUREHANDLER_H

#include <common/map.h>
#include <common/rgb.h>

#include <vector>

namespace gui
{
class TextureHandler
{
public:
	[[nodiscard]] virtual const std::vector<std::vector<sRgb>> block(const common::eBlock) const = 0;
};
}

#endif //SRC_CONTRACTS_GUI_TEXTUREHANDLER_H
