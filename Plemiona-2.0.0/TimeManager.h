#pragma once

#ifndef TIME__
#define TIME__

class Time
{
public:
	double Hours;
	double Minutes;

	double GetHours() { return Hours; }
	double GetMinutes() { return Minutes; }
	void SetHours(double a) { Hours = a; }
	void SetMinutes(double a) { Minutes = a; }

	~Time() {};
	Time()
	{
		Game::inGameTime.restart();
		Hours = 0;
		Minutes = 0;

		

	}
	friend std::ostream& operator<<(std::ostream& os, Time& a)
	{
		int seconds = Game::inGameTime.getElapsedTime().asSeconds();
		int minutes = seconds / 60;
		seconds = seconds - minutes * 60;
		int hours = minutes / 60;
		minutes = minutes - hours * 60;
		a.Hours = hours;
		a.Minutes = minutes;

		if (a.Hours < 10)
		{
			if (a.Minutes < 10)
				os << "0" << a.Hours << ":0" << a.Minutes;
			else
				os << "0" << a.Hours << ":" << a.Minutes;
		}
		else
		{
			if (a.Minutes < 10)
				os << "" << a.Hours << ":0" << a.Minutes;
			else
				os << "" << a.Hours << ":" << a.Minutes;
		}

		return os;
	};

	void Restart()
	{
		Game::inGameTime.restart();
		Hours = 0;
		Minutes = 0;
	}

};



class Date
{
public:
	int year;
	int month;
	int day;

	~Date() {};

	Date(int day, int month, int year)
	{
		this->year = year;
		this->month = month;
		this->day = day;

		if (month < 2 && day < 21)Game::season = names::winter;
		else if (month < 5 && day < 20)Game::season = names::spring;
		else if (month < 8 && day < 23)Game::season = names::summer;
		else if (month < 11 && day < 20)Game::season = names::autumn;
		else Game::season = names::winter;

	}
	Date()
	{
		year = 0;
		month = 0;
		day = 0;

	}
	void Set(int day, int month, int year)
	{
		this->year = year;
		this->month = month;
		this->day = day;
		if (month < 2 && day < 21)Game::season = names::winter;
		else if (month < 5 && day < 20)Game::season = names::spring;
		else if (month < 8 && day < 23)Game::season = names::summer;
		else if (month < 11 && day < 20)Game::season = names::autumn;
		else Game::season = names::winter;
	}
	void AddTime(int addDays)
	{
		day += addDays;
		if (month == 0)
		{
			if (day > 31)
			{
				month = 1;
				day = day - 31;
			}
		}
		if (month == 1)
		{
			if (day > 28 && year%4 != 0 )
			{
				month = 2;
				day = day - 28;
			}
			if (day > 29 && year % 4 == 0)
			{
				month = 2;
				day = day - 29;
			}
		}
		if (month == 2)
		{
			if (day > 31)
			{
				month = 3;
				day = day - 31;
			}
		}
		if (month == 3)
		{
			if (day > 30)
			{
				month = 4;
				day = day - 30;
			}
		}
		if (month == 4)
		{
			if (day > 31)
			{
				month = 5;
				day = day - 31;
			}
		}
		if (month == 5)
		{
			if (day > 30)
			{
				month = 6;
				day = day - 30;
			}
		}
		if (month == 6)
		{
			if (day > 31)
			{
				month = 7;
				day = day - 31;
			}
		}
		if (month == 7)
		{
			if (day > 31)
			{
				month = 8;
				day = day - 31;
			}
		}
		if (month == 8)
		{
			if (day > 30)
			{
				month = 9;
				day = day - 30;
			}
		}
		if (month == 9)
		{
			if (day > 31)
			{
				month = 10;
				day = day - 31;
			}
		}
		if (month == 10)
		{
			if (day > 30)
			{
				month = 11;
				day = day - 30;
			}
		}
		if (month == 11)
		{
			if (day > 31)
			{
				month = 0;
				day = day - 31;
				year++;
			}
		}
		if (Game::season == names::winter && month == 2 && day >= 21)
		{
			Game::season = names::spring;
			//game.players[Game::currentPlayer].narrator.AddInfo("");
			
		}
		if (Game::season == names::spring && month == 5 && day >= 20)Game::season = names::summer;
		if (Game::season == names::summer && month == 8 && day >= 23)Game::season = names::autumn;
		if (Game::season == names::autumn && month == 11 & day >= 20)Game::season = names::winter;
		
	}

	friend std::ostream& operator<<(std::ostream& os, const Date& a)
	{

		os << "Data: " << a.day << ". " << months::months[a.month] << " " << a.year<<"      ";

		return os;
	};

};

#endif TIME__