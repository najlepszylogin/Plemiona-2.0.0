#pragma once

#ifndef MAPMGR_
#define MAPMGR_
#include "GameManager.h"
#include "Defines.h"


class GameManager;

class Tile
{
private:

public:
	int color;
	int back_color = _black;
	std::string name;
	Vector2 pos;
	char *appearance;
	bool highlighted = false;


	Tile(int color, std::string str, Vector2 pos, char *app, int bkccl = _black)
	{
		this->color = color;
		this->name = str;
		this->pos = pos;
		this->appearance = app;
		back_color = bkccl;
	}
	void Reset(int color, std::string str, Vector2 pos, char *app, int bkccl = _black)
	{
		this->color = color;
		this->name = str;
		this->pos = pos;
		this->appearance = app;
		back_color = bkccl;
	}
	Tile()
	{
		color = _black;
		back_color = _black;
		pos = Vector2(-1, -1);
		
	}
	void Click()
	{
		if (highlighted)
			highlighted = false;
		else highlighted = true;

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
};

inline MapManager MainMap;

#endif MAPMGR_