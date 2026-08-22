//
// Created by Sebastian on 15.08.26.
//

#ifndef SRC_APP_H
#define SRC_APP_H

#include <boost/signals2.hpp>
#include <contracts/app/view.h>
#include <app/manager.h>

#include <gui.h>

using ChangeViewSignal = boost::signals2::signal<void(View::eView)>;

class App
{
public:
	explicit App(Gui&);

	Manager& manager();
private:
	Manager m_manager;
};


#endif //SRC_APP_H
