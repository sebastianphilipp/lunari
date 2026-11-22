//
// Created by Sebastian on 06.11.26.
//

#ifndef SRC_FILE_TEXTUREFILE_H
#define SRC_FILE_TEXTUREFILE_H

#include <contracts/texture/texturefile.h>

namespace file
{
class TextureFile : public texture::TextureFile
{
public:
	const std::vector<std::vector<uint8_t>>& read(const std::string) const override;
};
}

#endif //SRC_FILE_TEXTUREFILE_H
