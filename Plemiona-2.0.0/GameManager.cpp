#include "GameManager.h"
#include "MapManager.h"
#include "AssetLoaders.h"
#include "UI.h"

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
	
	LoadMusic();
	LoadSounds();
	ChangeVolume(mainSettings::musicVol);
	ChangeSoundVolume(mainSettings::soundsVol);
	inGameTime.Restart();
	date.Set(10, 10, 1000);
	
	system("CLS");
	std::cout << "Engine Loaded";
	//other loader
	UI::strings::maxNarratorPage.var = &game.players[Game::currentPlayer].narrator.pages;
	UI::strings::cursorPositionx.var = &game.players[Game::currentPlayer].mapPos.x;
	UI::strings::cursorPositiony.var = &game.players[Game::currentPlayer].mapPos.y;

	Game::currentMap = &UI::controls::mainMapBtn;
	Game::currentMap->ChangeState();
	UI::mainMapFunc(this);
	
}

void GameManager::DrawTst()
{
	MainMap.DrawTest(this);
}

GameManager::GameManager()
{
	LoadEngine();
	std::cout << "loaded";
}

void GameManager::DrawTime()
{
	if (Game::menu == 0 || Game::menu == 2)
	{
		wind.gotoxy(71, 2);
		SetConsoleTextAttribute(wind.hOut, _gray);
		std::cout << "Czas w grze: " << inGameTime;
		SetConsoleTextAttribute(wind.hOut, _white);
	}
	
}



bool GameManager::UpdateTime()
{

		SetConsoleTextAttribute(wind.hOut, _gray);
		wind.gotoxy(71, 2);
		if (Game::inGameTime.getElapsedTime().asSeconds() <= 60 && (Game::menu == 0 || Game::menu == 2))std::cout << "Czas w grze: 00:00";
		else
			if (seconds.getElapsedTime().asSeconds() >= 60)
			{
				DrawTime();
				seconds.restart();
				SetConsoleTextAttribute(wind.hOut, _white);
				return true;
			}
			else
			{
				DrawTime();
				SetConsoleTextAttribute(wind.hOut, _white);
				return false;
			}

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

void GameManager::DrawTextBox(TextBox& shape)
{
	wind.gotoxy(shape.pos.x, shape.pos.y);
	SetConsoleTextAttribute(wind.hOut, shape.color);

	if (shape.menu == Game::menu)
	{
		wind.gotoxy(shape.pos.x, shape.pos.y);
		std::cout << char(201);
		wind.gotoxy(shape.pos.x + shape.size.x, shape.pos.y + shape.size.y);
		std::cout << char(188);
		wind.gotoxy(shape.pos.x, shape.pos.y + shape.size.y);
		std::cout << char(200);
		wind.gotoxy(shape.pos.x + shape.size.x, shape.pos.y);
		std::cout << char(187);
		for (int i = 1; i < shape.size.x; i++)
		{
			wind.gotoxy(shape.pos.x + i, shape.pos.y);
			std::cout << char(205);
		}
		for (int i = 1; i < shape.size.x; i++)
		{
			wind.gotoxy(shape.pos.x + i, shape.pos.y + shape.size.y);
			std::cout << char(205);
		}
		for (int i = 1; i < shape.size.y; i++)
		{
			wind.gotoxy(shape.pos.x, shape.pos.y + i);
			std::cout << char(186);
		}
		for (int i = 1; i < shape.size.y; i++)
		{
			wind.gotoxy(shape.pos.x + shape.size.x, shape.pos.y + i);
			std::cout << char(186);
		}

		wind.gotoxy(shape.pos.x + 2, shape.pos.y);
		std::cout << shape.text;
	}
		

}

void GameManager::DrawLight(Light& lg)
{
	if (lg.menu == Game::menu)
	{
		wind.gotoxy(lg.pos);

		if (lg.active == true)
		{
			SetConsoleTextAttribute(wind.hOut, lg.color);
			for (int i = 0; i < lg.size; i++)std::cout << char(176);
			std::cout << " ";
		}
		else
		{
			SetConsoleTextAttribute(wind.hOut, _gray);
			for (int i = 0; i < lg.size; i++)std::cout << char(176);
			std::cout << " ";
		}

	}
}

void GameManager::DrawButton(Button& btn)
{
	if (btn.menu == Game::menu)
	{
		SetConsoleTextAttribute(wind.hOut, btn.color);
		wind.gotoxy(btn.pos);
		std::cout << btn.str;
		SetConsoleTextAttribute(wind.hOut, _white);
	}
}

void GameManager::WriteString(String& str)
{
	if (str.menu == Game::menu)
	{
		setlocale(LC_ALL, "polish");
		SetConsoleTextAttribute(wind.hOut, str.color);
		wind.gotoxy(str.pos);
		std::cout << str.str;
		SetConsoleTextAttribute(wind.hOut, _white);
		setlocale(LC_ALL, "C");
	}
}
void GameManager::WriteString(ClickableString& str)
{
	if (str.menu == Game::menu)
	{
		setlocale(LC_ALL, "polish");
		SetConsoleTextAttribute(wind.hOut, str.color);
		wind.gotoxy(str.pos);
		std::cout << str.str;
		SetConsoleTextAttribute(wind.hOut, _white);
		setlocale(LC_ALL, "C");
	}
}
void GameManager::WriteString(ClickableBackButton& str)
{
	if (str.menu == Game::menu)
	{
		setlocale(LC_ALL, "polish");
		SetConsoleTextAttribute(wind.hOut, str.color);
		wind.gotoxy(str.pos);
		std::cout << str.str;
		SetConsoleTextAttribute(wind.hOut, _white);
		setlocale(LC_ALL, "C");
	}
}
void GameManager::WriteString(Vector2& pos, std::string& str, int color)
{
	setlocale(LC_ALL, "polish");
	SetConsoleTextAttribute(wind.hOut, color);
	wind.gotoxy(pos);
	std::cout << str;
	SetConsoleTextAttribute(wind.hOut, _white);
	setlocale(LC_ALL, "C");
}

void GameManager::WriteString(StringBox& str)
{
	if (str.menu == Game::menu)
	{
		setlocale(LC_ALL, "polish");
		SetConsoleTextAttribute(wind.hOut, str.color);
		wind.gotoxy(str.pos);
		int h = 0;

		for (int i = 0; i < str.size.y; i++)
		{
			for (int j = 0; j <= str.size.x; j++) {
				if (j == str.size.x && str.str[h] != ' ' && h < str.str.size())
				{
					int g=0;
					while (str.str[h] != ' ')
					{
						
						wind.gotoxy(str.pos.x+str.size.x-g-1, str.pos.y + i);
						g++;
						std::cout << ' ';
						h--;
					}
					wind.gotoxy(str.pos.x, str.pos.y + i + 1);
					break;
				}


				if (h < str.str.size())
				{

					cout << str.str[h];
					h++;
				}
				else
					std::cout << ' ';

					
			}
			wind.gotoxy(str.pos.x, str.pos.y + i + 1);
		}
		SetConsoleTextAttribute(wind.hOut, _white);
		setlocale(LC_ALL, "C");
	}
}
void GameManager::WriteString(Vector2& pos, Vector2& size, std::string& str, int color)
{
		setlocale(LC_ALL, "polish");
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
		setlocale(LC_ALL, "C");
}

void GameManager::WriteVarString(VariableString& str)
{
	if (str.menu == Game::menu)
	{
		setlocale(LC_ALL, "polish");
		SetConsoleTextAttribute(wind.hOut, str.color);
		wind.gotoxy(str.pos);
		std::cout << str.str;
		SetConsoleTextAttribute(wind.hOut, str.color2);
		std::cout << *str.var<<"    ";
		SetConsoleTextAttribute(wind.hOut, _white);
		setlocale(LC_ALL, "C");
	}
}

void GameManager::WriteVarString(ClickableVarString& str)
{
	if (str.menu == Game::menu)
	{
		setlocale(LC_ALL, "polish");
		SetConsoleTextAttribute(wind.hOut, str.color);
		wind.gotoxy(str.pos);
		std::cout << str.str;
		SetConsoleTextAttribute(wind.hOut, str.color2);
		std::cout << *str.var << "    ";;
		SetConsoleTextAttribute(wind.hOut, _white);
		setlocale(LC_ALL, "C");
	}

}
void GameManager::WriteVarString(PercentString& str)
{
	if (str.menu == Game::menu)
	{
		setlocale(LC_ALL, "polish");
		SetConsoleTextAttribute(wind.hOut, str.color);
		wind.gotoxy(str.pos);
		std::cout << str.str;
		SetConsoleTextAttribute(wind.hOut, str.color2);
		std::cout << *str.var << "%    ";
		SetConsoleTextAttribute(wind.hOut, _white);
		setlocale(LC_ALL, "C");
	}
}

void GameManager::DrawProgressBar(ProgressBar& bar)
{
	if (bar.menu == Game::menu)
	{
		wind.gotoxy(bar.pos);
		for (int i = 0; i < bar.size; i++)
		{
			if (*bar.var > (i * bar.div))
			{
				SetConsoleTextAttribute(wind.hOut, _green);
				std::cout << char(176);
				SetConsoleTextAttribute(wind.hOut, _white);
			}
			else
			{
				SetConsoleTextAttribute(wind.hOut, _gray);
				std::cout << char(176);
				SetConsoleTextAttribute(wind.hOut, _white);
			}
		}
	}
}



int GameManager::Update()
{
	if (Game::menu == 0 || Game::menu == 2)
	{
		SetConsoleTextAttribute(wind.hOut, _white);
		wind.gotoxy(100, 2);
		setlocale(LC_ALL, "polish");
		std::cout << date;
		if(Game::season == names::winter)SetConsoleTextAttribute(wind.hOut, _laz);
		if(Game::season == names::spring)SetConsoleTextAttribute(wind.hOut, _green);
		if(Game::season == names::summer)SetConsoleTextAttribute(wind.hOut, _yellow);
		if(Game::season == names::autumn)SetConsoleTextAttribute(wind.hOut, _yellow_);
		wind.gotoxy(130, 2);
		std::cout << Game::season << "      ";
		SetConsoleTextAttribute(wind.hOut, _white);

		setlocale(LC_ALL, "C");
	}
	
	
		

	ReadConsoleInput(wind.hin, &wind.InputRecord, 1, &wind.Events);
	wind.gotoxy(0, 0);
	if (wind.InputRecord.Event.MouseEvent.dwButtonState != FROM_LEFT_1ST_BUTTON_PRESSED)wind.mouseState = 0;

		if (wind.InputRecord.EventType == MOUSE_EVENT && wind.mouseState == 0)
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
				
				if (MainMap.currentTile != &MainMap.mainMap[MouseToMapPos(Vector2(wind.coord.X, wind.coord.Y)).x][MouseToMapPos(Vector2(wind.coord.X, wind.coord.Y)).y] && Game::menu == 0)
				{
					MainMap.currentTile = &MainMap.mainMap[MouseToMapPos(Vector2(wind.coord.X, wind.coord.Y)).x][MouseToMapPos(Vector2(wind.coord.X, wind.coord.Y)).y];
					MainMap.Highlight();
					wind.mouseState = 1;
					return 2;
				}
				
				FlushConsoleInputBuffer(wind.hin);
				return 1;
			}
			if (wind.InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED && Game::menu == 0)
			{
				MainMap.Unlight();
				MainMap.currentTile = &MainMap.mainMap[MainMap.size.x][MainMap.size.y];
				system("CLS");
				wind.Init();
				RedrawAll(this);
				if (mainSettings::showPos)
				{
					wind.gotoxy(1, 73);
					std::cout << GetMousePos() << "        ";
					
				}
				FlushConsoleInputBuffer(wind.hin);
				return 2;
			}
		}
		if (wind.InputRecord.EventType == KEY_EVENT && wind.InputRecord.Event.KeyEvent.bKeyDown == false && Game::menu == 0)
		{
			if (wind.InputRecord.Event.KeyEvent.uChar.AsciiChar == 'w' && players[Game::currentPlayer].mapPos.y > 4)players[Game::currentPlayer].mapPos.y-=4;
			if (wind.InputRecord.Event.KeyEvent.uChar.AsciiChar == 'a' && players[Game::currentPlayer].mapPos.x > 4)players[Game::currentPlayer].mapPos.x-=4;
			if (wind.InputRecord.Event.KeyEvent.uChar.AsciiChar == 's' && players[Game::currentPlayer].mapPos.y < MainMap.size.y - 4)players[Game::currentPlayer].mapPos.y+=4;
			if (wind.InputRecord.Event.KeyEvent.uChar.AsciiChar == 'd' && players[Game::currentPlayer].mapPos.x < MainMap.size.x - 4)players[Game::currentPlayer].mapPos.x+=4;
			if (wind.InputRecord.Event.KeyEvent.uChar.AsciiChar == 'q')
			{
				date.AddTime(5);
				//for (int i = MouseToMapPos(Vector2(wind.coord.X, wind.coord.Y)).x - 2; i <= MouseToMapPos(Vector2(wind.coord.X, wind.coord.Y)).x + 2; i++)
				//	for (int j = MouseToMapPos(Vector2(wind.coord.X, wind.coord.Y)).y - 2; j <= MouseToMapPos(Vector2(wind.coord.X, wind.coord.Y)).y + 2; j++)MainMap.mainMap[i][j].owning = &players[Game::currentPlayer];
			}
			DrawAllItems();
			DrawAllStr();
			FlushConsoleInputBuffer(wind.hin);
			return 2;
		}
		FlushConsoleInputBuffer(wind.hin);
		return 0;

}

Vector2 GameManager::GetMousePos()
{
	//ReadConsoleInput(wind.hin, &wind.InputRecord, 1, &wind.Events);
	return Vector2(wind.InputRecord.Event.MouseEvent.dwMousePosition.X, wind.InputRecord.Event.MouseEvent.dwMousePosition.Y);

}

bool GameManager::CheckBtn(ClickableString& str)
{
	if (str.menu == Game::menu)
	{
		if (MouseClickPos.x >= str.pos.x && MouseClickPos.y >= str.pos.y && MouseClickPos.x < (str.str.size() + str.pos.x) && MouseClickPos.y <= str.pos.y)
		{
			//str.ChangeState();
			MouseClickPos.x = 0;
			MouseClickPos.y = 0;
			sound.Play(sound::click);
			return true;

		}
		//str.Reset();
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
			sound.Play(sound::click);
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
			sound.Play(sound::click);
			return true;
		}
		str.Reset();
		return false;
	}
	return false;
}

bool GameManager::CheckBtn(Button& btn)
{
	if (btn.menu == Game::menu)
	{
		if (MouseClickPos.x >= btn.pos.x && MouseClickPos.y >= btn.pos.y && MouseClickPos.x < (1 + btn.pos.x) && MouseClickPos.y <= btn.pos.y)
		{
			btn.ChangeState();
			MouseClickPos.x = 0;
			MouseClickPos.y = 0;
			sound.Play(sound::click);
			return true;
		}
		btn.Reset();
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
		for (int i = 0; i < PercentString::variablestrings.size(); i++)WriteVarString(*PercentString::variablestrings[i]);
		for (int i = 0; i < Button::buttons.size(); i++)DrawButton(*Button::buttons[i]);
}

void GameManager::DrawAllBoxes()
{
	for (int i = 0; i < TextBox::boxes.size(); i++)DrawTextBox(*TextBox::boxes[i]);
	for (int i = 0; i < Box::boxes.size(); i++)DrawRect(*Box::boxes[i]);
	
}

void GameManager::DrawAllItems()
{
	for (int i = 0; i < ProgressBar::bars.size(); i++)DrawProgressBar(*ProgressBar::bars[i]);
	for (int i = 0; i < Light::lights.size(); i++)DrawLight(*Light::lights[i]);
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
	for (int i = 0; i < Button::buttons.size(); i++)
	if (CheckBtn(*Button::buttons[i]))
	{
		Button::buttons[i]->Action(this);
		buttonsTimer.restart();
		DrawAllStr();
	}
	
}

void GameManager::UpdateMap()
{
	setlocale(LC_ALL, "C");
	MainMap.Draw(this);
}

bool GameManager::CheckClickedBtns()
{
	for (int i = 0; i < ClickableBackButton::clickablestrings.size(); i++)if (ClickableBackButton::clickablestrings[i]->clicked == true)
	{
		ClickableBackButton::clickablestrings[i]->ChangeState();
		return true;
	}
	for (int i = 0; i < Button::buttons.size(); i++)if (Button::buttons[i]->clicked == true)
	{
		Button::buttons[i]->ChangeState();
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

void GameManager::OpenDialogBox(DialogBoxC& box)
{
	Game::dialogBoxOpened = true;
	currentDialogBox = &box;
}

void GameManager::CloseDialogBox()
{
	Game::dialogBoxOpened = false;
	currentDialogBox = nullptr;
}

void GameManager::DrawDialogBox()
{
	DrawRect(50, 50, 50, 40, 1, _gray);
	wind.gotoxy(51,54);
	int h = 0;

	for (int i = 0; i < 90; i++)
	{
		for (int j = 0; j <= 99; j++) {
			if (j == 99 && currentDialogBox->str[h] != ' ' && h < currentDialogBox->str.size())
			{
				int g = 0;
				while (currentDialogBox->str[h] != ' ')
				{

					wind.gotoxy(currentDialogBox->pos.x + currentDialogBox->size.x - g - 1, currentDialogBox->pos.y + i);
					g++;
					std::cout << ' ';
					h--;
				}
				wind.gotoxy(currentDialogBox->pos.x, currentDialogBox->pos.y + i + 1);
				break;
			}
			if (h < currentDialogBox->str.size())
			{
				cout << currentDialogBox->str[h];
				h++;
			}
			else
				std::cout << ' ';
		}
		wind.gotoxy(currentDialogBox->pos.x, currentDialogBox->pos.y + i + 1);
	}
	SetConsoleTextAttribute(wind.hOut, _white);
	
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

Vector2 GameManager::MouseToMapPos(Vector2 pos)
{
	if (pos.x > 3 && pos.y > 3 && pos.x < 42 && pos.y < 42 && players[Game::currentPlayer].mapPos.x + MouseClickPos.x - 23 >= 0 && players[Game::currentPlayer].mapPos.x + MouseClickPos.x - 23 < MainMap.size.x && players[Game::currentPlayer].mapPos.y + MouseClickPos.y - 23 >= 0 && players[Game::currentPlayer].mapPos.y + MouseClickPos.y - 23 < MainMap.size.y)
	{
		if(MainMap.mainMap[players[Game::currentPlayer].mapPos.x + MouseClickPos.x - 23][players[Game::currentPlayer].mapPos.y + MouseClickPos.y - 23].open[Game::currentPlayer])
		return Vector2(players[Game::currentPlayer].mapPos.x + MouseClickPos.x - 23, players[Game::currentPlayer].mapPos.y + MouseClickPos.y - 23);
		else return MainMap.currentTile->pos;
	}
	else return MainMap.currentTile->pos;
	
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
			MainMap.currentTile = &MainMap.mainMap[poss.x][poss.y];
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

void GameManager::NextPlayer()
{
	Game::current_narrator_page = 0;
	
	if (Game::currentPlayer == playersSettings::playersNum)Game::currentPlayer = 0;
	else Game::currentPlayer++;
	//there is need to switch shown text that depends on Game::currentPlayer
	UI::strings::narratorText.SetText(players[Game::currentPlayer].narrator.info[0]);
	UI::strings::maxNarratorPage.var = &game.players[Game::currentPlayer].narrator.pages;
	UI::strings::cursorPositionx.var = &game.players[Game::currentPlayer].mapPos.x;
	UI::strings::cursorPositiony.var = &game.players[Game::currentPlayer].mapPos.y;
	Game::currentMap = &UI::controls::mainMapBtn;
	Game::currentMap->ChangeState();
	UI::mainMapFunc(this);
}
