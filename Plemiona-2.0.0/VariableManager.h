#pragma once
#ifndef VARMGR_
#define VARMGR_


namespace Game //all of this will be in savefile
{
	inline int e = 0;
	inline std::string playerNamesTemp[playersSettings::playersNum];
	inline int playerColorsTemp[4] = { _red, _blue, _pink,_pink_};
	inline int menu = 0; //0 - main, 1 - settings, 2 - city
	inline bool dialogBoxOpened = 0;
	inline bool needPassword = 0;
	inline int currentPlayer = 0;
	inline double current_narrator_page = 0;
	inline int map_type = 0; //0 - main, 1 - teretority, 
	inline ClickableString* currentMap;
	inline int income_type = 0; //0 - gold, 1 - wood, 2 - stone, 3 - iron, 4 - food, 5 - production, 6 - luxuries,  7 - faith, 8 - knowledge
	inline sf::Clock inGameTime;
	inline double turn = 0;
	inline std::string season;

};


#endif VARMGR_
