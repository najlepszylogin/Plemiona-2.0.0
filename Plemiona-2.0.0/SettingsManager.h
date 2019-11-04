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
	inline double music = false;
	inline double sounds = true;
	inline double musicVol = 100;
	inline double soundsVol = 100;
}

namespace mapSettings
{
	inline int forestSeeds = 200;
	inline Vector2 CapitalMapSizeSmall = Vector2(60, 60);
	inline Vector2 CapitalMapSizeMedium = Vector2(90,90);
	inline Vector2 CapitalMapSizeBig = Vector2(120, 120);
	inline Vector2* capitalMapSize = &CapitalMapSizeMedium;
}