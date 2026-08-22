//
// Created by Sebastian on 15.08.26.
//

#include <gui/menu.h>

Menu::Menu(KeyEvent& keyEvent, SDL_Renderer& renderer) : m_renderer{renderer}
{
	keyEvent.key().connect(boost::bind(&Menu::onKeyDown, this, boost::placeholders::_1));
}

void Menu::render()
{

}

void Menu::entry()
{
}

void Menu::exit()
{
}

View::eView Menu::type() const
{
	return View::eView::Main;
}

ChangeViewSignal& Menu::change()
{
	return m_change;
}

void Menu::onKeyDown(SDL_Keycode key)
{
	/* TODO(sp): Example, delete  later */
	if (key == SDLK_P)
	{
		SDL_SetRenderDrawColor(&m_renderer, 0, 0, 0, 255);
		SDL_RenderClear(&m_renderer);

		SDL_SetRenderDrawColor(&m_renderer, 255, 255, 0, 255);
		SDL_RenderPoint(&m_renderer, 400.0f, 300.0f);
		SDL_RenderPoint(&m_renderer, 400.0f, 350.0f);

		SDL_RenderPresent(&m_renderer);
	}
	else
	{
		SDL_SetRenderDrawColor(&m_renderer, 0, 0, 0, 255);
		SDL_RenderClear(&m_renderer);

		SDL_SetRenderDrawColor(&m_renderer, 255, 255, 0, 255);
		SDL_RenderPoint(&m_renderer, 100.0f, 200.0f);
		SDL_RenderPoint(&m_renderer, 300.0f, 550.0f);

		SDL_RenderPresent(&m_renderer);
	}
}
