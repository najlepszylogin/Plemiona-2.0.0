#include "MapManager.h"

void CapitalMap::GenerateMap()
{
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
	//mountains generator
	if (mountains == 1)
	{
		for (int i = 0; i < size.x; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				mainMap[i][j].Reset(_white_, names::mountains, Vector2(i, j), &map::mountainch, BACKGROUND_GREEN);
			}
			for(int j=6;j<rand()%4;j++)mainMap[i][j].Reset(_white_, names::mountains, Vector2(i, j), &map::mountainch, BACKGROUND_GREEN);
		}
	}
	if (mountains == 2)
	{
		for (int j = 0; j < size.y; j++)
		{
			for (int i = size.x; i > size.x-6; i--)
			{
				mainMap[i][j].Reset(_white_, names::mountains, Vector2(i, j), &map::mountainch, BACKGROUND_GREEN);
			}
			for (int i = size.x - 6; i > size.x-rand() % 4; i--)mainMap[i][j].Reset(_white_, names::mountains, Vector2(i, j), &map::mountainch, BACKGROUND_GREEN);
		}
	}
	if (mountains == 3)
	{
		for (int i = 0; i < size.x; i++)
		{
			for (int j = size.y; j > size.y - 6; j--)
			{
				mainMap[i][j].Reset(_white_, names::mountains, Vector2(i, j), &map::mountainch, BACKGROUND_GREEN);
			}
			for (int j = size.y - 6; j > size.y - rand() % 4; j--)mainMap[i][j].Reset(_white_, names::mountains, Vector2(i, j), &map::mountainch, BACKGROUND_GREEN);
		}
	}
	if (mountains == 4)
	{
		for (int j = 0; j < size.y; j++)
		{
			for (int i = 0; i < 6; i++)
			{
				mainMap[i][j].Reset(_white_, names::mountains, Vector2(i, j), &map::mountainch, BACKGROUND_GREEN);
			}
			for (int i = 6; i < rand() % 4; i++)mainMap[i][j].Reset(_white_, names::mountains, Vector2(i, j), &map::mountainch, BACKGROUND_GREEN);
		}
	}
	//water generator
	if (water == 1)
	{
		for (int i = 0; i < size.x; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				mainMap[i][j].Reset(_laz, names::water, Vector2(i, j), &map::waterch);
			}
			for (int j = 6; j < rand() % 4; j++)mainMap[i][j].Reset(_laz, names::water, Vector2(i, j), &map::waterch);
		}
	}
		if (water == 2)
		{
		for (int j = 0; j < size.y; j++)
		{
			for (int i = size.x; i > size.x - 6; i--)
			{
				mainMap[i][j].Reset(_laz, names::water, Vector2(i, j), &map::waterch);
			}
			for (int i = size.x - 6; i > size.x - rand() % 4; i--)mainMap[i][j].Reset(_laz, names::water, Vector2(i, j), &map::waterch);

		}
		}
		if (water == 3)
		{
			for (int i = 0; i < size.x; i++)
			{
				for (int j = size.y; j > size.y - 6; j--)
				{
					mainMap[i][j].Reset(_laz, names::water, Vector2(i, j), &map::waterch);
				}
				for (int j = size.y - 6; j > size.y - rand() % 4; j--)mainMap[i][j].Reset(_laz, names::water, Vector2(i, j), &map::waterch);
			}
		}
		if (water == 4)
		{
			for (int j = 0; j < size.y; j++)
			{
				for (int i = 0; i < 6; i++)
				{
					mainMap[i][j].Reset(_laz, names::water, Vector2(i, j), &map::waterch);
				}
				for (int i = 6; i < rand() % 4; i++)mainMap[i][j].Reset(_laz, names::water, Vector2(i, j), &map::waterch);
			}
		}




		for (int i = 0; i < rand() % 100; i++)
		{
			Vector2 los;
			do {
				los.x = rand() % (int)size.x;
				los.y = rand() % (int)size.y;
			} while (mainMap[los.x][los.y].name != names::plains);
			mainMap[los.x][los.y].Reset(_green_, names::bush, Vector2(los.x, los.y), &map::forestch);
		}

		for (int i = 0; i < rand() % 50; i++)
		{
			Vector2 los;
			do {
				los.x = rand() % (int)size.x;
				los.y = rand() % (int)size.y;
			} while (mainMap[los.x][los.y].name != names::plains);
			mainMap[los.x][los.y].Reset(_gray, names::stone, Vector2(los.x, los.y), &map::grassch);
		}
	}

void CapitalMap::Draw(GameManager *mgr)
{
	int w = 4;
	int h = 4;
	for (int i = mgr->players[Game::currentPlayer].capitalMapPos.x - 19; i < mgr->players[Game::currentPlayer].capitalMapPos.x + 19; i++)
	{
		h = 4;

		for (int j = mgr->players[Game::currentPlayer].capitalMapPos.y - 19; j < mgr->players[Game::currentPlayer].capitalMapPos.y + 19; j++)
		{
			mgr->wind.gotoxy(w, h);

			if (j < size.y && j >= 0 && i < size.x && i >= 0 && mainMap[i][j].open[Game::currentPlayer])
			{

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
	if (highlighted)
	{
		mgr->wind.gotoxy(7, 52);
		SetConsoleTextAttribute(mgr->wind.hOut, currentTile->color | currentTile->back_color);
		std::cout << currentTile->appearance[0];
		SetConsoleTextAttribute(mgr->wind.hOut, _white);
		mgr->wind.gotoxy(10, 52);
		std::cout << "Nazwa: " << currentTile->name << "     ";
		mgr->wind.gotoxy(10, 53);
		std::cout << "x: " << currentTile->pos.x << "     ";
		mgr->wind.gotoxy(10, 54);
		std::cout << "y: " << currentTile->pos.y << "     ";

	}
}