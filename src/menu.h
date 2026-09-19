//
// Created by Sebastian on 12.09.26.
//

#ifndef SRC_MENU_H
#define SRC_MENU_H

#include <menu/general.h>

namespace menu
{
class Menu
{
public:
	Menu();

	General& general();

private:
	General m_general;
};
}


#endif //SRC_MENU_H
