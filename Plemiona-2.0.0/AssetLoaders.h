#pragma once
#include "GameManager.h"



inline void LoadMusic()
{
	for (int i = 0; i <= 5; i++)
	{
		game.songs[i].openFromFile("Assets/Music/calm"+std::to_string(i)+".ogg");
		game.music.AddSong(&game.songs[i], 2);
	}
	int j = 0;
	for (int i = 6; i <= 8; i++)
	{
		
		game.songs[i].openFromFile("Assets/Music/sad" + std::to_string(j) + ".ogg");
		game.music.AddSong(&game.songs[i], 1);
		j++;
	}
	j = 0;
	
}