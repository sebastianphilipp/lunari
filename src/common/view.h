//
// Created by Sebastian on 05.09.26.
//

#ifndef SRC_COMMON_VIEW_H
#define SRC_COMMON_VIEW_H

#include <cstdint>

namespace common
{
	enum eView : uint8_t
	{
		None = 0,
		Main,
		Game,
		GeneralSettings
	};
} // common

#endif //SRC_COMMON_VIEW_H
