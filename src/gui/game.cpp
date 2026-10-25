//
// Created by Sebastian on 25.10.26.
//

#include <gui/game.h>

namespace gui
{
Game::Game(SDL_Renderer& renderer, KeyEvent& keyEvent, GameController& gameController, WorldState& worldState) : m_renderer{renderer}, m_keyEvent{keyEvent}, m_gameController{gameController},
																												 m_worldState{worldState}
{
}

void Game::render()
{
	/* render everything */
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
}
