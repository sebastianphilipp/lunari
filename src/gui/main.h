//
// Created by Sebastian on 12.09.26.
//

#ifndef SRC_GUI_MAIN_H
#define SRC_GUI_MAIN_H

#include <contracts/app/view.h>
#include <contracts/gui/keyevent.h>

#include <SDL3_ttf/SDL_ttf.h>
#include <array>

namespace gui
{
class Main : public app::View
{
public:
	Main(SDL_Renderer&, TTF_TextEngine&, TTF_Font&, KeyEvent&);
	~Main() override;

	void render() override;
	void entry() override;
	void exit() override;
	[[nodiscard]] common::eView type() const override;
	app::ChangeViewSignal& change() override;

private:
	static constexpr std::string_view kStartGame{"Start Game"};
	static constexpr std::string_view kSettings{"Settings"};
	static constexpr std::string_view kExit{"Exit"};
	static constexpr size_t kGap{40U};

	SDL_Renderer& m_renderer;
	TTF_TextEngine& m_textEngine;
	TTF_Font& m_font;
	KeyEvent& m_keyEvent;

	void onKeyDown(SDL_Keycode key);

	boost::signals2::scoped_connection m_keyConnection{};
	app::ChangeViewSignal m_change{};

	std::array<Label, 3> m_labels{{{std::string{kStartGame}, TTF_CreateText(&m_textEngine, &m_font, kStartGame.data(), 0)},
										  {std::string{kSettings}, TTF_CreateText(&m_textEngine, &m_font, kSettings.data(), 0)},
										  {std::string{kExit}, TTF_CreateText(&m_textEngine, &m_font, kExit.data(), 0)}}};
	size_t m_index{0U};
};
}


#endif //SRC_GUI_MAIN_H
