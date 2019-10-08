#pragma once
#ifndef VARMGR_
#define VARMGR_
#include "SettingsManager.h"


namespace Game
{
	inline int e = 0;
	inline std::string playerNamesTemp[playersSettings::playersNum];
	inline int playerColorsTemp[4] = { _red, _blue, _pink,_pink_};
	inline int menu = 0; //0 - main, 1 - settings,
	inline int currentPlayer = 0;
	
};


#endif VARMGR_
