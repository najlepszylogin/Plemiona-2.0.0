#pragma once
#ifndef BONFU__
#define BONFU__
#include "GameManager.h"
#include "MapManager.h"
class GameManager;

namespace bonusFunc
{
	inline void wheatWhenMet(GameManager* mgr, Vector2 pos)
	{
		
		mgr->players[Game::currentPlayer].food += 50;
		mgr->players[Game::currentPlayer].narrator.AddInfo("Znalaz³eœ pszenice na polu ("+std::to_string((int)pos.x)+", "+std::to_string((int)pos.y)+") Twoi robotnicy zebrali plony i postanowili rozprowadziæ j¹ po okolicy. Uzyskali z niej 50 sztuk ¿ywnoœci, a ka¿de pole wokó³ pszenicy dostaje +1 do ¿yznoœci!");
		MainMap.mainMap[pos.x][pos.y].back_color = _yellow_;
		//if(Game::current_narrator_page == 0)UI::strings::narratorText.SetText(mgr->players[Game::currentPlayer].narrator.info[Game::current_narrator_page]);
		//if (mgr->players[Game::currentPlayer].narrator.read_count < mgr->players[Game::currentPlayer].narrator.read.size() - 1)UI::Lights::narrator_unread.active = true;
		//else UI::Lights::narrator_unread.active = false;

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

#endif BONFU__