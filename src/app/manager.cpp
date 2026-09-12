//
// Created by Sebastian on 10.08.26.
//

#include "manager.h"

#include <utility>

Manager::Manager(std::vector<View*> views) : m_views{std::move(views)}
{
	m_activeView = getView(common::eView::Main);
	m_activeView->entry();

	for (View* view : m_views)
	{
		if (!view)
		{
			continue;
		}
		view->change().connect(boost::bind(&Manager::onViewChanged, this, boost::placeholders::_1));
	}
}

View* Manager::getView(common::eView type)
{
	auto it = std::find_if(m_views.begin(), m_views.end(), [type](View* view)
	{ return view->type() == type; });
	return it != m_views.end() ? *it : nullptr;
}

void Manager::onViewChanged(common::eView type)
{
	auto view = getView(type);
	if (!view)
		return;

	m_activeView->exit();
	m_activeView = view;
	m_activeView->entry();
}

void Manager::render()
{
	if (!m_activeView)
		return;
	m_activeView->render();
}
