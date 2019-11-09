#pragma once
#ifndef MUS__
#define MUS__
#include <SFML/Audio.hpp>



static class MusicManager
{
private:
	std::vector<sf::Music*>sadSongs;
	std::vector<sf::Music*>calmSongs;
	std::vector<sf::Music*>ambientSongs;

	

	int current_song=0;


	
public:
	MusicManager()
	{
		
	}
	int sadSongsCount = 0;
	int calmSongsCount = 0;
	int ambientSongsCount = 0;

	void AddSong(sf::Music *song, int type=2)//types: 1 = sad, 2 = calm, 3 = ambient
	{
		if (type == 1)
		{
			
			sadSongs.push_back(song);
			sadSongsCount = sadSongs.size();
			
		}
		if (type == 2)
		{


			calmSongs.push_back(song);
			calmSongsCount = calmSongs.size();

		}
		if (type == 3)
		{


			ambientSongs.push_back(song);
			ambientSongsCount = ambientSongs.size();

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
			song /= 2;
			sadSongs[song]->play();
			current_song = song;

		}
		if (type == 2)
		{
			int song = rand() % calmSongsCount;
			song /= 2;
			calmSongs[song]->play();
			current_song = song;

		}
		if (type == 3)
		{
			int song = rand() % ambientSongsCount;
			song /= 2;
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

namespace sound
{
	inline sf::Sound click;
	inline sf::Sound page[3];
	inline sf::Sound menuKnopka;
	inline sf::Sound menuhud;
}

class SoundManager
{
public:
	sf::SoundBuffer buffers[200];
	int buffNum = 0;
	std::vector<sf::Sound*> sounds;

	void LoadSoundBuffer(std::string filename)
	{
		buffers[buffNum].loadFromFile("Assets/Sound/" + filename + ".wav");
		buffNum++;

	}

	void Play(sf::Sound& snd)
	{
		if (snd.getBuffer() == sound::click.getBuffer())
		{
			snd.setVolume(20);
		}
		if(mainSettings::sounds==1)
		snd.play();
	}

	void AddSound(std::string filename, sf::Sound& snd)
	{
		LoadSoundBuffer(filename);
		snd.setBuffer(buffers[buffNum-1]);
		sounds.push_back(&snd);
	}

};

#endif MUS__