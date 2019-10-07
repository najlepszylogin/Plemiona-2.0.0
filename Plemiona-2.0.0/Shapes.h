#pragma once

#include "Vector2.h"
#include "Defines.h"
#include <vector>

#ifndef SHAPES_
#define SHAPES_

class Box
{
public:
	Vector2 pos;
	Vector2 size;
	char type;
	int color;
	static std::vector<Box*> boxes;
	int menu;

	Box(Vector2 position, Vector2 size_,int type = 0, int menu = 0, int color = _white)
	{
		pos = position;
		size = size_;
		this->color = color;
		this->type = type;
		boxes.push_back(this);
		this->menu = menu;
	}
	Box(int x, int y, int width, int height, int type = 0, int menu = 0, int color = _white)
	{
		pos.x = x;
		pos.y = y;
		size.x = width;
		size.y = height;
		this->color = color;
		this->type = type;
		boxes.push_back(this);
		this->menu = menu;
	}
	~Box() {};
};

inline std::vector<Box*> Box::boxes;

#endif SHAPES_
