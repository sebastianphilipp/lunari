//
// Created by Sebastian on 15.08.26.
//

#ifndef SRC_GUI_MENU_H
#define SRC_GUI_MENU_H

#include <contracts/app/view.h>

using ChangeViewSignal = boost::signals2::signal<void(View::eView)>;

class Menu : public View
{
public:
	explicit Menu(ChangeViewSignal&);

	void render() override;
	void entry() override;
	void exit() override;
	eView type() const override;

private:
	ChangeViewSignal& m_change;
};


#endif //SRC_GUI_MENU_H
