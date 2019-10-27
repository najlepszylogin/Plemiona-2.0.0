#pragma once
#include "GameManager.h"




namespace func
{
	inline void endGameLoop(GameManager* mgr)
	{
		Game::e = 1;
	}
	inline void null(GameManager* mgr) { };
	inline void openSettings(GameManager* mgr)
	{
		Game::menu = 1;
		system("CLS");
		mgr->wind.Init();
		

	};
	inline void openMainMenu(GameManager* mgr)
	{
		Game::menu = 0;
		system("CLS");
		mgr->wind.Init();
		
	};
	inline void mousePosF(GameManager* mgr)
	{
		if (mainSettings::showPos == true)mainSettings::showPos = false;
		else
			mainSettings::showPos = true;
		system("CLS");
		mgr->wind.Init();
	}
	inline void musicF(GameManager* mgr)
	{
		if (mainSettings::music == true)mainSettings::music = false;
		else
			mainSettings::music = true;
		system("CLS");
		mgr->wind.Init();
	}
	inline void soundsF(GameManager* mgr)
	{
		if (mainSettings::sounds == true)mainSettings::sounds = false;
		else
			mainSettings::sounds = true;
		system("CLS");
		mgr->wind.Init();
	}

	inline void backToHome(GameManager* mgr)
	{
		mgr->players[Game::currentPlayer].mapPos = mgr->players[Game::currentPlayer].pos;
		system("CLS");
		mgr->wind.Init();
	}
	inline void up(GameManager* mgr)
	{
		if(mgr->players[Game::currentPlayer].mapPos.y > 0)
		mgr->players[Game::currentPlayer].mapPos.y--;
		
	}
	inline void down(GameManager* mgr)
	{
		if (mgr->players[Game::currentPlayer].mapPos.y < MainMap.size.y - 1)
		mgr->players[Game::currentPlayer].mapPos.y++;
		
	}
	inline void left(GameManager* mgr)
	{
		if (mgr->players[Game::currentPlayer].mapPos.x > 0)
		mgr->players[Game::currentPlayer].mapPos.x--;
		
	}
	inline void right(GameManager* mgr)
	{
		if (mgr->players[Game::currentPlayer].mapPos.x < MainMap.size.x - 1)
		mgr->players[Game::currentPlayer].mapPos.x++;
		
	}


}






