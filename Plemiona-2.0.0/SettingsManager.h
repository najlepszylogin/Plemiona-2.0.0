#pragma once
#include <iostream>

inline std::string mapFilename = "map.bmp";

namespace times
{
	inline sf::Time buttonTime = sf::milliseconds(1000);
	

}

namespace playersSettings
{
	inline const int playersNum = 1;
	
}

namespace mainSettings
{
	inline double showPos = true;
	inline double music = true;
	inline double sounds = true;
}

namespace mapSettings
{
	inline int forestSeeds = 200;
}