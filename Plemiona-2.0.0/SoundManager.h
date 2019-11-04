#pragma once
#include <SFML/Audio.hpp>

static class SoundManager
{
public:
	static std::vector<sf::SoundBuffer> buffers;


	void LoadSoundBuffer(std::string filename)
	{
		sf::SoundBuffer* snd = new sf::SoundBuffer;
		snd->loadFromFile("Assets/Sounds/"+filename+".wav");
		buffers.push_back(*snd);
		delete snd;
		
	}



};

