//
// Created by Sebastian on 10.08.26.
//

#ifndef SRC_CONTRACTS_APP_VIEW_H
#define SRC_CONTRACTS_APP_VIEW_H

#include <boost/signals2.hpp>

class View
{
public:
	enum eView : uint8_t
	{
		Main = 0,
		Game,
		Settings
	};

	virtual ~View() = default;

	virtual void render() = 0;
	virtual void entry() = 0;
	virtual void exit() = 0;
	[[nodiscard]] virtual eView type() const = 0;
	virtual boost::signals2::signal<void(View::eView)>& change() = 0;
};

#endif //SRC_CONTRACTS_APP_VIEW_H
