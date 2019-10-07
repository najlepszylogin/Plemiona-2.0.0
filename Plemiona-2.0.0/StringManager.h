#pragma once
#include <iostream>
#include <vector>
#include "Vector2.h"
#ifndef STRINGMGR_
#define STRINGMGR_



class GameManager;


class String
{
public:
	std::string str;
	Vector2 pos;
	int color;
	static std::vector<String*> strings;
	int menu;


	String(Vector2 position, std::string str, int menu = 0, int color = _white)//menu is index of menuUI
	{
		this->str = str;
		this->color = color;
		pos = position;
		strings.push_back(this);
		this->menu = menu;
		
	}
	String(int x, int y, std::string str, int menu = 0, int color = _white)
	{
		pos.x = x;
		pos.y = y;
		this->str = str;
		this->color = color;
		strings.push_back(this);
		this->menu = menu;
	}
	~String() {};
	
};


class StringBox
{
public:
	std::string str;
	Vector2 pos;
	int color;
	Vector2 size;
	static std::vector<StringBox*> stringboxes;
	int menu;

	StringBox(Vector2 position, Vector2 size, std::string str, int menu = 0, int color = _white)
	{
		this->str = str;
		this->color = color;
		pos = position;
		this->size = size;
		stringboxes.push_back(this);
		this->menu = menu;
	}
	StringBox(int x, int y, int width, int height, std::string str, int menu = 0, int color = _white)
	{
		pos.x = x;
		pos.y = y;
		this->str = str;
		this->color = color;
		size.x = width;
		size.y = height;
		stringboxes.push_back(this);
		this->menu = menu;
	}
	~StringBox() {};
};

class VariableString
{
public:
	std::string str;
	Vector2 pos;
	int color;
	int color2;
	int *var;
	static std::vector<VariableString*> variablestrings;
	int menu;

	VariableString(Vector2 position,int &variable, std::string str,int menu = 0, int color = _white, int color2 = _white)
	{
		this->str = str;
		this->color = color;
		pos = position;
		var = &variable;
		this->color2 = color2;
		variablestrings.push_back(this);
		this->menu = menu;
	}
	VariableString(int x, int y, int& variable, std::string str, int menu = 0, int color = _white, int color2 = _white)
	{
		pos.x = x;
		pos.y = y;
		this->str = str;
		this->color = color;
		var = &variable;
		this->color2 = color2;
		variablestrings.push_back(this);
		this->menu = menu;
	}
	~VariableString() {};
};

class ClickableString
{
public:
	std::string str;
	Vector2 pos;
	int color;
	bool clicked = false;
	int def_color;
	static std::vector<ClickableString*> clickablestrings;
	void (*Action)(GameManager*);
	int menu;
	ClickableString()
	{
		str = "";
		color = _white;
		pos = Vector2(0, 0);
		def_color = _white;
		clickablestrings.push_back(this);
		Action = nullptr;
		menu = 0;
	}
	ClickableString(Vector2 position, std::string str, void f(GameManager*), int menu = 0, int color = _white)
	{
		this->str = str;
		this->color = color;
		pos = position;
		def_color = color;
		clickablestrings.push_back(this);
		Action = *f;
		this->menu = menu;
	}
	ClickableString(int x, int y, std::string str, void f(GameManager*), int menu = 0, int color = _white)
	{
		pos.x = x;
		pos.y = y;
		this->str = str;
		this->color = color;
		def_color = color;
		clickablestrings.push_back(this);
		Action = *f;
		this->menu = menu;
	}
	~ClickableString() {};
	void ChangeState()
	{
		if (clicked == false)
		{
			clicked = true;
			color = _green;
			
			return;
		}
		if (clicked == true)
		{
			clicked = false;
			color = def_color;
			
			return;
		}
	}
	void Reset()
	{
		clicked = false;
		color = def_color;
	}
};

class ClickableVarString
{
public:
	std::string str;
	Vector2 pos;
	int color;
	int color2;
	int def_color;
	int def_color2;
	int* var;
	bool clicked = false;
	static std::vector<ClickableVarString*> clickablevarstrings;
	void (*Action)(GameManager*);
	int menu;
	ClickableVarString()
	{
		str = "";
		color = _white;
		pos = Vector2(0, 0);
		def_color = _white;
		clickablevarstrings.push_back(this);
		Action = nullptr;
		menu = 0;
		color2 = _white;
		def_color2 = _white;
		var = nullptr;
	}
	ClickableVarString(Vector2 position, int& variable, std::string str, void f(GameManager*), int menu = 0, int color = _white, int color2 = _white)
	{
		this->str = str;
		this->color = color;
		pos = position;
		var = &variable;
		this->color2 = color2;
		def_color = color;
		def_color2 = color2;
		clickablevarstrings.push_back(this);
		Action = *f;
		this->menu = menu;
	}
	ClickableVarString(int x, int y, int& variable, std::string str, void f(GameManager*), int menu = 0, int color = _white, int color2 = _white)
	{
		pos.x = x;
		pos.y = y;
		this->str = str;
		this->color = color;
		var = &variable;
		this->color2 = color2;
		def_color = color;
		def_color2 = color2;
		clickablevarstrings.push_back(this);
		Action = *f;
		this->menu = menu;
	}
	~ClickableVarString() {};
	void ChangeState()
	{
		if (clicked == false)
		{
			clicked = true;
			color = _green;
			color2 = _green;
			return;
		}
		if (clicked == true)
		{
			clicked = false;
			color = def_color;
			color2 = def_color2;
			return;
		}
	}

	void Reset()
	{
		clicked = false;
		color = def_color;
		color2 = def_color2;
	}


};

class ClickableBackButton
{
public:
	std::string str;
	Vector2 pos;
	int color;
	bool clicked = false;
	int def_color;
	static std::vector<ClickableBackButton*> clickablestrings;
	void (*Action)(GameManager*);
	int menu;
	ClickableBackButton()
	{
		str = "";
		color = _white;
		pos = Vector2(0, 0);
		def_color = _white;
		clickablestrings.push_back(this);
		Action = nullptr;
		menu = 0;
	}
	ClickableBackButton(Vector2 position, std::string str, void f(GameManager*), int menu = 0, int color = _white)
	{
		this->str = str;
		this->color = color;
		pos = position;
		def_color = color;
		clickablestrings.push_back(this);
		Action = *f;
		this->menu = menu;
	}
	ClickableBackButton(int x, int y, std::string str, void f(GameManager*), int menu = 0, int color = _white)
	{
		pos.x = x;
		pos.y = y;
		this->str = str;
		this->color = color;
		def_color = color;
		clickablestrings.push_back(this);
		Action = *f;
		this->menu = menu;
	}
	ClickableBackButton(int x, int y, char ch, void f(GameManager*), int menu = 0, int color = _white)
	{
		pos.x = x;
		pos.y = y;
		this->str.push_back(ch);
		this->color = color;
		def_color = color;
		clickablestrings.push_back(this);
		Action = *f;
		this->menu = menu;
	}
	~ClickableBackButton() {};
	void ChangeState()
	{
		if (clicked == false)
		{
			clicked = true;
			color = _green;
			return;
		}
		if (clicked == true)
		{
			clicked = false;
			color = def_color;
			return;
		}
	}
	void Reset()
	{
		clicked = false;
		color = def_color;
	}
};




inline std::vector<String*> String::strings;
inline std::vector<VariableString*> VariableString::variablestrings;
inline std::vector<StringBox*> StringBox::stringboxes;
inline std::vector<ClickableString*> ClickableString::clickablestrings;
inline std::vector<ClickableVarString*> ClickableVarString::clickablevarstrings;
inline std::vector<ClickableBackButton*>ClickableBackButton::clickablestrings;


#endif STRINGMGR_

