//
// Created by Sebastian on 15.08.26.
//

#include <gui/main.h>

Main::Main(SDL_Renderer& renderer, KeyEvent& keyEvent) : m_renderer{renderer}, m_keyEvent{keyEvent}
{
}

Main::~Main()
{

}

void Main::render()
{
	SDL_SetRenderDrawColor(&m_renderer, 20, 24, 38, 255);
	SDL_RenderClear(&m_renderer);

	SDL_SetRenderDrawColor(&m_renderer, 255, 210, 40, 255);

	SDL_FRect pixel{
			.x = 70.0f,
			.y = 110.0f,
			.w = 10.0f,
			.h = 10.0f
	};

	SDL_RenderFillRect(&m_renderer, &pixel);

	SDL_RenderPresent(&m_renderer);
}

void Main::entry()
{

}

void Main::exit()
{

}

common::eView Main::type() const
{
	return common::eView::Main;
}

ChangeViewSignal& Main::change()
{
	return m_change;
}

void Main::onKeyDown(SDL_Keycode key)
{
	if (key == SDLK_RETURN)
	{
		m_change(common::eView::GeneralSettings);
	}
}
