//
// Created by Sebastian on 15.08.26.
//

#ifndef SRC_GUI_MENU_H
#define SRC_GUI_MENU_H

#include <contracts/app/view.h>
#include <contracts/gui/keyevent.h>
#include <contracts/gui/menulogic.h>
#include <common/view.h>

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <vector>
#include <string>

using ChangeViewSignal = boost::signals2::signal<void(common::eView)>;

class Menu : public View
{
public:
	Menu(SDL_Renderer&, TTF_TextEngine&, TTF_Font&, common::eView, KeyEvent&, MenuLogic&);
	~Menu() override;

	void render() override;
	void entry() override;
	void exit() override;
	[[nodiscard]] common::eView type() const override;
	ChangeViewSignal& change() override;

private:
	struct SelectedValue
	{
		std::string text{};
		TTF_Text* ttfText{nullptr};
	};

	struct Label
	{
		std::string text{};
		TTF_Text* ttfText{nullptr};
	};

	void onKeyDown(SDL_Keycode key);

	SDL_Renderer& m_renderer;
	TTF_TextEngine& m_textEngine;
	TTF_Font& m_font;
	common::eView m_view{common::eView::None};
	KeyEvent& m_keyEvent;
	MenuLogic& m_menuLogic;

	ChangeViewSignal m_change{};
	boost::signals2::scoped_connection m_keyConnection{};
	std::vector<Label> m_labels{};
	SelectedValue m_value{};
	size_t m_selectedItem{0};
};


#endif //SRC_GUI_MENU_H
