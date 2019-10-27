#pragma once
#include "WorkManager.h"

class Narrator
{
public:
	std::vector<std::string> info;
	double pages;
	Narrator() 
	{
		info.clear();
		pages = 0;
		info.push_back(" ");
	};
	~Narrator() {};

	void Reset()
	{
		info.clear();
		info.push_back(" ");
		pages = 0;
	}
	void AddInfo(std::string str)
	{
		if (info[0] == " ")info.erase(info.begin());
		else pages++;
		info.push_back(str);
		
	}

};