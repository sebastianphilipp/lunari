//
// Created by Sebastian on 09.08.26.
//

#ifndef SRC_EVENT_H
#define SRC_EVENT_H

#include <boost/signals2.hpp>
#include <SDL3/SDL.h>

#include "event/key.h"

using KeySignal = boost::signals2::signal<void(SDL_Keycode)>;

class Event
{
public:
	explicit Event(KeySignal &keySignal);

private:
	Key m_key;
};


#endif //SRC_EVENT_H
