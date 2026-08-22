//
// Created by Sebastian on 10.08.26.
//

#ifndef SRC_CONTRACTS_GUI_KEYEVENT_H
#define SRC_CONTRACTS_GUI_KEYEVENT_H

#include <boost/signals2.hpp>

using KeySignal = boost::signals2::signal<void(SDL_Keycode)>;

class KeyEvent
{
public:
	virtual ~KeyEvent() = default;

	virtual KeySignal& key() = 0;
};

#endif //SRC_CONTRACTS_GUI_KEYEVENT_H
