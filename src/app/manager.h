//
// Created by Sebastian on 10.08.26.
//

#ifndef SRC_APP_MANAGER_H
#define SRC_APP_MANAGER_H

#include <contracts/app/view.h>

#include <boost/signals2.hpp>
#include <vector>

using ChangeViewSignal = boost::signals2::signal<void(View::eView)>;

class Manager
{
public:
	Manager(std::vector<View*>);
	void render();

private:
	View* getView(View::eView);

	void onViewChanged(View::eView);

	std::vector<View*> m_views;
	View* m_activeView{nullptr};
};


#endif //SRC_APP_MANAGER_H
