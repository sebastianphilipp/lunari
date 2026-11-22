//
// Created by Sebastian on 06.11.26.
//

#include <file/texturefile.h>

#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

namespace file
{
const std::vector<std::vector<common::sRgb>> TextureFile::read(const std::string& path) const
{
	std::ifstream file(path);
	if (!file)
	{
		return {};
	}

	std::string line{};
	std::vector<std::vector<common::sRgb>> entries{};
	while (std::getline(file, line))
	{
		entries.emplace_back();
		splitChunks(entries.back(), line);
	}

	return entries;
}

void TextureFile::splitChunks(std::vector<common::sRgb>& entries, const std::string& line)
{
	std::istringstream stream(line);
	std::string chunk;

	while (stream >> chunk)
	{
		convertToRgb(entries, chunk);
	}
}

void TextureFile::convertToRgb(std::vector<common::sRgb>& entries, std::string chunk)
{
	std::replace(chunk.begin(), chunk.end(), kDelimiter, kSpace);
	std::istringstream stream(chunk);

	int r, g, b;
	stream >> r >> g >> b;

	entries.push_back(common::sRgb{static_cast<uint8_t>(r), static_cast<uint8_t>(g), static_cast<uint8_t>(b)});
}
}
