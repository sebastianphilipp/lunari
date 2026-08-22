//
// Created by Sebastian on 09.08.26.
//

#include "event.h"

Event::Event(KeySignal& keySignal) : m_key{keySignal}
{}

Key& Event::key()
{
	return m_key;
}
