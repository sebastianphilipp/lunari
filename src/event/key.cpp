//
// Created by Sebastian on 09.08.26.
//

#include <boost/bind/bind.hpp>
#include <iostream>

#include <event/key.h>

namespace event
{
Key::Key(KeySignal& keySignal)
{
    keySignal.connect(boost::bind(&Key::onKeyDown, this, boost::placeholders::_1));
}

KeySignal& Key::key()
{
	return m_key;
}

void Key::onKeyDown(SDL_Keycode key)
{
	    m_key(key);
}
}
