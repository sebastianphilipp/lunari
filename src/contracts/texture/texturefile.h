//
// Created by Sebastian on 04.11.26.
//

#ifndef SRC_CONTRACTS_TEXTURE_TEXTUREFILE_H
#define SRC_CONTRACTS_TEXTURE_TEXTUREFILE_H

#include <vector>
#include <string>

namespace texture
{
class TextureFile
{
public:
	[[nodiscard]] virtual const std::vector<std::vector<uint8_t>>& read(const std::string) const = 0;
};
}

#endif //SRC_CONTRACTS_TEXTURE_TEXTUREFILE_H
