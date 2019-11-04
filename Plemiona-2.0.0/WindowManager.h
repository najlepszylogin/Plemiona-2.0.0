#pragma once


#include <Windows.h>
#include <iostream>
#include "Vector2.h"
#ifndef WINDOWMGR_
#define WINDOWMGR_

class Window
{
private:
	


public:
	HANDLE hOut;
	HANDLE wHnd;
	HANDLE rHnd;
	HANDLE hout;
	HANDLE hin;
	INPUT_RECORD InputRecord;
	DWORD Events;
	COORD coord;
	CONSOLE_CURSOR_INFO cci;
	PCONSOLE_SCREEN_BUFFER_INFO inf;





	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x; coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		return;
	}
	void gotoxy(Vector2 &pos)
	{
		COORD coord;
		coord.X = pos.x; coord.Y = pos.y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		return;
	}
	void cls()
	{
		HANDLE hOut;
		COORD Position;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		Position.X = 0;
		Position.Y = 0;
		SetConsoleCursorPosition(hOut, Position);
	}
	void Init()
	{
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SMALL_RECT windowSize = { 0, 0, 1440, 900 };
		
		
		COORD bufferSize = { 220, 75 };
		wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
		rHnd = GetStdHandle(STD_INPUT_HANDLE);
		std::string s = "Plemiona!";
		std::wstring stemp = std::wstring(s.begin(), s.end());
		LPCWSTR sw = stemp.c_str();
		SetConsoleTitle(sw);
		cci.dwSize = 25;
		cci.bVisible = FALSE;
		SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
		SetConsoleScreenBufferSize(wHnd, bufferSize);
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		hin = GetStdHandle(STD_INPUT_HANDLE);

		SetConsoleCursorInfo(hout, &cci);
		SetConsoleMode(hin, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
		ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
		
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0;                   // Width of each character in the font
		cfi.dwFontSize.Y = 25;                  // Height
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		//wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

		
	}

};



#endif WINDOWMGR_