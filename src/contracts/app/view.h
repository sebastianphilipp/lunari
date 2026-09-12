//
// Created by Sebastian on 10.08.26.
//

#ifndef SRC_CONTRACTS_APP_VIEW_H
#define SRC_CONTRACTS_APP_VIEW_H

#include <boost/signals2.hpp>
#include <common/view.h>

class View
{
public:

	virtual ~View() = default;

	virtual void render() = 0;
	virtual void entry() = 0;
	virtual void exit() = 0;
	[[nodiscard]] virtual common::eView type() const = 0;
	virtual boost::signals2::signal<void(common::eView)>& change() = 0;
};

#endif //SRC_CONTRACTS_APP_VIEW_H
