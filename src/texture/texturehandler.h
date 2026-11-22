//
// Created by Sebastian on 25.10.26.
//

#ifndef SRC_TEXTURE_TEXTUREHANDLER_H
#define SRC_TEXTURE_TEXTUREHANDLER_H

#include <contracts/gui/texturehandler.h>

namespace texture
{
class TextureHandler : public gui::TextureHandler
{
public:
	const std::array<std::array<uint8_t, common::kBlockTextureWidth>, common::kBlockTextureHeight>& mapObject(const common::eMapObject) const override;
};
}

#endif //SRC_TEXTURE_TEXTUREHANDLER_H
