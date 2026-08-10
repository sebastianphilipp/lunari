//
// Created by Sebastian on 10.08.26.
//

#include "manager.h"

Manager::Manager(ChangeViewSignal &change, std::vector<View *> &views) : m_views{views}
{
	m_activeView = getView(View::eView::Main);
	m_activeView->entry();

	change.connect(
			boost::bind(
					&Manager::onViewChanged,
					this,
					boost::placeholders::_1
			)
	);
}

View *Manager::getView(View::eView type)
{
	auto it = std::find_if(m_views.begin(), m_views.end(), [type](View *view)
	{ return view->type() == type; });
	return it != m_views.end() ? *it : nullptr;
}

void Manager::onViewChanged(View::eView type)
{
	auto view = getView(type);
	if (!view)
		return;

	m_activeView->exit();
	m_activeView = view;
	m_activeView->entry();
}
