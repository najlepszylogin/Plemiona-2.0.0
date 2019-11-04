#pragma once
#pragma warning

#ifndef GAMEMGR_
#define GAMEMGR_

#include "WorkManager.h"
#include "MapManager.h"
#include "Defines.h"
#include "Player.h"
#include "City.h"
#include "VariableManager.h"
#include "SettingsManager.h"
#include "Names.h"
#include "MusicManager.h"
#include "SoundManager.h"




static class GameManager
{

	
public:

	GameManager();

	Window wind;
	MusicManager music;
	
	sf::Clock buttonsTimer;
	std::vector<Player> players;
	sf::Clock MusicTime;

	void LoadEngine();
	void InitPlayers(int x, std::string name[], int colors[]);
	void AddPlayer(std::string name, int color, int id, Vector2 pos);
	void AddPlayer(Player& pl);

	//drawing////////////////////////////////////////////////
	void DrawRect(int x, int y, int width, int height, int type = 0, int color = _white);
	void DrawRect(Vector2& position, Vector2& size, int type = 0, int color = _white);
	void DrawRect(Box& shape);
	void DrawTextBox(TextBox& shape);
	void DrawProgressBar(ProgressBar& bar);
	void WriteString(String& str);
	void WriteString(ClickableString& str);
	void WriteString(Vector2& pos, std::string& str, int color = _white);
	void WriteString(StringBox& str);
	void WriteString(Vector2& pos, Vector2& size, std::string& str, int color = _white);
	void WriteString(ClickableBackButton& str);
	void WriteVarString(VariableString& str);
	void WriteVarString(PercentString& str);
	void WriteVarString(ClickableVarString& str);
	void DrawAllStr();
	void DrawAllBoxes();
	void DrawLight(Light& lg);
	void DrawAllItems();
	
	
	//info and dialog boxes
	void OpenDialogBox(DialogBoxC& box);
	void CloseDialogBox();
	void DrawDialogBox();
	DialogBoxC* currentDialogBox;

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

	//sounds and music
	sf::Music songs[20];
	sf::Sound sounds[200];
	void ChangeVolume(double& vol) { for (int i = 0; i < 20; i++)songs[i].setVolume(vol); };
};

inline GameManager game;



inline void RedrawAll(GameManager* mgr)
{
	mgr->DrawAllBoxes();
	mgr->DrawAllStr();
}


#endif GAMEMGR_