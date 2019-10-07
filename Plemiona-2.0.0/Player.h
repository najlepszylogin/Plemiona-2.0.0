#pragma once

#ifndef PLAYER_
#define PLAYER_
#include "Vector2.h"

class Player
{
public:
	int id;
	Vector2 pos;
	Vector2 mapPos;
	int color;
	std::string name;

	Player(int id, Vector2 pos, int color, std::string nm);
	Player(int id, int x, int y, int color, std::string nm);
	

};

#endif // !PLAYER_

