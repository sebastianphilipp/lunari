//
// Created by Sebastian on 15.08.26.
//

#ifndef SRC_APP_H
#define SRC_APP_H

#include <boost/signals2.hpp>
#include <contracts/app/view.h>
#include <app/manager.h>

#include <gui.h>

class App
{
public:
	explicit App(Gui&);

	Manager& manager();
private:
	Manager m_manager;
};


#endif //SRC_APP_H
