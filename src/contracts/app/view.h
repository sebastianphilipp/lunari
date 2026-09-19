//
// Created by Sebastian on 10.08.26.
//

#ifndef SRC_CONTRACTS_APP_VIEW_H
#define SRC_CONTRACTS_APP_VIEW_H

#include <boost/signals2.hpp>
#include <common/view.h>

#include <SDL3_ttf/SDL_ttf.h>

namespace app
{
using ChangeViewSignal = boost::signals2::signal<void(common::eView)>;

class View
{
public:
	/* Fuer die Zuordnung von Text zu TTFText */
	struct Label
	{
		std::string text{};
		TTF_Text* ttfText{nullptr};
	};

	virtual ~View() = default;

	virtual void render() = 0;
	virtual void entry() = 0;
	virtual void exit() = 0;
	[[nodiscard]] virtual common::eView type() const = 0;
	virtual ChangeViewSignal& change() = 0;
};
}

#endif //SRC_CONTRACTS_APP_VIEW_H
