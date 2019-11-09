#pragma once
#ifndef SHAPES_
#define SHAPES_

#include "Vector2.h"


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

class TextBox
{
public:
	Vector2 pos;
	Vector2 size;
	std::string text;
	int color;
	static std::vector<TextBox*> boxes;
	int menu;

	TextBox(Vector2 position, Vector2 size_, std::string text, int menu = 0, int color = _white)
	{
		pos = position;
		size = size_;
		this->color = color;
		this->text = text;
		boxes.push_back(this);
		this->menu = menu;
	}
	TextBox(int x, int y, int width, int height, std::string text, int menu = 0, int color = _white)
	{
		pos.x = x;
		pos.y = y;
		size.x = width;
		size.y = height;
		this->color = color;
		this->text = text;
		boxes.push_back(this);
		this->menu = menu;
	}
	~TextBox() {};
};

class ProgressBar
{
public:
	Vector2 pos;
	int size;
	double* var;
	double div;
	static std::vector<ProgressBar*> bars;
	int menu;

	ProgressBar(Vector2 position, int size_,double &var, int menu = 0)//variables only 0 - 100
	{
		pos = position;
		this->size = size_;
		this->var = &var;
		bars.push_back(this);
		this->menu = menu;
		div = 100 / size;
	}
	ProgressBar(int x, int y, int size, double &var, int menu = 0)//variables only 0 - 100
	{
		pos.x = x;
		pos.y = y;
		this->var = &var;
		this->size = size;
		bars.push_back(this);
		this->menu = menu;
		div = 100 / size;
	}
	~ProgressBar() {};
};

class DialogBoxC
{
public:
	Vector2 pos;
	Vector2 size;
	std::string str;


	DialogBoxC(Vector2 position, Vector2 size_, std::string& st)
	{
		pos = position;
		size = size_;
		str = st;


	}
	DialogBoxC(int x, int y, int width, int height, std::string & st)
	{
		pos.x = x;
		pos.y = y;
		size.x = width;
		size.y = height;
		str = st;
	}
	~DialogBoxC() {};
};

class Light
{
public:
	Vector2 pos;
	int size;
	int color;
	int menu;
	bool active = false;
	static std::vector<Light*> lights;

	Light(Vector2 pos, int size = 0, int menu = 0, int color = _green)
	{
		this->pos = pos;
		this->size = size;
		this->color = color;
		this->menu = menu;
		lights.push_back(this);
	}
	Light(int x, int y, int size = 0, int menu = 0, int color = _green)
	{
		pos.x = x;
		pos.y = y;
		this->size = size;
		this->color = color;
		this->menu = menu;
		lights.push_back(this);
	}
	void Switch()
	{
		if (active == false)active = true;
		else
			active = false;
	}
	~Light() {};
};

inline std::vector<Box*> Box::boxes;
inline std::vector<ProgressBar*> ProgressBar::bars;
inline std::vector<Light*> Light::lights;
inline std::vector<TextBox*> TextBox::boxes;

#endif SHAPES_
