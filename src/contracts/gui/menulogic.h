//
// Created by Sebastian on 10.08.26.
//

#ifndef SRC_CONTRACTS_GUI_MENULOGIC_H
#define SRC_CONTRACTS_GUI_MENULOGIC_H

#include <boost/signals2.hpp>
#include <SDL3/SDL.h>
#include <string>
#include <common/view.h>

namespace gui
{
using ChangeViewSignal = boost::signals2::signal<void(common::eView)>;

class MenuLogic
{
public:
	virtual ~MenuLogic() = default;

	virtual std::string label(size_t) const = 0;
	virtual std::string value(size_t) const = 0;
	virtual ChangeViewSignal& change() = 0;
	virtual size_t settingsCount() const = 0;
	virtual void handleKey(size_t, SDL_Keycode) = 0;
};
}

#endif //SRC_CONTRACTS_GUI_MENULOGIC_H
