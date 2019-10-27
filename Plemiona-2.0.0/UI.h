#pragma once
#ifndef UI_
#define UI_
#include "StringManager.h"
#include "Shapes.h"
#include "Functions.h"
#include "Player.h"
#include "GameManager.h"


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
		inline Box settings_frame(95,30,40,30,0,1);
		inline Box settings_exit(202, 71, 15, 2, 0,1);
		inline Box controlBox(5,43,36,6);
		inline Box tilePanel(5, 50, 36, 13);
		inline Box tileBox(6, 51, 2, 2);
		inline Box narratorBox(177, 1, 40, 40);
		inline Box narratorBoxControl(178, 41, 38, 2);
	}


	namespace strings
	{
		
		inline ClickableBackButton exitBtn(Vector2(208, 72), "Wyjdz", func::endGameLoop,0,_red);
		inline ClickableBackButton saveBtn(207, 69, "Zapisz", func::null, 0);
		inline ClickableBackButton loadBtn(206, 66, "Wczytaj", func::null, 0);
		inline ClickableBackButton settingsBtn(208, 63, "Opcje", func::openSettings, 0);
		inline ClickableBackButton exitBtnStn(208, 72, "Wyjdz", func::openMainMenu,1,_red);
		inline ClickableVarString showPosition(97, 32,mainSettings::showPos, "Pozycja Myszy: ", func::mousePosF, 1);
		inline ClickableVarString musicOn(97, 33, mainSettings::music, "Muzyka: ", func::musicF, 1);
		inline ClickableVarString soundsOn(97, 34, mainSettings::sounds, "Odglosy: ", func::soundsF, 1);

		inline VariableString narratorPage(200, 42,Game::current_narrator_page, "", 0, 15, _green);
		inline VariableString maxNarratorPage(202, 42, game.players[Game::currentPlayer].narrator.pages, "/", 0, 15, _white);
		inline StringBox narratorText(178, 2, 38, 38, " ", 0, 15);
		
		
	}
	//functions that using UI::strings
	inline void prevInfo(GameManager* mgr)
	{
		if (Game::current_narrator_page > 0)
		{
			Game::current_narrator_page--;
			UI::strings::narratorText.SetText(mgr->players[Game::currentPlayer].narrator.info[Game::current_narrator_page]);
		}
	}
	inline void nextInfo(GameManager* mgr)
	{
		if (Game::current_narrator_page < mgr->players[Game::currentPlayer].narrator.info.size()-1)
		{
			Game::current_narrator_page++;
			UI::strings::narratorText.SetText(mgr->players[Game::currentPlayer].narrator.info[Game::current_narrator_page]);
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
			mgr->players[Game::currentPlayer].narrator.pages--;
			Game::current_narrator_page--;
			UI::strings::narratorText.SetText(mgr->players[Game::currentPlayer].narrator.info[Game::current_narrator_page]);
		}
	}

	namespace controls
	{
		
		
		inline ClickableBackButton up(11, 45, "-NORTH-", func::up,0, _green_);
		inline ClickableBackButton down(11, 47, "-SOUTH-", func::down, 0, _green_);
		inline ClickableBackButton left(7, 46, "-WEST-", func::left, 0, _green_);
		inline ClickableBackButton right(16, 46, "-EAST-", func::right, 0, _green_);
		inline ClickableBackButton centerToCapital(14, 46,char(254),func::backToHome,0,_green_);

		inline ClickableBackButton prevInfo(180, 42, "<-----", prevInfo, 0, _green_);
		inline ClickableBackButton nextInfo(190, 42, "----->", nextInfo, 0, _green_);
		inline ClickableBackButton deleteInfo(214, 42, "X", deleteInfoF, 0, _red);
	}
}


#endif UI_
