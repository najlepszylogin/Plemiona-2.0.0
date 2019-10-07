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
	std::string name;
	Vector2 pos;
	char *appearance;

	Tile(int color, std::string str, Vector2 pos, char *app)
	{
		this->color = color;
		this->name = str;
		this->pos = pos;
		this->appearance = app;
	}
	void Reset(int color, std::string str, Vector2 pos, char *app)
	{
		this->color = color;
		this->name = str;
		this->pos = pos;
		this->appearance = app;
	}
	~Tile() {};
};


class MapManager
{
private:
	
	int offset = 20;

public:
	Vector2 size;
	sf::Image mainmapimage;
	void Draw(GameManager *mgr);
	void DrawTest(GameManager* mgr);
	void LoadMap(std::string filename);
	std::vector<std::vector<Tile>>mainMap;
};

inline MapManager MainMap;

#endif MAPMGR_