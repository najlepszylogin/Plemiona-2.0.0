#pragma once
#include "GameManager.h"

namespace bonusFunc
{
	inline void wheatWhenMet(GameManager* mgr, Vector2 pos)
	{
		mgr->players[Game::currentPlayer].food += 50;
		mgr->players[Game::currentPlayer].narrator.AddInfo("Znalazles pszenice na polu ("+std::to_string((int)pos.x)+", "+std::to_string((int)pos.y)+") Twoi robotnicy wydobyli z niego 50 sztuk zywnosci oraz kazde pole wokol pszenicy dostaje +1 do zywznosci!");
		MainMap.mainMap[pos.x][pos.y].back_color = _yellow_;
		for (int i = pos.x - 1; i <= pos.x + 1; i++)
		{
			for (int j = pos.y - 1; j <= pos.y + 1; j++)
			{
				if (i < 0 || j < 0)continue;
				else if(MainMap.mainMap[i][j].name == names::plains || MainMap.mainMap[i][j].name == names::forest)
					MainMap.mainMap[i][j].soil += 2;
			}
		}
		
	}
	inline void wheatPerTurn(GameManager * mgr, Vector2 pos)
	{
		MainMap.mainMap[pos.x][pos.y].owning->food += 5;
		
	}

	
}
