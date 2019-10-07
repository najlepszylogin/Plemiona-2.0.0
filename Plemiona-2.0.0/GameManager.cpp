#include "GameManager.h"

using namespace std;
using namespace map;

void GameManager::LoadEngine()
{
	
	srand(time(NULL));
	MainMap.LoadMap(mapFilename);
	if (playersSettings::playersNum == 1)AddPlayer("Gracz 1", _red, 0, Vector2(50, 50));
	else
	{
		AskForNames();
		InitPlayers(playersSettings::playersNum, Game::playerNamesTemp, Game::playerColorsTemp);
	}
	//std::cin.sync();
	
	system("CLS");
	std::cout << "Engine Loaded";
	
}

void GameManager::DrawTst()
{
	MainMap.DrawTest(this);
}

GameManager::GameManager()
{
	std::cout << "loaded";
}

void GameManager::DrawRect(int x, int y, int width, int height,int type, int color)
{
	wind.gotoxy(x, y);
	SetConsoleTextAttribute(wind.hOut, color);
	
	if (type == 0)
	{
		wind.gotoxy(x, y);
		std::cout << char(201);
		wind.gotoxy(x+width, y+height);
		std::cout << char(188);
		wind.gotoxy(x, y+height);
		std::cout << char(200);
		wind.gotoxy(x+width, y);
		std::cout << char(187);
		for (int i = 1; i < width; i++)
		{
			wind.gotoxy(x + i, y);
			std::cout << char(205);
		}
		for (int i = 1; i < width; i++)
		{
			wind.gotoxy(x + i, y+height);
			std::cout << char(205);
		}
		for (int i = 1; i < height; i++)
		{
			wind.gotoxy(x, y + i);
			std::cout << char(186);
		}
		for (int i = 1; i < height; i++)
		{
			wind.gotoxy(x+width, y + i);
			std::cout << char(186);
		}


	}
	if (type == 1)
	{
		wind.gotoxy(x, y);
		std::cout << char(bloczek);
		wind.gotoxy(x+width, y+height);
		std::cout << char(bloczek);
		wind.gotoxy(x, y+height);
		std::cout << char(bloczek);
		wind.gotoxy(x+width, y);
		std::cout << char(bloczek);
		for (int i = 1; i < width; i++)
		{
			wind.gotoxy(x + i, y);
			std::cout << char(bloczek);
		}
		for (int i = 1; i < width; i++)
		{
			wind.gotoxy(x + i, y+height);
			std::cout << char(bloczek);
		}
		for (int i = 1; i < height; i++)
		{
			wind.gotoxy(x, y + i);
			std::cout << char(bloczek);
		}
		for (int i = 1; i < height; i++)
		{
			wind.gotoxy(x+width, y + i);
			std::cout << char(bloczek);
		}
	}
	
	SetConsoleTextAttribute(wind.hOut, _white);
}

void GameManager::DrawRect(Vector2 &position, Vector2 &size, int type, int color)
{
	DrawRect(position.x, position.y, size.x, size.y,type, color);
}
void GameManager::DrawRect(Box& shape)
{
	if (shape.menu == Game::menu)
	{
		DrawRect(shape.pos, shape.size, shape.type, shape.color);
	}
}

void GameManager::WriteString(String& str)
{
	if (str.menu == Game::menu)
	{
		SetConsoleTextAttribute(wind.hOut, str.color);
		wind.gotoxy(str.pos);
		std::cout << str.str;
		SetConsoleTextAttribute(wind.hOut, _white);
	}
}
void GameManager::WriteString(ClickableString& str)
{
	if (str.menu == Game::menu)
	{
		SetConsoleTextAttribute(wind.hOut, str.color);
		wind.gotoxy(str.pos);
		std::cout << str.str;
		SetConsoleTextAttribute(wind.hOut, _white);
	}
}
void GameManager::WriteString(ClickableBackButton& str)
{
	if (str.menu == Game::menu)
	{
		SetConsoleTextAttribute(wind.hOut, str.color);
		wind.gotoxy(str.pos);
		std::cout << str.str;
		SetConsoleTextAttribute(wind.hOut, _white);
	}
}
void GameManager::WriteString(Vector2& pos, std::string& str, int color)
{

	SetConsoleTextAttribute(wind.hOut, color);
	wind.gotoxy(pos);
	std::cout << str;
	SetConsoleTextAttribute(wind.hOut, _white);
}

void GameManager::WriteString(StringBox& str)
{
	if (str.menu == Game::menu)
	{
		SetConsoleTextAttribute(wind.hOut, str.color);
		wind.gotoxy(str.pos);
		int h = 0;

		for (int i = 0; i < str.size.y; i++)
		{
			for (int j = 0; j < str.size.x; j++) {

				if (h < str.str.size())
				{

					cout << str.str[h];
					h++;
				}
				else
					cout << " ";
			}
			wind.gotoxy(str.pos.x, str.pos.y + i + 1);
		}
		SetConsoleTextAttribute(wind.hOut, _white);
	}
}
void GameManager::WriteString(Vector2& pos, Vector2& size, std::string& str, int color)
{
	
		SetConsoleTextAttribute(wind.hOut, color);
		wind.gotoxy(pos);
		int h = 0;

		for (int i = 0; i < size.y; i++)
		{
			for (int j = 0; j < size.x; j++) {

				if (h < str.size())
				{

					cout << str[h];
					h++;
				}
				else
					cout << " ";
			}
			wind.gotoxy(pos.x, pos.y + i);
		}


		SetConsoleTextAttribute(wind.hOut, _white);
	
}

void GameManager::WriteVarString(VariableString& str)
{
	if (str.menu == Game::menu)
	{
		SetConsoleTextAttribute(wind.hOut, str.color);
		wind.gotoxy(str.pos);
		std::cout << str.str;
		SetConsoleTextAttribute(wind.hOut, str.color2);
		std::cout << *str.var;
		SetConsoleTextAttribute(wind.hOut, _white);
	}
}

void GameManager::WriteVarString(ClickableVarString& str)
{
	if (str.menu == Game::menu)
	{
		SetConsoleTextAttribute(wind.hOut, str.color);
		wind.gotoxy(str.pos);
		std::cout << str.str;
		SetConsoleTextAttribute(wind.hOut, str.color2);
		std::cout << *str.var;
		SetConsoleTextAttribute(wind.hOut, _white);
	}

}

bool GameManager::Update()
{
	ReadConsoleInput(wind.hin, &wind.InputRecord, 1, &wind.Events);
	wind.gotoxy(0, 0);

	if (wind.InputRecord.EventType == KEY_EVENT)
	{
		if(wind.InputRecord.Event.KeyEvent.uChar.AsciiChar == 'w' && players[Game::currentPlayer].mapPos.y > 0)players[Game::currentPlayer].mapPos.y--;
		if (wind.InputRecord.Event.KeyEvent.uChar.AsciiChar == 'a' && players[Game::currentPlayer].mapPos.x > 0)players[Game::currentPlayer].mapPos.x--;
		if (wind.InputRecord.Event.KeyEvent.uChar.AsciiChar == 's' && players[Game::currentPlayer].mapPos.y < MainMap.size.y-1)players[Game::currentPlayer].mapPos.y++;
		if (wind.InputRecord.Event.KeyEvent.uChar.AsciiChar == 'd' && players[Game::currentPlayer].mapPos.x < MainMap.size.x - 1)players[Game::currentPlayer].mapPos.x++;
		return true;
	}

	
		if (wind.InputRecord.EventType == MOUSE_EVENT)
		{
			
			if (wind.InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				wind.coord.X = wind.InputRecord.Event.MouseEvent.dwMousePosition.X;
				wind.coord.Y = wind.InputRecord.Event.MouseEvent.dwMousePosition.Y;
				
				MouseClickPos.Reset(wind.coord.X, wind.coord.Y);
				CheckAllBtns();
				if (mainSettings::showPos)
				{
					wind.gotoxy(1, 73);
					std::cout << GetMousePos() << "        ";
				}
				FlushConsoleInputBuffer(wind.hin);
				return true;
			}
		}
		FlushConsoleInputBuffer(wind.hin);
		return false;

}

Vector2 GameManager::GetMousePos()
{
	ReadConsoleInput(wind.hin, &wind.InputRecord, 1, &wind.Events);
	return Vector2(wind.InputRecord.Event.MouseEvent.dwMousePosition.X, wind.InputRecord.Event.MouseEvent.dwMousePosition.Y);

}

bool GameManager::CheckBtn(ClickableString& str)
{
	if (str.menu == Game::menu)
	{
		if (MouseClickPos.x >= str.pos.x && MouseClickPos.y >= str.pos.y && MouseClickPos.x < (str.str.size() + str.pos.x) && MouseClickPos.y <= str.pos.y)
		{
			str.ChangeState();
			MouseClickPos.x = 0;
			MouseClickPos.y = 0;
			return true;

		}
		str.Reset();
		return false;
	}
	return false;
}
bool GameManager::CheckBtn(ClickableVarString& str)
{
	if (str.menu == Game::menu)
	{
		std::string* s = new std::string(std::to_string(*str.var));
		if (MouseClickPos.x >= str.pos.x && MouseClickPos.y >= str.pos.y && MouseClickPos.x < (str.str.size() + str.pos.x) && MouseClickPos.y <= str.pos.y)
		{
			str.ChangeState();
			MouseClickPos.x = 0;
			MouseClickPos.y = 0;
			delete s;
			return true;
		}
		delete s;
		str.Reset();
		return false;
	}
	return false;
}
bool GameManager::CheckBtn(ClickableBackButton& str)
{
	if (str.menu == Game::menu)
	{
		if (MouseClickPos.x >= str.pos.x && MouseClickPos.y >= str.pos.y && MouseClickPos.x < (str.str.size() + str.pos.x) && MouseClickPos.y <= str.pos.y)
		{
			str.ChangeState();
			MouseClickPos.x = 0;
			MouseClickPos.y = 0;
			return true;
		}
		str.Reset();
		return false;
	}
	return false;
}

void GameManager::DrawAllStr()
{
		for (int i = 0; i < String::strings.size(); i++)WriteString(*String::strings[i]);
		for (int i = 0; i < StringBox::stringboxes.size(); i++)WriteString(*StringBox::stringboxes[i]);
		for (int i = 0; i < ClickableString::clickablestrings.size(); i++)WriteString(*ClickableString::clickablestrings[i]);
		for (int i = 0; i < VariableString::variablestrings.size(); i++)WriteVarString(*VariableString::variablestrings[i]);
		for (int i = 0; i < ClickableVarString::clickablevarstrings.size(); i++)WriteVarString(*ClickableVarString::clickablevarstrings[i]);
		for (int i = 0; i < ClickableBackButton::clickablestrings.size(); i++)WriteString(*ClickableBackButton::clickablestrings[i]);
}

void GameManager::DrawAllBoxes()
{
	for (int i = 0; i < Box::boxes.size(); i++)DrawRect(*Box::boxes[i]);
}

void GameManager::CheckAllBtns()
{
	for (int i = 0; i < ClickableString::clickablestrings.size(); i++)if(CheckBtn(*ClickableString::clickablestrings[i]))ClickableString::clickablestrings[i]->Action(this);
	for (int i = 0; i < ClickableVarString::clickablevarstrings.size(); i++)if(CheckBtn(*ClickableVarString::clickablevarstrings[i]))ClickableVarString::clickablevarstrings[i]->Action(this);
	for (int i = 0; i < ClickableBackButton::clickablestrings.size(); i++)
		if(CheckBtn(*ClickableBackButton::clickablestrings[i]))
		{
			ClickableBackButton::clickablestrings[i]->Action(this);
			buttonsTimer.restart();
			DrawAllStr();
		}
	
}

void GameManager::UpdateMap()
{
	MainMap.Draw(this);
}

bool GameManager::CheckClickedBtns()
{
	for (int i = 0; i < ClickableBackButton::clickablestrings.size(); i++)if (ClickableBackButton::clickablestrings[i]->clicked == true)
	{
		ClickableBackButton::clickablestrings[i]->ChangeState();
		return true;
	}
	return false;
}

bool GameManager::Update2()
{
	if (buttonsTimer.getElapsedTime() > sf::seconds(.01))
	{
		if (CheckClickedBtns())
		{
			DrawAllStr();
			wind.cls();
		}
		buttonsTimer.restart();
		return true;
	}
	return false;
}

void GameManager::AddPlayer(std::string name, int color, int id, Vector2 pos)
{
	Player* buff = new Player(id, pos, color, name);
	AddPlayer(*buff);
	delete buff;
}

void GameManager::AddPlayer(Player& pl)
{
	players.push_back(pl);
}



bool GameManager::CheckNames(std::string& str)
{
	for (int i = 0; i < playersSettings::playersNum; i++)
	{
		if (str == Game::playerNamesTemp[i])return false;
	}
	return true;
}

void GameManager::AskForNames()
{
	if (playersSettings::playersNum > 1)
	{
		for (int i = 0; i < playersSettings::playersNum; i++)
		{
			if (i == 0)
			{
				std::string sr;
				system("CLS");
				wind.gotoxy(120, 40);
				std::cout << "Wpisz nazwe gracza numer " << i + 1 << ": ";
				std::cin >> sr;
				Game::playerNamesTemp[i] = sr;
				system("CLS");
				wind.gotoxy(120, 40);
				std::cout << "Kliknij cokolwiek aby kontynuowac.";
				_getch();
				system("CLS");
				wind.gotoxy(120, 40);
				std::cin.sync();
				Sleep(500);
				continue;
			}

			std::string sr;
			system("CLS");
			wind.gotoxy(120, 40);
			std::cout << "Wpisz nazwe gracza numer " << i + 1 << ": ";
			std::cin >> sr;
			while (CheckNames(sr) == false)
			{
				system("CLS");
				wind.gotoxy(120, 40);
				std::cout << "Nazwa zajeta, kliknij cokolwiek i wpisz ponownie.";
				_getch();
				std::cin.sync();
				system("CLS");
				wind.gotoxy(120, 40);
				std::cout << "Wpisz nazwe gracza numer " << i + 1 << ": ";
				std::cin >> sr;
			}
			Game::playerNamesTemp[i] = sr;
			system("CLS");
			wind.gotoxy(120, 40);
			std::cout << "Kliknij cokolwiek aby kontynuowac.";
			_getch();
			system("CLS");
			wind.gotoxy(120, 40);
			std::cin.sync();
			Sleep(500);
		}
		system("CLS");
		wind.gotoxy(120, 40);
		std::cout << "Kliknij cokolwiek aby kontynuowac.";
		_getch();
		std::cin.sync();
		system("CLS");
		wind.gotoxy(120, 40);
		std::cout << "..Loading..";
		
	}
	
}

bool GameManager::CheckIfNear(Vector2& pos, int x)
{
	for (int h = 0; h < x; h++)
	{
		for (int i = pos.x - 15; i < pos.x + 15; i++)
		{
			for (int j = pos.y - 15; j < pos.y + 15; j++)
			{
				if (players[h].pos == Vector2(i, j))return false;
			}
		}
	}
	return true;
}

void GameManager::InitPlayers(int x, std::string name[], int colors[])
{
	for(int i = 0; i < x; i++)
	{
		if (i == 0)
		{
			Vector2 poss;
			poss.x = rand() % ((int)MainMap.size.x-1);
			poss.y = rand() % ((int)MainMap.size.y-1);
			while (MainMap.mainMap[poss.x][poss.y].name != names::plains && MainMap.mainMap[poss.x][poss.y].name != names::forest)
			{
				poss.x = rand() % ((int)MainMap.size.x-1);
				poss.y = rand() % ((int)MainMap.size.y-1);
				std::cout << "PL1:" << (MainMap.mainMap[poss.x][poss.y].name != names::plains && MainMap.mainMap[poss.x][poss.y].name != names::forest) << " ";
				Sleep(30);
			}
			
			AddPlayer(name[i], colors[i], i, poss);

			continue;
		}
		else
		{
			Vector2 poss;
			poss.x = rand() % ((int)MainMap.size.x-1);
			poss.y = rand() % ((int)MainMap.size.y-1);
			while (MainMap.mainMap[poss.x][poss.y].name != names::plains && MainMap.mainMap[poss.x][poss.y].name != names::forest && CheckIfNear(poss, i))
			{
				poss.x = rand() % ((int)MainMap.size.x-1);
				poss.y = rand() % ((int)MainMap.size.y-1);
				
			}
			AddPlayer(name[i], colors[i], i, poss);

		}
		
	}
}
