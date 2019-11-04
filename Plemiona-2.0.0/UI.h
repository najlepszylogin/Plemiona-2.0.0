#pragma once
#ifndef UI_
#define UI_
#include "StringManager.h"
#include "Shapes.h"
#include "Functions.h"
#include "Player.h"
#include "GameManager.h"
#include <math.h>

namespace UI
{
	namespace blocks
	{
		inline Box frames(0, 0, 218, 74);
		inline Box settings_frames(0, 0, 218, 74,0,1);
		inline Box mapBox(3, 3, 39, 39, 1);
		inline Box menu(43, 4, 25, 37);

		inline Box exit(202, 71, 15, 2);
		inline Box save(202, 68, 15, 2);
		inline Box load(202, 65, 15, 2);
		inline Box settings(202, 62, 15, 2);
		inline Box buttonBox0(202, 59, 15, 2);
		inline Box buttonBox1(202, 56, 15, 2);
		inline Box buttonBox2(202, 53, 15, 2);
		inline Box buttonBox3(202, 50, 15, 2);
		inline Box buttonBox4(202, 47, 15, 2);
		inline Box delete_all_noti(202, 44, 15, 2);

		inline Box settings_frame(95,30,40,30,0,1);
		inline Box settings_exit(202, 71, 15, 2, 0,1);
		inline TextBox controlBox(5,43,36,6,"Nawigacja");
		inline TextBox tilePanel(5, 50, 36, 21,"Aktualne Pole");
		inline Box tileBox(6, 51, 2, 2);
		inline TextBox narratorBox(177, 1, 40, 40,"Komunikaty");
		inline Box narratorBoxControl(178, 41, 38, 2);
		inline Box tileStatus(42, 43, 36, 28);
		inline TextBox playerName(43, 1, 25, 2,"Gracz");
		inline TextBox mapSwitchBox(177, 44, 23, 20, "Widok Mapy");

		inline Box Cframes(0, 0, 218, 74,0,2);
		inline Box Csettings_frames(0, 0, 218, 74, 0, 2);
		inline Box CmapBox(3, 3, 39, 39, 1,2);
		inline Box Cmenu(43, 4, 25, 37,0,2);
		inline Box Cexit(202, 71, 15, 2,0,2);
	}
	
	namespace Lights
	{
		inline Light narrator_unread(209, 42, 3, 0, _yellow);
	}


	namespace strings
	{
		
		inline ClickableBackButton exitBtn(Vector2(208, 72), "Wyjdz", func::endGameLoop,0,_red);
		inline ClickableBackButton saveBtn(207, 69, "Zapisz", func::null, 0);
		inline ClickableBackButton loadBtn(207, 66, "Wczytaj", func::null, 0);
		inline ClickableBackButton settingsBtn(208, 63, "Opcje", func::openSettings, 0);
		
		inline ClickableBackButton exitBtnStn(208, 72, "Wyjdz", func::openMainMenu,1,_red);
		inline ClickableVarString showPosition(97, 32,mainSettings::showPos, "Pozycja Myszy: ", func::mousePosF, 1);
		inline ClickableVarString musicOn(97, 33, mainSettings::music, "Muzyka: ", func::musicF, 1);
		inline ClickableVarString soundsOn(97, 34, mainSettings::sounds, "Odglosy: ", func::soundsF, 1);
		inline PercentString musicVol(97, 35, mainSettings::musicVol, "Glosnosc Muzyki: ", 1, 15, 15);
		inline PercentString soundsVol(97, 36, mainSettings::soundsVol, "Glosnosc Odglosow: ", 1, 15, 15);
		

		inline VariableString narratorPage(200, 42,Game::current_narrator_page, "", 0, 15, _green);
		inline VariableString maxNarratorPage(202, 42, game.players[Game::currentPlayer].narrator.pages, "/", 0, 15, _white);
		inline StringBox narratorText(178, 3, 38, 38, " ", 0, 15);
		
		inline String playerName(45, 2, game.players[Game::currentPlayer].name, 0, game.players[Game::currentPlayer].color);
		inline VariableString cursorPositionx(23, 45, game.players[Game::currentPlayer].mapPos.x, "Kursor X: ", 0, 15, 15);
		inline VariableString cursorPositiony(23, 47, game.players[Game::currentPlayer].mapPos.y, "Kursor Y: ", 0, 15, 15);
	}
	//functions that using UI::strings
	inline void prevInfoF(GameManager* mgr)
	{
		if (Game::current_narrator_page > 0)
		{
			Game::current_narrator_page--;
			UI::strings::narratorText.SetText(mgr->players[Game::currentPlayer].narrator.info[Game::current_narrator_page]);
			if (mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] == false)
			{
				mgr->players[Game::currentPlayer].narrator.read_count++;
				mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] = true;
				mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] = true;
				if (mgr->players[Game::currentPlayer].narrator.read_count < mgr->players[Game::currentPlayer].narrator.read.size()-1)UI::Lights::narrator_unread.active = true;
				else UI::Lights::narrator_unread.active = false;
			}
			
		}
	}
	inline void nextInfoF(GameManager* mgr)
	{
		if (Game::current_narrator_page < mgr->players[Game::currentPlayer].narrator.info.size()-1)
		{
			Game::current_narrator_page++;
			UI::strings::narratorText.SetText(mgr->players[Game::currentPlayer].narrator.info[Game::current_narrator_page]);
			if (mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] == false)
			{
				mgr->players[Game::currentPlayer].narrator.read_count++;
				mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] = true;
				if (mgr->players[Game::currentPlayer].narrator.read_count < mgr->players[Game::currentPlayer].narrator.read.size()-1)UI::Lights::narrator_unread.active = true;
				else UI::Lights::narrator_unread.active = false;
			}
		}
	}
	inline void lastInfoF(GameManager* mgr)
	{
		if (Game::current_narrator_page < mgr->players[Game::currentPlayer].narrator.info.size() - 1)
		{
			Game::current_narrator_page = mgr->players[Game::currentPlayer].narrator.info.size()-1;
			UI::strings::narratorText.SetText(mgr->players[Game::currentPlayer].narrator.info[Game::current_narrator_page]);
			if (mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] == false)
			{
				mgr->players[Game::currentPlayer].narrator.read_count++;
				mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] = true;
				if (mgr->players[Game::currentPlayer].narrator.read_count < mgr->players[Game::currentPlayer].narrator.read.size()-1)UI::Lights::narrator_unread.active = true;
				else UI::Lights::narrator_unread.active = false;
			}
		}
	}
	inline void firstInfoF(GameManager* mgr)
	{
		Game::current_narrator_page = 0;
		UI::strings::narratorText.SetText(mgr->players[Game::currentPlayer].narrator.info[Game::current_narrator_page]);
		if (mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] == false)
		{
			mgr->players[Game::currentPlayer].narrator.read_count++;
			mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] = true;
			if (mgr->players[Game::currentPlayer].narrator.read_count < mgr->players[Game::currentPlayer].narrator.read.size()-1)UI::Lights::narrator_unread.active = true;
			else UI::Lights::narrator_unread.active = false;
		}
		
		
	}
	inline void deleteInfoF(GameManager* mgr)
	{
		if (Game::current_narrator_page == 0)
		{
			return;
		}
		else
		{
			mgr->players[Game::currentPlayer].narrator.info.erase(mgr->players[Game::currentPlayer].narrator.info.begin()+Game::current_narrator_page);
			mgr->players[Game::currentPlayer].narrator.read.erase(mgr->players[Game::currentPlayer].narrator.read.begin() + Game::current_narrator_page);
			
			mgr->players[Game::currentPlayer].narrator.read_count--;
			mgr->players[Game::currentPlayer].narrator.pages--;
			Game::current_narrator_page--;
			if (mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] == false)
			{
				mgr->players[Game::currentPlayer].narrator.read_count++;
				mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] = true;
			}
			UI::strings::narratorText.SetText(mgr->players[Game::currentPlayer].narrator.info[Game::current_narrator_page]);
			if (mgr->players[Game::currentPlayer].narrator.read_count < mgr->players[Game::currentPlayer].narrator.read.size() - 1)UI::Lights::narrator_unread.active = true;
			else UI::Lights::narrator_unread.active = false;
		}
	}

	inline void deleteAllNoti(GameManager* mgr)
	{
		Game::current_narrator_page = 0;
		mgr->players[Game::currentPlayer].narrator.Reset();
		UI::strings::narratorText.SetText(mgr->players[Game::currentPlayer].narrator.info[Game::current_narrator_page]);
		UI::Lights::narrator_unread.active = false;
	}
	inline void mainMapFunc(GameManager* mgr);
	inline void terMapFunc(GameManager* mgr);

	namespace controls
	{
		
		
		inline ClickableBackButton up(11, 45, "-NORTH-", func::up,0, _green_);
		inline ClickableBackButton down(11, 47, "-SOUTH-", func::down, 0, _green_);
		inline ClickableBackButton left(7, 46, "-WEST-", func::left, 0, _green_);
		inline ClickableBackButton right(16, 46, "-EAST-", func::right, 0, _green_);
		inline ClickableBackButton centerToCapital(14, 46,char(254),func::backToHome,0,_green_);

		inline ClickableBackButton prevInfo(180, 42, "<-----", prevInfoF, 0, _green_);
		inline ClickableBackButton nextInfo(190, 42, "----->", nextInfoF, 0, _green_);
		inline ClickableBackButton firstInfo(197, 42, "<", firstInfoF, 0, _green_);
		inline ClickableBackButton lastInfo(198, 42, ">", lastInfoF, 0, _green_);
		inline ClickableBackButton deleteInfo(214, 42, "X", deleteInfoF, 0, _red);
		inline ClickableBackButton delete_all_notBtn(203, 45, "Usun Wsz. Pow.",deleteAllNoti, 0,_red);


		inline ClickableBackButton VolAdd(126, 35, ">", func::VolumeMusicPlus, 1, _white);
		inline ClickableBackButton VolDec(125, 35, "<", func::VolumeMusicMinus, 1, _white);
		inline ClickableBackButton VolAddS(126, 36, ">", func::VolumeSoundPlus, 1, _white);
		inline ClickableBackButton VolDecS(125, 36, "<", func::VolumeSoundMinus, 1, _white);

		inline ClickableString mainMapBtn(179, 46, "Mapa Topograficzna", mainMapFunc);
		inline ClickableString terMapBtn(179, 48, "Mapa Teretorialna", terMapFunc);
	}
	inline void mainMapFunc(GameManager* mgr)
	{
		if (Game::currentMap != &UI::controls::mainMapBtn)
		{
			Game::currentMap->ChangeState();
			Game::map_type = 0;
			Game::currentMap = &UI::controls::mainMapBtn;
			Game::currentMap->ChangeState();
		}
	}
	inline void terMapFunc(GameManager* mgr)
	{
		if (Game::currentMap != &UI::controls::terMapBtn)
		{
			Game::currentMap->ChangeState();
			Game::map_type = 1;
			Game::currentMap = &UI::controls::terMapBtn;
			Game::currentMap->ChangeState();
		}
	}
}


#endif UI_
