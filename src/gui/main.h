//
// Created by Sebastian on 12.09.26.
//

#ifndef SRC_GUI_MAIN_H
#define SRC_GUI_MAIN_H

#include <contracts/app/view.h>
#include <contracts/gui/keyevent.h>

using ChangeViewSignal = boost::signals2::signal<void(common::eView)>;

class Main : public View
{
public:
	Main(SDL_Renderer&, KeyEvent&);
	~Main() override;

	void render() override;
	void entry() override;
	void exit() override;
	[[nodiscard]] common::eView type() const override;
	ChangeViewSignal& change() override;

private:
	SDL_Renderer& m_renderer;
	KeyEvent& m_keyEvent;

	void onKeyDown(SDL_Keycode key);

	ChangeViewSignal m_change{};
};


#endif //SRC_GUI_MAIN_H
