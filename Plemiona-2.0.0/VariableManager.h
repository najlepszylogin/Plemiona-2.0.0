#pragma once
#ifndef VARMGR_
#define VARMGR_
#include "SettingsManager.h"


namespace Game
{
	inline int e = 0;
	inline std::string playerNamesTemp[playersSettings::playersNum];
	inline int playerColorsTemp[4] = { _red, _blue, _pink,_pink_};
	inline int menu = 0; //0 - main, 1 - settings, 2 - city
	inline bool dialogBoxOpened = 0;
	inline bool needPassword = 0;
	inline int currentPlayer = 0;
	inline double current_narrator_page = 0;
	inline int map_type = 0; //0 - main
	inline ClickableString* currentMap;

};


#endif VARMGR_
