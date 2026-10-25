//
// Created by Sebastian on 25.10.26.
//

#include <gui/game.h>

namespace gui
{
Game::Game(SDL_Renderer& renderer, KeyEvent& keyEvent, GameController& gameController) : m_renderer{renderer}, m_keyEvent{keyEvent}, m_gameController{gameController}
{
}

void Game::render()
{}

void Game::entry()
{

}

void Game::exit()
{

}

common::eView Game::type() const
{
	return common::eView::Game;
}

app::ChangeViewSignal& Game::change()
{
	return m_change;
}
}
