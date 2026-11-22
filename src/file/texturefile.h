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
	[[nodiscard]] const std::vector<std::vector<common::sRgb>> read(const std::string&) const override;

private:
	static constexpr char kDelimiter{','};
	static constexpr char kSpace{' '};

	static void splitChunks(std::vector<common::sRgb>& entries, const std::string& line);
	static void convertToRgb(std::vector<common::sRgb>& entries, std::string chunk);
};
}

#endif //SRC_FILE_TEXTUREFILE_H
