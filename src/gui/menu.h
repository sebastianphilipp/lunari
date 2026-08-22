//
// Created by Sebastian on 15.08.26.
//

#ifndef SRC_GUI_MENU_H
#define SRC_GUI_MENU_H

#include <contracts/app/view.h>

#include <SDL3/SDL.h>

#include <contracts/gui/keyevent.h>

using ChangeViewSignal = boost::signals2::signal<void(View::eView)>;

class Menu : public View
{
public:
	Menu(KeyEvent&, SDL_Renderer&);

	void render() override;
	void entry() override;
	void exit() override;
	eView type() const override;
	ChangeViewSignal& change() override;

private:
	void onKeyDown(SDL_Keycode key);

	ChangeViewSignal m_change{};

	SDL_Renderer& m_renderer;
};


#endif //SRC_GUI_MENU_H
