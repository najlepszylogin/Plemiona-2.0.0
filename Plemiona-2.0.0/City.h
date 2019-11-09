#pragma once
#ifndef CITY__
#define CITY__

#include "Linker.h"
#include "Vector2.h"
#include "Player.h"

class City
{
public:
	std::string name;
	Vector2 pos;
	int level;
	Player* owner = nullptr;

	int id;
	int region;

	float production;
	int wood;
	int stone;
	int iron;
	int food;
	int population;
	float happines;
	float health;

	


};

class Capital : City
{
	

};

#endif CITY__