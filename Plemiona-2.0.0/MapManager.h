#pragma once

#ifndef MAPMGR_
#define MAPMGR_
#include "GameManager.h"
#include "Defines.h"
#include "Player.h"
#include "SettingsManager.h"
#include "VariableManager.h"
#include "Names.h"


class GameManager;



class BonusTile
{
public:
	void (*ActionWhenMet)(GameManager*, Vector2 pos);
	void (*ActionPerTurn)(GameManager*, Vector2 pos);
	std::string name;
	Vector2 pos;
	bool met;
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

class Tile
{
private:

public:
	int color;
	int back_color = _black;
	std::string name;
	Vector2 pos;
	char *appearance;
	Player *owning = nullptr;
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
	Tile currentTile;
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





#endif MAPMGR_