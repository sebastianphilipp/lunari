//
// Created by Sebastian on 15.08.26.
//

#include <gui/menu.h>

Menu::Menu(SDL_Renderer& renderer, TTF_TextEngine& textEngine, TTF_Font& font, KeyEvent& keyEvent) : m_renderer{
		renderer}, m_textEngine{textEngine}, m_font{font}, m_keyEvent{keyEvent}
{
	for (MenuItem& menuItem: m_menuItems)
	{
		menuItem.ttf_text = TTF_CreateText(&m_textEngine, &m_font, menuItem.text.c_str(), 0);
	}
}

void Menu::render()
{
	SDL_SetRenderDrawColor(&m_renderer, 20, 24, 38, 255);
	SDL_RenderClear(&m_renderer);

	for (int i = 0; i < m_menuItems.size(); ++i)
	{
		TTF_DrawRendererText(
				m_menuItems[i].ttf_text,
				100.0f,
				100.0f + (30.0f * static_cast<float>(i))
		);
	}

	SDL_SetRenderDrawColor(&m_renderer, 255, 210, 40, 255);

	SDL_FRect pixel{
			.x = 70.0f,
			.y = 110.0f + (30.0f * static_cast<float>(m_menuItem)),
			.w = 10.0f,
			.h = 10.0f
	};

	SDL_RenderFillRect(&m_renderer, &pixel);

	SDL_RenderPresent(&m_renderer);
}

void Menu::entry()
{
	m_keyEvent.key().connect(boost::bind(&Menu::onKeyDown, this, boost::placeholders::_1));
}

void Menu::exit()
{
	m_keyEvent.key().disconnect(boost::bind(&Menu::onKeyDown, this, boost::placeholders::_1));
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
	if (key == SDLK_UP)
	{
		if (m_menuItem > 0)
			m_menuItem--;
	} else if (key == SDLK_DOWN)
	{
		if (m_menuItem < (m_menuItems.size() - 1))
			m_menuItem++;
	}
}
