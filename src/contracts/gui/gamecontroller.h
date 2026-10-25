//
// Created by Sebastian on 25.10.26.
//

#ifndef SRC_CONTRACTS_GUI_GAMECONTROLLER_H
#define SRC_CONTRACTS_GUI_GAMECONTROLLER_H

#include <SDL3/SDL.h>

namespace gui
{
class GameController
{
public:
	virtual void processKey(SDL_Keycode) = 0;
};
}

#endif //SRC_CONTRACTS_GUI_GAMECONTROLLER_H
