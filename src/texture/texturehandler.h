//
// Created by Sebastian on 25.10.26.
//

#ifndef SRC_TEXTURE_TEXTUREHANDLER_H
#define SRC_TEXTURE_TEXTUREHANDLER_H

#include <contracts/gui/texturehandler.h>
#include <contracts/texture/texturefile.h>

#include <unordered_map>

namespace texture
{
class TextureHandler : public gui::TextureHandler
{
public:
	TextureHandler(TextureFile&);
	const std::vector<std::vector<common::sRgb>> block(const common::eBlock) const override;

private:
	const std::unordered_map<common::eBlock, std::string> blockTextures{
			{common::eBlock::Wall,  "assets/stone_80x80_rgb.txt"},
			{common::eBlock::Chest, "assets/chest_80x80_rgb.txt"}
	};

	TextureFile& m_textureFile;
};
}

#endif //SRC_TEXTURE_TEXTUREHANDLER_H
