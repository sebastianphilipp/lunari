//
// Created by Sebastian on 09.08.26.
//

#ifndef SRC_EVENT_H
#define SRC_EVENT_H

#include <boost/signals2.hpp>
#include <SDL3/SDL.h>

#include "event/key.h"

namespace event
{
class Event
{
public:
	explicit Event(KeySignal &keySignal);
	Key& key();

private:
	Key m_key;
};
}


#endif //SRC_EVENT_H
