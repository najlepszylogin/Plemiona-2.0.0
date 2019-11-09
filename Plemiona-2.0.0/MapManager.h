#pragma once

#ifndef MAPMGR_
#define MAPMGR_
#include "GameManager.h"



class GameManager;
class City;


class BonusTile
{
public:
	void (*ActionWhenMet)(GameManager*, Vector2 pos);
	void (*ActionPerTurn)(GameManager*, Vector2 pos);
	std::string name;
	Vector2 pos;
	bool met;
	City* city = nullptr;

	~BonusTile() {};
	BonusTile(void fwMet(GameManager*, Vector2), void fpTurn(GameManager*, Vector2),std::string name, Vector2 posi)
	{
		this->name = name;
		ActionWhenMet = fwMet;
		ActionPerTurn = fpTurn;
		met = false;
		pos = posi;
	}
	BonusTile()
	{
		name = names::empty;
		ActionPerTurn = nullptr;
		ActionWhenMet = ActionPerTurn;
		met = false;
	}
	void Met(GameManager *mgr)
	{
		if (met == false)
		{
			ActionWhenMet(mgr, pos);
			met = true;
		}
	}
	void Turn(GameManager *mgr)
	{
		if (met == true)
		{
			ActionPerTurn(mgr, pos);
		}
	}
	
};

inline BonusTile nullbon;
inline Player neutral(99,0,0,_gray,"Gaja");

enum income_
{
	gold = 0,
	wood = 1,
	stone =2,
	iron = 3,
	food = 4,
	production = 5,
	luxuries = 6,
	faith = 7,
	knowledge = 8
};

class Tile
{
private:

public:
	income_ incomes;
	int color;
	double income[8];

	int region;
	int gmina;

	int back_color = _black;
	std::string name;
	Vector2 pos;
	char *appearance;
	Player* owning = &neutral;

	bool open[playersSettings::playersNum];
	bool inSight[playersSettings::playersNum];
	int soil;
	BonusTile bonus;
	int travelCost;


	Tile(int color, std::string str, Vector2 pos, char *app, int bkccl = _black)
	{
		this->color = color;
		this->name = str;
		this->pos = pos;
		this->appearance = app;
		back_color = bkccl;
		open[0] = true;
		soil = 1;
		travelCost = 1;
		
	}
	void Reset(int color, std::string str, Vector2 pos, char *app, int bkccl = _black)
	{
		this->color = color;
		this->name = str;
		this->pos = pos;
		this->appearance = app;
		back_color = bkccl;
		open[0] = true;
		soil = 1;
		travelCost = 1;
	}
	Tile()
	{
		color = _black;
		back_color = _black;
		pos = Vector2(-1, -1);
		
	}
	
	void Reset()
	{
		color = _black;
		back_color = _black;
		pos = Vector2(-1, -1);

	}
	~Tile() {};
};


class MapManager
{
private:
	
	int CheckNeigh(std::string input, std::string checking, Vector2 pos);

public:
	Tile *currentTile = nullptr;
	Vector2 size;
	sf::Image mainmapimage;
	void Draw(GameManager *mgr);
	void DrawTest(GameManager* mgr);
	void LoadMap(std::string filename);
	std::vector<std::vector<Tile>>mainMap;
	bool highlighted = false;
	void Highlight(){highlighted = true;}
	void Unlight() { highlighted = false; }
	
};

inline MapManager MainMap;

class CapitalMap : MapManager
{
	int water;
	int mountains;
public:
	CapitalMap(int water, int mountains)//0 on water and mountain means that there is no w or m nearby, 1 is up tile and goin with clock 4 times
	{
		this->size = *mapSettings::capitalMapSize;
		this->water = water;
		this->mountains = mountains;
		this->GenerateMap();
	}
	~CapitalMap() {};
	void GenerateMap();
	void Draw(GameManager *mgr);
};







#endif MAPMGR_