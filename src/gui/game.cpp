//
// Created by Sebastian on 25.10.26.
//

#include <gui/game.h>

#include <common/player.h>
#include <common/map.h>

#include <algorithm>
#include <cmath>

namespace gui
{
Game::Game(SDL_Renderer& renderer, KeyEvent& keyEvent, GameController& gameController, WorldState& worldState, PlayerState& playerState, TextureHandler& textureHandler) : m_renderer{renderer},
																																										   m_keyEvent{keyEvent},
																																										   m_gameController{
																																												   gameController},
																																										   m_worldState{worldState},
																																										   m_playerState{playerState},
																																										   m_textureHandler{
																																												   textureHandler}
{
}

void Game::render()
{
	SDL_RenderClear(&m_renderer);
	drawMap();
	SDL_RenderPresent(&m_renderer)
}

void Game::entry()
{
	m_keyConnection = m_keyEvent.key().connect(boost::bind(&Game::onKeyDown, this, boost::placeholders::_1));
}

void Game::exit()
{
	m_keyConnection.disconnect();

	/* todo clear game state */
}

common::eView Game::type() const
{
	return common::eView::Game;
}

app::ChangeViewSignal& Game::change()
{
	return m_change;
}

void Game::onKeyDown(SDL_Keycode key)
{
	if (key == SDLK_ESCAPE)
	{
		m_change(common::eView::Main);
	}
}

void Game::drawMap()
{
	bool displayResolutionValid = false;
	const sDisplayResolution displayResolution = displayResoultion(displayResolutionValid);
	if (!displayResolutionValid)
	{
		return;
	}

	const float scaleFactor = static_cast<float>(displayResolution.w) / kReferenceWidth;
	const float blockSize = kReferenceBlockSize * scaleFactor;
	if (blockSize <= 0.0F)
	{
		return;
	}

	int renderWidth{};
	int renderHeight{};
	if (!SDL_GetRenderOutputSize(&m_renderer, &renderWidth, &renderHeight) || renderWidth <= 0 || renderHeight <= 0)
	{
		return;
	}

	const size_t blocksPerWidth = static_cast<size_t>(std::ceil(renderWidth / blockSize));
	const size_t blocksPerHeight = static_cast<size_t>(std::ceil(renderHeight / blockSize));

	const WorldMap& worldMap = m_worldState.map();
	if (worldMap.empty())
	{
		return;
	}

	const size_t mapHeight = worldMap.size();
	const size_t mapWidth = std::max_element(worldMap.begin(), worldMap.end(), [](const auto& left, const auto& right)
	{
		return left.size() < right.size();
	})->size();
	const common::sPlayer& player = m_playerState.player();

	const size_t maxStartX = mapWidth > blocksPerWidth ? mapWidth - blocksPerWidth : 0U;
	const size_t maxStartY = mapHeight > blocksPerHeight ? mapHeight - blocksPerHeight : 0U;
	const size_t startX = std::min(player.posX > blocksPerWidth / 2 ? player.posX - blocksPerWidth / 2 : 0U, maxStartX);
	const size_t startY = std::min(player.posY > blocksPerHeight / 2 ? player.posY - blocksPerHeight / 2 : 0U, maxStartY);

	const size_t rows = std::min(blocksPerHeight, mapHeight - startY);
	for (size_t j = 0; j < rows; ++j)
	{
		const auto& row = worldMap.at(startY + j);
		const size_t columns = startX < row.size() ? std::min(blocksPerWidth, row.size() - startX) : 0U;
		for (size_t i = 0; i < columns; ++i)
		{
			const float x = i * blockSize;
			const float y = j * blockSize;
			drawBlock(row.at(startX + i), x, y, scaleFactor);
		}
	}
}

void Game::drawBlock(common::eBlock block, float x, float y, float scale)
{
	if (blockTextures.find(block) == blockTextures.end())
	{
		createBlockTexture(block);
	}

	const float blockSize = kReferenceBlockSize * scale;
	const SDL_FRect rect{x, y, blockSize, blockSize};
	SDL_RenderTexture(&m_renderer, blockTextures.at(block), nullptr, &rect);
}

void Game::createBlockTexture(common::eBlock block)
{
	SDL_Surface* surface = SDL_CreateSurface(common::kBlockTextureWidth, common::kBlockTextureHeight, SDL_PIXELFORMAT_RGBA32);
	if (!surface)
	{
		throw std::runtime_error(SDL_GetError());
	}

	const auto pixels = m_textureHandler.block(block);
	for (int x = 0; x < common::kBlockTextureWidth; ++x)
	{
		for (int y = 0; y < common::kBlockTextureHeight; ++y)
		{
			const common::sRgb& pixel = pixels[y][x];
			SDL_WriteSurfacePixel(surface, x, y, pixel.r, pixel.g, pixel.b, 255);
		}
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(&m_renderer, surface);
	SDL_DestroySurface(surface);

	if (!texture)
	{
		throw std::runtime_error(SDL_GetError());
	}

	SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
	blockTextures.emplace(block, texture);
}

Game::sDisplayResolution Game::displayResoultion(bool& valid) const
{
	SDL_Window* window = SDL_GetRenderWindow(&m_renderer);
	SDL_DisplayID display = SDL_GetDisplayForWindow(window);
	const SDL_DisplayMode* mode = SDL_GetCurrentDisplayMode(display);

	valid = true;
	sDisplayResolution displayResolution{0U};
	if (mode)
	{
		displayResolution.w = mode->w;
		displayResolution.h = mode->h;
	} else
	{
		valid = false;
	}

	return displayResolution;
}

Game::sWindowSize Game::windowSize() const
{
	SDL_Window* window = SDL_GetRenderWindow(&m_renderer);

	int w{};
	int h{};

	SDL_GetWindowSize(window, &w, &h);

	return sWindowSize{w, h};
}
}
