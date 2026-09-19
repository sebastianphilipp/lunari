//
// Created by Sebastian on 12.09.26.
//

#ifndef SRC_MENU_GENERAL_H
#define SRC_MENU_GENERAL_H

#include <contracts/gui/menulogic.h>
#include <common/view.h>
#include <boost/signals2.hpp>

#include <array>

namespace menu
{
class General : public gui::MenuLogic
{
public:
	General();

	std::string label(size_t) const override;
	std::string value(size_t) const override;
	gui::ChangeViewSignal& change() override;
	size_t settingsCount() const override;
	void handleKey(size_t, SDL_Keycode) override;

private:
	static constexpr std::string_view kPlayer{"Player"};
	static constexpr std::string_view kNetwork{"Network"};

	const std::array<std::string_view, 2> m_entries{kPlayer, kNetwork};
	
	gui::ChangeViewSignal m_change{};
};
}


#endif //SRC_MENU_GENERAL_H
