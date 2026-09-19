//
// Created by Sebastian on 09.08.26.
//

#ifndef SRC_EVENT_KEY_H
#define SRC_EVENT_KEY_H

#include <boost/signals2.hpp>
#include <SDL3/SDL.h>

#include <contracts/gui/keyevent.h>

namespace event
{
using KeySignal = gui::KeySignal;

class Key : public gui::KeyEvent {
public:
	    explicit Key(KeySignal& keySignal);
	gui::KeySignal& key() override;

private:
	gui::KeySignal m_key{};

    void onKeyDown(SDL_Keycode key);
};
}


#endif //SRC_EVENT_KEY_H
