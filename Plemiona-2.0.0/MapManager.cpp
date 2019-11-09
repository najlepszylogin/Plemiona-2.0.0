#include "MapManager.h"
#include "UI.h"
#include "BonusFuncs.h"


void MapManager::Draw(GameManager *mgr)
{
	int w=4;
	int h = 4;
	mgr->wind.gotoxy(17, 2);
	setlocale(LC_ALL, "polish");
	std::wcout << "MAPA REGIONU";
	setlocale(LC_ALL, "C");
	mgr->WriteVarString(UI::strings::cursorPositionx);
	mgr->WriteVarString(UI::strings::cursorPositiony);

	//main map
	if(Game::map_type == 0)
	for (int i = mgr->players[Game::currentPlayer].mapPos.x - 19; i < mgr->players[Game::currentPlayer].mapPos.x + 19;i++)
	{
		h = 4;
		for (int j = mgr->players[Game::currentPlayer].mapPos.y - 19; j < mgr->players[Game::currentPlayer].mapPos.y + 19; j++)
		{
			
			mgr->wind.gotoxy(w, h);

			if (j < size.y && j >= 0 && i < size.x && i >= 0 && mainMap[i][j].open[Game::currentPlayer])
			{
				//bonuses here
				if (mainMap[i][j].bonus.met == false && mainMap[i][j].bonus.name!=names::empty)mainMap[i][j].bonus.Met(mgr);



				if (currentTile->pos.x == i && currentTile->pos.y == j)
				{
					SetConsoleTextAttribute(mgr->wind.hOut, mainMap[i][j].color | _white);
					std::cout << mainMap[i][j].appearance[0];
					SetConsoleTextAttribute(mgr->wind.hOut, _white);
				}
				else
				{
					SetConsoleTextAttribute(mgr->wind.hOut, mainMap[i][j].color | mainMap[i][j].back_color);
					std::cout << mainMap[i][j].appearance[0];
					SetConsoleTextAttribute(mgr->wind.hOut, _white);
				}

			}
			else if (j == -1 || i == -1 || i == size.x || j == size.y)std::cout << "@";
			else std::cout << " ";
			h++;
		}
		w++;
	}

	//teretority map
	if (Game::map_type == 1)
	for (int i = mgr->players[Game::currentPlayer].mapPos.x - 19; i < mgr->players[Game::currentPlayer].mapPos.x + 19; i++)
	{
		h = 4;
		for (int j = mgr->players[Game::currentPlayer].mapPos.y - 19; j < mgr->players[Game::currentPlayer].mapPos.y + 19; j++)
		{
			mgr->wind.gotoxy(w, h);
			if (j < size.y && j >= 0 && i < size.x && i >= 0 && mainMap[i][j].open[Game::currentPlayer])
			{
				//bonuses here
				if (mainMap[i][j].bonus.met == false && mainMap[i][j].bonus.name != names::empty)mainMap[i][j].bonus.Met(mgr);



				if (currentTile->pos.x == i && currentTile->pos.y == j)
				{
					SetConsoleTextAttribute(mgr->wind.hOut, _black | _black);
					std::cout << mainMap[i][j].appearance[0];
					SetConsoleTextAttribute(mgr->wind.hOut, _white);
				}
				else
				{
					SetConsoleTextAttribute(mgr->wind.hOut, mainMap[i][j].owning->color | mainMap[i][j].owning->color);
					std::cout << mainMap[i][j].appearance[0];
					SetConsoleTextAttribute(mgr->wind.hOut, _white);
				}

			}
			else if (j == -1 || i == -1 || i == size.x || j == size.y)std::cout << "@";
			else std::cout << " ";
			h++;
		}
		w++;
	}

	//other maps

	if (Game::map_type == 8)
		for (int i = mgr->players[Game::currentPlayer].mapPos.x - 19; i < mgr->players[Game::currentPlayer].mapPos.x + 19; i++)
		{
			h = 4;
			for (int j = mgr->players[Game::currentPlayer].mapPos.y - 19; j < mgr->players[Game::currentPlayer].mapPos.y + 19; j++)
			{
				mgr->wind.gotoxy(w, h);
				if (j < size.y && j >= 0 && i < size.x && i >= 0 && mainMap[i][j].open[Game::currentPlayer])
				{
					//bonuses here
					if (mainMap[i][j].bonus.met == false && mainMap[i][j].bonus.name != names::empty)mainMap[i][j].bonus.Met(mgr);



					if (currentTile->pos.x == i && currentTile->pos.y == j)
					{
						SetConsoleTextAttribute(mgr->wind.hOut, _black | _black);
						std::cout << mainMap[i][j].appearance[0];
						SetConsoleTextAttribute(mgr->wind.hOut, _white);
					}
					else
					{
						if (mainMap[i][j].name != names::water && mainMap[i][j].name != names::river && mainMap[i][j].name != names::mountains)
						{
							if (mainMap[i][j].income[Game::income_type] > 0)SetConsoleTextAttribute(mgr->wind.hOut, _green | _gray);
							if (mainMap[i][j].income[Game::income_type] == 0)SetConsoleTextAttribute(mgr->wind.hOut, _white | _gray);
							if (mainMap[i][j].income[Game::income_type] < 0)SetConsoleTextAttribute(mgr->wind.hOut, _red | _gray);
						}
						else
						{
							if (mainMap[i][j].name != names::water && mainMap[i][j].name != names::river)
							{
								if (mainMap[i][j].income[Game::income_type] > 0)SetConsoleTextAttribute(mgr->wind.hOut, 123);
								if (mainMap[i][j].income[Game::income_type] == 0)SetConsoleTextAttribute(mgr->wind.hOut, 128);
								if (mainMap[i][j].income[Game::income_type] < 0)SetConsoleTextAttribute(mgr->wind.hOut, 125);
							}
							else
							{
								if (mainMap[i][j].income[Game::income_type] > 0)SetConsoleTextAttribute(mgr->wind.hOut, 59);
								if (mainMap[i][j].income[Game::income_type] == 0)SetConsoleTextAttribute(mgr->wind.hOut, 56);
								if (mainMap[i][j].income[Game::income_type] < 0)SetConsoleTextAttribute(mgr->wind.hOut, 61);
							}
							
						}
						
						std::cout << std::abs(mainMap[i][j].income[Game::income_type]);
						SetConsoleTextAttribute(mgr->wind.hOut, _white);
					}

				}
				else if (j == -1 || i == -1 || i == size.x || j == size.y)std::cout << "@";
				else std::cout << " ";
				h++;
			}
			w++;
		}

	
	if (highlighted)
	{
		
		mgr->wind.gotoxy(7, 52);
		SetConsoleTextAttribute(mgr->wind.hOut, currentTile->color | currentTile->back_color);
		std::cout << currentTile->appearance[0];
		SetConsoleTextAttribute(mgr->wind.hOut, _white);
		setlocale(LC_ALL, "polish");
		mgr->wind.gotoxy(10, 52);
		std::cout << "Nazwa: " << currentTile->name << "     ";
		mgr->wind.gotoxy(10, 53);
		std::cout <<"x: "<< currentTile->pos.x << "     ";
		mgr->wind.gotoxy(10, 54);
		std::cout <<"y: "<< currentTile->pos.y << "     ";
		mgr->wind.gotoxy(10, 55);
		if(currentTile->owning == nullptr)std::cout << "Nale¿noœæ: Nikt" << "     ";
		else
		std::cout << "Nale¿noœæ: " << currentTile->owning->name << "     ";
		mgr->wind.gotoxy(10, 56);
		if (currentTile->bonus.name == names::empty)std::cout << "Bonus: Brak" << "              ";
		else
			std::cout << "Bonus: " << currentTile->bonus.name << "            ";
		mgr->wind.gotoxy(10, 57);
		std::cout << "----------------";
		mgr->wind.gotoxy(10, 58);
		std::cout << "Urodzaj: " << currentTile->soil << "    ";
		mgr->wind.gotoxy(10, 59);
		std::cout << "Koszt Przejœcia: " << currentTile->travelCost << "   ";


		//nd box
		mgr->wind.gotoxy(45, 44);
		std::cout << "Przychód";


		setlocale(LC_ALL, "C");
	}

}

void MapManager::DrawTest(GameManager* mgr)
{
	int w = 0;
	int h = 0;
	for (int i = 5; i < 80; i++)
	{
		
		h = 0;
		for (int j = 5; j <75; j++)
		{
			
			mgr->wind.gotoxy(w, h);
			SetConsoleTextAttribute(mgr->wind.hOut, mainMap[i][j].color);
			std::cout << mainMap[i][j].appearance[0];
			SetConsoleTextAttribute(mgr->wind.hOut, _white);
			h++;
		}
		w++;
	}
}



void MapManager::LoadMap(std::string filename)
{
	if(!mainmapimage.loadFromFile("Assets/"+filename))std::cout << "Map not loaded";
	
	size.x = mainmapimage.getSize().x;
	size.y = mainmapimage.getSize().y;

	for (int i = 0; i <= size.x; i++)
	{
		std::vector<Tile> row;
		mainMap.push_back(row);

		for (int j = 0; j <= size.y; j++)
		{
			Tile* buff = new Tile(_green, names::plains, Vector2(i, j), &map::grassch);
			mainMap[i].push_back(*buff);
			
			delete buff;
		}
	}

	mainMap[size.x][size.y].Reset(_black, "Brak", Vector2(size.x, size.y), &map::null, 0);

	std::cout << "Map loaded";
	std::cout << size.x << "/" << size.y;

	//reading colors from bitmap//
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++)
		{
			
			if (mainmapimage.getPixel(i, j) == (map::grass))
			{
				mainMap[i][j].Reset(_green, names::plains, Vector2(i, j), &map::grassch);
				//mainMap[i][j].income[income_::gold]++;
				continue;
			}
			if (mainmapimage.getPixel(i, j) == map::river)
			{

				mainMap[i][j].Reset(_laz, names::river, Vector2(i, j), &map::riverch);
				continue;
			}
			if (mainmapimage.getPixel(i, j) == map::mountain)
			{

				mainMap[i][j].Reset(_white_, names::mountains, Vector2(i, j), &map::mountainch, BACKGROUND_GREEN);
				continue;
			}
			if (mainmapimage.getPixel(i, j) == map::water)
			{
				mainMap[i][j].Reset(_laz, names::water, Vector2(i, j), &map::waterch);
				continue;
			}

		}
	}

	//forest generator 1//
	for (int i = 0; i < mapSettings::forestSeeds; i++)
	{
		Vector2 los;
		do{
			los.x = rand() % (int)size.x;
			los.y = rand() % (int)size.y;
		} while(mainMap[los.x][los.y].name != names::plains);
		mainMap[los.x][los.y].Reset(_green_, names::forest, Vector2(los.x,los.y), &map::forestch);
	}

	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++)
		{

			int count_of_forest = CheckNeigh(names::forest,names::forest,Vector2(i,j));
			int grass_chance = 100;
			
			if (count_of_forest == 1)grass_chance = 50;
			if (count_of_forest > 1)grass_chance = 40;
			if (count_of_forest > 3)grass_chance = 3;

			int rande;
			rande = rand() % 100;
			if (rande > grass_chance && mainMap[i][j].name == names::plains)mainMap[i][j].Reset(_green_, names::forest, Vector2(i, j), &map::forestch);

		}
	}

	//forest generation 2//
	for (int i = 0; i < mapSettings::forestSeeds*3; i++)
	{
		Vector2 los;
		do {
			los.x = rand() % (int)size.x;
			los.y = rand() % (int)size.y;
		} while (mainMap[los.x][los.y].name != names::plains);
		mainMap[los.x][los.y].Reset(_green_, names::forest, Vector2(los.x, los.y), &map::forestch);
	}

	//adding bonus tiles//
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++)
		{
			if (mainMap[i][j].name == names::plains)
				if (rand() % 100 > 97)
				{
					mainMap[i][j].bonus = BonusTile(bonusFunc::wheatWhenMet, bonusFunc::wheatPerTurn, names::additionals::wheat, Vector2(i, j));
					mainMap[i][j].appearance = &map::riverch;
				}
		}
	}

	//remaping soil and travel cost lvl//
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++)
		{
			if (mainMap[i][j].name == names::forest || mainMap[i][j].name == names::mountains)
			{
				mainMap[i][j].soil -= 1;
				mainMap[i][j].travelCost += 2;
			}
			if (mainMap[i][j].name == names::mountains)mainMap[i][j].travelCost = map::maxTravelCost;
			if (mainMap[i][j].name == names::water || mainMap[i][j].name == names::river)
			{
				mainMap[i][j].soil -= 1;
				mainMap[i][j].travelCost += 3;
			}
		}
	}
	
	system("CLS");
	currentTile = &mainMap[size.x][size.y];
	//std::cout << size.x << "/" << size.y;
	//_getch();
}


int MapManager::CheckNeigh(std::string input, std::string checking, Vector2 pos)
{
	int a=0;
	for (int i = pos.x - 1; i <= pos.x + 1; i++)
	{
		for (int j = pos.y - 1; j <= pos.y + 1; j++)
		{
			if (i < 0 || j < 0 || i >= size.x || j >= size.y)continue;
			if (i == pos.x && j == pos.y)continue;
			else
				if (mainMap[i][j].name == input)a++;
		}
	}
	return a;
}

