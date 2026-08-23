//
// Created by Sebastian on 15.08.26.
//

#ifndef SRC_GUI_MENU_H
#define SRC_GUI_MENU_H

#include <contracts/app/view.h>
#include <contracts/gui/keyevent.h>

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <array>
#include <string>

using ChangeViewSignal = boost::signals2::signal<void(View::eView)>;

class Menu : public View
{
public:
	Menu(SDL_Renderer&, TTF_TextEngine&, TTF_Font&, KeyEvent&);

	void render() override;
	void entry() override;
	void exit() override;
	eView type() const override;
	ChangeViewSignal& change() override;

private:
	struct MenuItem
	{
		std::string text{};
		TTF_Text* ttf_text{nullptr};
	};

	void onKeyDown(SDL_Keycode key);

	SDL_Renderer& m_renderer;
	TTF_TextEngine& m_textEngine;
	TTF_Font& m_font;
	KeyEvent& m_keyEvent;

	ChangeViewSignal m_change{};
	std::array<MenuItem, 3> m_menuItems{{{"Start"}, {"Settings"}, {"Exit"}}};
	size_t m_menuItem{0};
};


#endif //SRC_GUI_MENU_H
