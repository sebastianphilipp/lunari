//
// Created by Sebastian on 15.08.26.
//

#ifndef SRC_GUI_MENU_H
#define SRC_GUI_MENU_H

#include <contracts/app/view.h>

#include <SDL3/SDL.h>

using ChangeViewSignal = boost::signals2::signal<void(View::eView)>;

class Menu : public View
{
public:
	explicit Menu(SDL_Renderer&, ChangeViewSignal&);

	void render() override;
	void entry() override;
	void exit() override;
	eView type() const override;

private:
	SDL_Renderer& m_renderer;
	ChangeViewSignal& m_signal;
};


#endif //SRC_GUI_MENU_H
