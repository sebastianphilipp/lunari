//
// Created by Sebastian on 09.08.26.
//

#include <boost/bind/bind.hpp>
#include <iostream>

#include "key.h"

Key::Key(KeySignal& keySignal) {
    keySignal.connect(
            boost::bind(
                    &Key::onKeyDown,
                    this,
                    boost::placeholders::_1
            )
    );
}

void Key::onKeyDown(SDL_Keycode key) {
    std::cout << key << std::endl;
}