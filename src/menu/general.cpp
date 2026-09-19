//
// Created by Sebastian on 12.09.26.
//

#include <menu/general.h>

namespace menu
{
General::General() = default;

std::string General::label(size_t index) const
{
	return std::string{m_entries.at(index)};
}

std::string General::value(size_t index) const
{
	//TODO(sp)
	return "";
}

gui::ChangeViewSignal& General::change()
{
	return m_change;
}

size_t General::settingsCount() const
{
	return m_entries.size();
}

void General::handleKey(size_t index, SDL_Keycode keycode)
{
	if (keycode == SDLK_ESCAPE)
	{
		m_change(common::eView::Main);
	}

	if (index >= m_entries.size())
	{
		return;
	}
}
}
