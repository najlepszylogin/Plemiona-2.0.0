#pragma once

#ifndef PLAYER_
#define PLAYER_
#include "Narrator.h"

class Player
{
public:
	int id;
	Vector2 pos;
	Vector2 mapPos;
	Vector2 capitalMapPos;
	int color;
	std::string name;
	std::string password;
	double food;
	double stone;
	double money;
	double faith;
	double knowledge;
	Narrator narrator;

	Player(int id, Vector2 pos, int color, std::string nm);
	Player(int id, int x, int y, int color, std::string nm);
	

};

#endif PLAYER_

