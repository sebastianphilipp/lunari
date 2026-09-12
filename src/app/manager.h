//
// Created by Sebastian on 10.08.26.
//

#ifndef SRC_APP_MANAGER_H
#define SRC_APP_MANAGER_H

#include <contracts/app/view.h>

#include <boost/signals2.hpp>
#include <vector>

class Manager
{
public:
	Manager(std::vector<View*>);
	void render();

private:
	View* getView(common::eView);

	void onViewChanged(common::eView);

	std::vector<View*> m_views;
	View* m_activeView{nullptr};
};


#endif //SRC_APP_MANAGER_H
