#pragma once


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