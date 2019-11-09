#pragma once

#ifndef NAR__
#define NAR__
#include "Linker.h"



class Narrator
{
public:
	std::vector<std::string> info;
	double pages;
	std::vector<bool> read;
	int read_count;

	Narrator() 
	{
		info.clear();
		pages = 0;
		info.push_back(" ");
		read.push_back(true);
		read_count = 1;
	};
	~Narrator() {};

	void Reset()
	{
		info.clear();
		info.push_back(" ");
		read.clear();
		read.push_back(true);
		pages = 0;
		read_count = 1;

	}
	void AddInfo(std::string str);

};

#endif NAR__