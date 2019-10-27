#pragma once
#pragma warning

#ifndef GAMEMGR_
#define GAMEMGR_

#include "WorkManager.h"
#include "MapManager.h"
#include "Defines.h"
#include "Player.h"
#include "VariableManager.h"
#include "SettingsManager.h"
#include "Names.h"





static class GameManager
{

	
public:

	GameManager();

	Window wind;
	sf::Clock buttonsTimer;
	std::vector<Player> players;
	

	void LoadEngine();
	void InitPlayers(int x, std::string name[], int colors[]);
	void AddPlayer(std::string name, int color, int id, Vector2 pos);
	void AddPlayer(Player& pl);

	//drawing////////////////////////////////////////////////
	void DrawRect(int x, int y, int width, int height, int type = 0, int color = _white);
	void DrawRect(Vector2& position, Vector2& size, int type = 0, int color = _white);
	void DrawRect(Box& shape);
	void WriteString(String& str);
	void WriteString(ClickableString& str);
	void WriteString(Vector2& pos, std::string& str, int color = _white);
	void WriteString(StringBox& str);
	void WriteString(Vector2& pos, Vector2& size, std::string& str, int color = _white);
	void WriteString(ClickableBackButton& str);
	void WriteVarString(VariableString& str);
	void WriteVarString(ClickableVarString& str);
	void DrawAllStr();
	void DrawAllBoxes();

	//updates - important//
	bool Update();
	bool Update2();
	void UpdateMap();
	void DrawTst();

	//chaecking cuttons//
	void CheckAllBtns();
	bool CheckClickedBtns();
	bool CheckBtn(ClickableString& str);
	bool CheckBtn(ClickableVarString& str);
	bool CheckBtn(ClickableBackButton& str);

	//checking players
	bool CheckIfNear(Vector2& pos, int x);

	//playersUtil
	void AskForNames();
	bool CheckNames(std::string& str);

	//utility
	Vector2 GetMousePos();
	Vector2 MouseToMapPos(Vector2 pos);
	Vector2 MouseClickPos;
	
	//mechanics
	void NextPlayer();
	void NextTurn();
};

inline GameManager game;

inline VariableString cursorPositionx(23, 45, game.players[Game::currentPlayer].mapPos.x, "Kursor X: ", 0, 15, 15);
inline VariableString cursorPositiony(23, 47, game.players[Game::currentPlayer].mapPos.y, "Kursor Y: ", 0, 15,15);

inline void RedrawAll(GameManager* mgr)
{
	mgr->DrawAllBoxes();
	mgr->DrawAllStr();
}


#endif GAMEMGR_