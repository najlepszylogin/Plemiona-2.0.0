#include "MapManager.h"


void MapManager::Draw(GameManager *mgr)
{
	int w=4;
	int h = 4;
	for (int i = mgr->players[Game::currentPlayer].mapPos.x - 19; i < mgr->players[Game::currentPlayer].mapPos.x + 19;i++)
	{
		h = 4;
		for (int j = mgr->players[Game::currentPlayer].mapPos.y - 19; j < mgr->players[Game::currentPlayer].mapPos.y + 19; j++)
		{
			mgr->wind.gotoxy(w, h);
			if (j < size.y && j >= 0 && i < size.x && i >= 0)
			{
				SetConsoleTextAttribute(mgr->wind.hOut, mainMap[i][j].color);
				std::cout << mainMap[i][j].appearance[0];
				SetConsoleTextAttribute(mgr->wind.hOut, _white);
			}
			else if (j == -1 || i == -1 || i == size.x || j == size.y)std::cout << "@";
			else std::cout << " ";
			h++;
		}
		w++;
	}
}

void MapManager::DrawTest(GameManager* mgr)
{
	int w = 0;
	int h = 0;
	for (int i = 5; i < 60; i++)
	{
		
		h = 0;
		for (int j = 5; j < 60; j++)
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

	for (int i = 0; i < size.x; i++)
	{
		std::vector<Tile> row;
		mainMap.push_back(row);

		for (int j = 0; j < size.y; j++)
		{
			Tile* buff = new Tile(_green, names::plains, Vector2(i, j), &map::grassch);
			mainMap[i].push_back(*buff);
			delete buff;
		}
	}

	std::cout << "Map loaded";
	std::cout << size.x << "/" << size.y;


	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++)
		{
			
			if (mainmapimage.getPixel(i, j) == (map::grass))
			{
				int rande;
				rande = rand() % 2;
				if (rande == 1)mainMap[i][j].Reset(_green_, names::forest, Vector2(i, j), &map::forestch);
				else
					mainMap[i][j].Reset(_green, names::plains, Vector2(i, j), &map::grassch);
				continue;
			}
			if (mainmapimage.getPixel(i, j) == map::river)
			{

				mainMap[i][j].Reset(_laz, names::river, Vector2(i, j), &map::riverch);
				continue;
			}
			if (mainmapimage.getPixel(i, j) == map::mountain)
			{

				mainMap[i][j].Reset(_gray, names::mountains, Vector2(i, j), &map::mountainch);
				continue;
			}
			if (mainmapimage.getPixel(i, j) == map::water)
			{
				mainMap[i][j].Reset(_laz_, names::water, Vector2(i, j), &map::waterch);
				continue;
			}

		}
	}
	system("CLS");

}