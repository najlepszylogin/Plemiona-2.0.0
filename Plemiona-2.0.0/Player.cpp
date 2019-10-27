#include "Player.h"


Player::Player(int id, int x, int y, int color, std::string nm)
{
	this->id = id;
	pos.x = x;
	pos.y = y;
	this->color = color;
	mapPos = pos;
	name = nm;
	
	
}
Player::Player(int id, Vector2 pos, int color, std::string nm)
{
	this->id = id;
	this->pos = pos;
	this->color = color;
	mapPos = pos;
	name = nm;
}