#pragma once
#include <SFML/Audio.hpp>

static class MusicManager
{
private:
	std::vector<sf::Music*>sadSongs;
	std::vector<sf::Music*>calmSongs;
	std::vector<sf::Music*>ambientSongs;

	int sadSongsCount=0;
	int calmSongsCount=0;
	int ambientSongsCount=0;

	int current_song=0;


	
public:
	MusicManager()
	{
		
	}

	void AddSong(sf::Music *song, int type=2)//types: 1 = sad, 2 = calm, 3 = ambient
	{
		if (type == 1)
		{
			
			sadSongs.push_back(song);
			sadSongsCount++;
			
		}
		if (type == 2)
		{


			calmSongs.push_back(song);
			calmSongsCount++;

		}
		if (type == 3)
		{


			ambientSongs.push_back(song);
			ambientSongsCount++;

		}
	}



	void PlaySong(int type)//types: 1 = sad, 2 = calm, 3 = ambient
	{
		if (mainSettings::music == false)return;
			if(sadSongs.size()>0)
			if (sadSongs[current_song]->getStatus() == sf::Music::Playing)return;
			if(calmSongs.size() > 0)
			if (calmSongs[current_song]->getStatus() == sf::Music::Playing)return;
			if(ambientSongs.size()>0)
			if (ambientSongs[current_song]->getStatus() == sf::Music::Playing)return;


		
		if (type == 1)
		{
			int song = rand() % sadSongsCount;
			sadSongs[song]->play();
			current_song = song;

		}
		if (type == 2)
		{
			int song = rand() % calmSongsCount;
			calmSongs[song]->play();
			current_song = song;

		}
		if (type == 3)
		{
			int song = rand() % ambientSongsCount;
			ambientSongs[song]->play();
			current_song = song;

		}
	}

	void Stop()
	{
		if (sadSongs.size() > 0)
			if (sadSongs[current_song]->getStatus() == sf::Music::Playing)sadSongs[current_song]->stop();
		if (calmSongs.size() > 0)
			if (calmSongs[current_song]->getStatus() == sf::Music::Playing)calmSongs[current_song]->stop();
		if (ambientSongs.size() > 0)
			if (ambientSongs[current_song]->getStatus() == sf::Music::Playing)calmSongs[current_song]->stop();
		current_song = 0;
	}

};