#pragma once
#pragma warning

#ifndef GAMEMGR_
#define GAMEMGR_




#include "Linker.h"
#include "WindowManager.h"
#include "MusicManager.h"
#include "Player.h"
#include "TimeManager.h"
#include "Vector2.h"


static class GameManager
{

	
public:

	GameManager();

	Window wind;
	MusicManager music;
	SoundManager sound;
	sf::Clock buttonsTimer;
	std::vector<Player> players;
	sf::Clock MusicTime;
	sf::Clock seconds;
	Time inGameTime;
	Date date;
	int updateSheme = 0;

	
	

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
	void DrawButton(Button& btn);
	void DrawAllStr();
	void DrawAllBoxes();
	void DrawLight(Light& lg);
	void DrawAllItems();
	void DrawTime();
	
	
	//info and dialog boxes
	void OpenDialogBox(DialogBoxC& box);
	void CloseDialogBox();
	void DrawDialogBox();
	DialogBoxC* currentDialogBox;

	//updates - important//
	int Update();
	bool Update2();
	void UpdateMap();
	void DrawTst();
	bool UpdateTime();

	//chaecking buttons//
	void CheckAllBtns();
	bool CheckClickedBtns();
	bool CheckBtn(ClickableString& str);
	bool CheckBtn(ClickableVarString& str);
	bool CheckBtn(ClickableBackButton& str);
	bool CheckBtn(Button& btn);

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
	
	void ChangeVolume(double& vol) { for (int i = 0; i < 20; i++)songs[i].setVolume(vol); };
	void ChangeSoundVolume(double& vol) { for (int i = 0; i < sound.sounds.size(); i++)sound.sounds[i]->setVolume(vol); };
};

inline GameManager game;




inline void RedrawAll(GameManager* mgr)
{
	mgr->DrawAllBoxes();
	mgr->DrawAllStr();
}


#endif GAMEMGR_