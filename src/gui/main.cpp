//
// Created by Sebastian on 15.08.26.
//

#include <gui/main.h>

namespace gui
{
Main::Main(SDL_Renderer& renderer, TTF_TextEngine& textEngine, TTF_Font& font, KeyEvent& keyEvent) : m_renderer{
		renderer}, m_textEngine{textEngine}, m_font{font}, m_keyEvent{keyEvent}
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

	int width{};
	int height{};

	SDL_GetRenderOutputSize(&m_renderer, &width, &height);

	for (size_t i = 0; i < m_labels.size(); ++i)
	{
		int labelWidth{0U};
		int labelHeight{0U};
		TTF_GetTextSize(m_labels.at(i).ttfText, &labelWidth, &labelHeight);

		TTF_DrawRendererText(m_labels.at(i).ttfText, (width / 2.0F) - (labelWidth / 2.0F), (height / 2.0F) + (i * kGap) - ((labelHeight * m_labels.size()) / 2));
	}

	SDL_SetRenderDrawColor(&m_renderer, 192, 29, 29, 255);

	int labelWidth{0U};
	int labelHeight{0U};
	TTF_GetTextSize(m_labels.at(m_index).ttfText, &labelWidth, &labelHeight);

	const size_t x1 = (width / 2.0F) - (labelWidth / 2.0F);
	const size_t y1 = (height / 2.0F) + (m_index * kGap) - ((labelHeight * m_labels.size()) / 2U) + labelHeight;
	const size_t x2 = x1 + labelWidth;
	const size_t y2 = y1;

	SDL_RenderLine(&m_renderer, x1, y1, x2, y2);

	SDL_RenderPresent(&m_renderer);
}

void Main::entry()
{
	m_keyConnection = m_keyEvent.key().connect(boost::bind(&Main::onKeyDown, this, boost::placeholders::_1));
}

void Main::exit()
{
	m_keyConnection.disconnect();
}

common::eView Main::type() const
{
	return common::eView::Main;
}

app::ChangeViewSignal& Main::change()
{
	return m_change;
}

void Main::onKeyDown(SDL_Keycode key)
{
	if (key == SDLK_DOWN)
	{
		if (m_index < m_labels.size() - 1)
		{
			m_index++;
		}
	} else if (key == SDLK_UP)
	{
		if (m_index > 0)
		{
			m_index--;
		}
	} else if (key == SDLK_RETURN)
	{
		const std::string item{m_labels.at(m_index).text};
		if (item == kSettings)
		{
			m_change(common::eView::GeneralSettings);
		}
	}
}
}
