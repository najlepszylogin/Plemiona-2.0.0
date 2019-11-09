#pragma once
#ifndef ASSLDR__
#define ASSLDR__
#include "GameManager.h"


inline void LoadMusic()
{
	for (int i = 0; i <= 5; i++)
	{
		if(game.songs[i].openFromFile("Assets/Music/calm"+std::to_string(i)+".ogg"))
		game.music.AddSong(&game.songs[i], 2);
	}
	int j = 0;
	for (int i = 6; i <= 8; i++)
	{
		
		if (game.songs[i].openFromFile("Assets/Music/sad" + std::to_string(j) + ".ogg"))
		{
			game.music.AddSong(&game.songs[i], 1);
			j++;
		}
		
	}
	j = 0;
	
}



inline void LoadSounds()
{
	game.sound.AddSound("click",  sound::click);
	game.sound.AddSound("menu1",  sound::page[0]);
	game.sound.AddSound("menu2",  sound::page[1]);
	game.sound.AddSound("menu3",  sound::page[2]);
	game.sound.AddSound("MenuKnopka",  sound::menuKnopka);
	game.sound.AddSound("menuhud", sound::menuhud);

}

#endif ASSLDR__