//
// Created by Sebastian on 15.08.26.
//

#include <gui/menu.h>

namespace gui
{
Menu::Menu(SDL_Renderer& renderer, TTF_TextEngine& textEngine, TTF_Font& font, common::eView view, KeyEvent& keyEvent,
		   MenuLogic& menuLogic) : m_renderer{
		renderer}, m_textEngine{textEngine}, m_font{font}, m_view{view}, m_keyEvent{keyEvent}, m_menuLogic{menuLogic}
{
	const size_t settingsCount{m_menuLogic.settingsCount()};
	m_labels.reserve(settingsCount);

	for (size_t i = 0; i < m_menuLogic.settingsCount(); ++i)
	{
		const std::string label{m_menuLogic.label(i)};
		m_labels.push_back({label, TTF_CreateText(&m_textEngine, &m_font, label.c_str(), 0)});
	}

	m_menuLogic.change().connect([this](common::eView view)
								 {
									 m_change(view);
								 });
}

Menu::~Menu()
{
	for (const Label& label: m_labels)
	{
		if (label.ttfText)
		{
			TTF_DestroyText(label.ttfText);
		}
	}

	if (m_value.ttfText)
	{
		TTF_DestroyText(m_value.ttfText);
	}
}

void Menu::render()
{
	SDL_SetRenderDrawColor(&m_renderer, 20, 24, 38, 255);
	SDL_RenderClear(&m_renderer);

	for (size_t i = 0; i < m_labels.size(); ++i)
	{
		const float y = 100.0f + (30.0f * static_cast<float>(i));

		if (m_labels.at(i).ttfText)
		{
			TTF_DrawRendererText(m_labels.at(i).ttfText, 100.0f, y);
		}

		if (!(m_selectedItem == i))
		{
			continue;
		}

		const std::string value{m_menuLogic.value(i)};
		if (m_value.text != value)
		{
			if (m_value.ttfText)
			{
				TTF_DestroyText(m_value.ttfText);
			}

			m_value.text = value;
			m_value.ttfText = TTF_CreateText(&m_textEngine, &m_font, value.c_str(), 0);
		}

		int labelWidth{};
		int labelHeight{};
		if (m_labels.at(i).ttfText)
		{
			TTF_GetTextSize(m_labels.at(i).ttfText, &labelWidth, &labelHeight);
		}
		if (m_value.ttfText)
		{
			TTF_DrawRendererText(m_value.ttfText, 100.0f + static_cast<float>(labelWidth) + 30.0f, y);
		}
	}

	SDL_SetRenderDrawColor(&m_renderer, 255, 210, 40, 255);

	SDL_FRect pixel{
			.x = 70.0f,
			.y = 110.0f + (30.0f * static_cast<float>(m_selectedItem)),
			.w = 10.0f,
			.h = 10.0f
	};

	SDL_RenderFillRect(&m_renderer, &pixel);

	SDL_RenderPresent(&m_renderer);
}

void Menu::entry()
{
	m_keyConnection = m_keyEvent.key().connect(boost::bind(&Menu::onKeyDown, this, boost::placeholders::_1));
}

void Menu::exit()
{
	m_keyConnection.disconnect();

	m_selectedItem = 0U;
}

common::eView Menu::type() const
{
	return m_view;
}

app::ChangeViewSignal& Menu::change()
{
	return m_change;
}

void Menu::onKeyDown(SDL_Keycode key)
{
	if (m_labels.empty())
	{
		return;
	}

	if (key == SDLK_UP)
	{
		if (m_selectedItem > 0)
		{
			m_selectedItem--;
			return;
		}
	} else if (key == SDLK_DOWN)
	{
		if (m_selectedItem < (m_labels.size() - 1))
		{
			m_selectedItem++;
			return;
		}
	}

	m_menuLogic.handleKey(m_selectedItem, key);
}
}
