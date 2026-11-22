//
// Created by Sebastian on 04.11.26.
//

#include <texture/texturehandler.h>

namespace texture
{
TextureHandler::TextureHandler(texture::TextureFile& textureFile)
		: m_textureFile{textureFile}
{}

const std::vector<std::vector<common::sRgb>> TextureHandler::block(const common::eBlock block) const
{
	return m_textureFile.read(blockTextures.at(block));
}
}
