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
		game.DrawAllBoxes();

	};
	inline void openMainMenu(GameManager* mgr)
	{
		Game::menu = 0;
		system("CLS");
		mgr->wind.Init();
		game.DrawAllBoxes();
	};
	inline void mousePosF(GameManager* mgr)
	{
		if (mainSettings::showPos == true)mainSettings::showPos = false;
		else
			mainSettings::showPos = true;
		system("CLS");
		mgr->wind.Init();
		game.DrawAllBoxes();
	}
	inline void musicF(GameManager* mgr)
	{
		if (mainSettings::music == true)mainSettings::music = false;
		else
			mainSettings::music = true;
		mgr->music.Stop();
		system("CLS");
		mgr->wind.Init();
		game.DrawAllBoxes();
	}
	inline void soundsF(GameManager* mgr)
	{
		if (mainSettings::sounds == true)mainSettings::sounds = false;
		else
			mainSettings::sounds = true;
		system("CLS");
		mgr->wind.Init();
		game.DrawAllBoxes();
	}

	inline void backToHome(GameManager* mgr)
	{
		mgr->players[Game::currentPlayer].mapPos = mgr->players[Game::currentPlayer].pos;
		system("CLS");
		mgr->wind.Init();
		game.DrawAllBoxes();
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
	inline void VolumeMusicPlus(GameManager* mgr)
	{
		if (mainSettings::musicVol < 100)mainSettings::musicVol += 10;
		mgr->ChangeVolume(mainSettings::musicVol);
	}
	inline void VolumeMusicMinus(GameManager* mgr)
	{
		if (mainSettings::musicVol > 0)mainSettings::musicVol -= 10;
		mgr->ChangeVolume(mainSettings::musicVol);
	}
	inline void VolumeSoundPlus(GameManager* mgr)
	{
		if (mainSettings::soundsVol < 100)mainSettings::soundsVol += 10;
		mgr->ChangeVolume(mainSettings::soundsVol);
	}
	inline void VolumeSoundMinus(GameManager* mgr)
	{
		if (mainSettings::soundsVol > 0)mainSettings::soundsVol -= 10;
		mgr->ChangeVolume(mainSettings::soundsVol);
	}


}






