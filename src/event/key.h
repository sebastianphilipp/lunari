//
// Created by Sebastian on 09.08.26.
//

#ifndef SRC_EVENT_KEY_H
#define SRC_EVENT_KEY_H

#include <boost/signals2.hpp>
#include <SDL3/SDL.h>

#include <contracts/gui/keyevent.h>

class Key : public KeyEvent {
public:
    explicit Key(KeySignal& keySignal);
	KeySignal& key() override;

private:
	KeySignal m_key{};

    void onKeyDown(SDL_Keycode key);
};


#endif //SRC_EVENT_KEY_H
