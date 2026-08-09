//
// Created by Sebastian on 09.08.26.
//

#ifndef SRC_EVENT_KEY_H
#define SRC_EVENT_KEY_H

#include <boost/signals2.hpp>
#include <SDL3/SDL.h>

using KeySignal = boost::signals2::signal<void(SDL_Keycode)>;

class Key {
public:
    explicit Key(KeySignal& keySignal);
private:
    void onKeyDown(SDL_Keycode key);
};


#endif //SRC_EVENT_KEY_H
