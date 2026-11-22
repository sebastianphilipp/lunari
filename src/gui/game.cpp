//
// Created by Sebastian on 25.10.26.
//

#include <gui/game.h>

#include <common/player.h>

#include <algorithm>
#include <cmath>

namespace gui
{
Game::Game(SDL_Renderer& renderer, KeyEvent& keyEvent, GameController& gameController, WorldState& worldState, PlayerState& playerState) : m_renderer{renderer}, m_keyEvent{keyEvent},
																																		   m_gameController{gameController},
																																		   m_worldState{worldState}, m_playerState{playerState}
{
}

void Game::render()
{
	drawMap();
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
	const DisplayResolution displayResolution = displayResoultion(displayResolutionValid);
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
	const common::Player& player = m_playerState.player();

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
			drawMapObject(row.at(startX + i), x, y, scaleFactor);
		}
	}
}

void Game::drawMapObject(common::eMapObject, float x, float y, float scale)
{
	const float blockSize = kReferenceBlockSize * scale;
	const SDL_FRect rect{x, y, blockSize, blockSize};
	/* dummy */
	SDL_SetRenderDrawColor(&m_renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(&m_renderer, &rect);
}

Game::DisplayResolution Game::displayResoultion(bool& valid) const
{
	SDL_Window* window = SDL_GetRenderWindow(&m_renderer);
	SDL_DisplayID display = SDL_GetDisplayForWindow(window);
	const SDL_DisplayMode* mode = SDL_GetCurrentDisplayMode(display);

	valid = true;
	DisplayResolution displayResolution{0U};
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

Game::WindowSize Game::windowSize() const
{
	SDL_Window* window = SDL_GetRenderWindow(&m_renderer);

	int w{};
	int h{};

	SDL_GetWindowSize(window, &w, &h);

	return WindowSize{w, h};
}
}
