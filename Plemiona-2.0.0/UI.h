#pragma once
#ifndef UI_
#define UI_

#include "Linker.h"
#include "GameManager.h"
#include "Functions.h"

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
		inline Box incomeMapBox(177, 68, 23, 2);
		inline TextBox mapSwitchBox(177, 44, 23, 29, "Widok Mapy");
		inline Box times(69, 1, 100, 2);
		inline TextBox currentIncomeBox(177, 71, 23, 2, "Mapa Przychodu");

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
		
		inline ClickableBackButton exitBtn(Vector2(208, 72), "Wyjd�", func::endGameLoop,0,_red);
		inline ClickableBackButton saveBtn(207, 69, "Zapisz", func::null, 0);
		inline ClickableBackButton loadBtn(207, 66, "Wczytaj", func::null, 0);
		inline ClickableBackButton settingsBtn(208, 63, "Opcje", func::openSettings, 0);
		
		inline ClickableBackButton exitBtnStn(208, 72, "Wyjd�", func::openMainMenu,1,_red);
		inline ClickableVarString showPosition(97, 32,mainSettings::showPos, "Pozycja Myszy: ", func::mousePosF, 1);
		inline ClickableVarString musicOn(97, 33, mainSettings::music, "Muzyka: ", func::musicF, 1);
		inline ClickableVarString soundsOn(97, 34, mainSettings::sounds, "Odg�osy: ", func::soundsF, 1);
		inline PercentString musicVol(97, 35, mainSettings::musicVol, "G�o�no�� Muzyki: ", 1, 15, 15);
		inline PercentString soundsVol(97, 36, mainSettings::soundsVol, "G�o�no�� Odg�os�w: ", 1, 15, 15);
		

		inline VariableString narratorPage(200, 42,Game::current_narrator_page, "", 0, 15, _green);
		inline VariableString maxNarratorPage(202, 42, game.players[Game::currentPlayer].narrator.pages, "/", 0, 15, _white);
		inline StringBox narratorText(178, 3, 38, 38, " ", 0, 15);
		inline VariableString turn(156, 2, Game::turn, "Tura: ", 0, _gray, _gray);
		
		inline String playerName(46, 2, game.players[Game::currentPlayer].name, 0, game.players[Game::currentPlayer].color);
		inline VariableString cursorPositionx(23, 45, game.players[Game::currentPlayer].mapPos.x, "Kursor X: ", 0, 15, 15);
		inline VariableString cursorPositiony(23, 47, game.players[Game::currentPlayer].mapPos.y, "Kursor Y: ", 0, 15, 15);

		
	}
	//functions that using UI::strings
	inline void prevInfoF(GameManager* mgr);
	inline void nextInfoF(GameManager* mgr);
	inline void lastInfoF(GameManager* mgr);
	inline void firstInfoF(GameManager* mgr);
	inline void deleteInfoF(GameManager* mgr);
	inline void deleteAllNoti(GameManager* mgr);
	
	inline void mainMapFunc(GameManager* mgr);
	inline void terMapFunc(GameManager* mgr);
	inline void IncomeMapF(GameManager* mgr);

	inline void goldIncomeF(GameManager* mgr);
	inline void woodIncomeF(GameManager* mgr);
	inline void stoneIncomeF(GameManager* mgr);
	inline void foodIncomeF(GameManager* mgr);
	inline void ironIncomeF(GameManager* mgr);
	inline void productionIncomeF(GameManager* mgr);
	inline void luxuryIncomeF(GameManager* mgr);
	inline void faithIncomeF(GameManager* mgr);
	inline void knowledgeIncomeF(GameManager* mgr);

	namespace controls
	{
		
		
		inline ClickableBackButton up(11, 45, "-NORTH-", func::up,0, _green_);
		inline ClickableBackButton down(11, 47, "-SOUTH-", func::down, 0, _green_);
		inline ClickableBackButton left(7, 46, "-WEST-", func::left, 0, _green_);
		inline ClickableBackButton right(16, 46, "-EAST-", func::right, 0, _green_);
		inline Button centerToCapital(14, 46,char(254),func::backToHome,0,_green_);

		inline ClickableBackButton prevInfo(180, 42, "<-----", prevInfoF, 0, _green_);
		inline ClickableBackButton nextInfo(190, 42, "----->", nextInfoF, 0, _green_);
		inline ClickableBackButton firstInfo(197, 42, "<", firstInfoF, 0, _green_);
		inline ClickableBackButton lastInfo(198, 42, ">", lastInfoF, 0, _green_);
		inline ClickableBackButton deleteInfo(214, 42, "X", deleteInfoF, 0, _red);
		inline ClickableBackButton delete_all_notBtn(203, 45, "Usu� Wsz. Pow.",deleteAllNoti, 0,_red);


		inline ClickableBackButton VolAdd(126, 35, ">", func::VolumeMusicPlus, 1, _white);
		inline ClickableBackButton VolDec(125, 35, "<", func::VolumeMusicMinus, 1, _white);
		inline ClickableBackButton VolAddS(126, 36, ">", func::VolumeSoundPlus, 1, _white);
		inline ClickableBackButton VolDecS(125, 36, "<", func::VolumeSoundMinus, 1, _white);

		inline ClickableString mainMapBtn(179, 46, "Mapa Topograficzna", mainMapFunc);
		inline ClickableString terMapBtn(179, 48, "Mapa Teretorialna", terMapFunc);
		inline ClickableString regMapBtn(179, 50, "Mapa Region�w", func::null);
		inline ClickableString gmMapBtn(179, 52, "Mapa Gmin", func::null);
		inline ClickableString roadMapBtn(179, 54, "Mapa Dr�g", func::null);
		inline ClickableString militMapBtn(179, 56, "Mapa Militarna", func::null);
		inline ClickableString popMapBtn(179, 58, "Mapa Ludno�ci", func::null);
		inline ClickableString citiesMapBtn(179, 60, "Mapa Miast", func::null);
		inline ClickableString incomeMapBtn(179, 68, "Mapy Przychod�w", IncomeMapF);
		
		inline Button goldIncome(179, 69, 'Z', goldIncomeF,0,_yellow_);
		inline Button woodIncome(181, 69, 'D', woodIncomeF,0,_green_);
		inline Button stoneIncome(183, 69, 'K', stoneIncomeF,0,_gray);
		inline ClickableBackButton ironIncome(185, 69, '�', ironIncomeF,0,_white_);
		inline ClickableBackButton foodIncome(187, 69, '�', foodIncomeF,0,_yellow);
		inline Button productionIncome(189, 69, 'P', productionIncomeF,0,_blue_);
		inline Button luxIncome(191, 69, 'L', luxuryIncomeF,0,_yellow_);
		inline Button faithIncome(193, 69, 'W', faithIncomeF,0,_white);
		inline Button knowledgeIncome(195, 69, 'N',knowledgeIncomeF, 0, _laz);
		inline String incomeMapType(180, 72, "",0,_pink);
	}
	inline void IncomeMapF(GameManager* mgr)
	{
		if (Game::currentMap != &UI::controls::incomeMapBtn)
		{
			mgr->sound.Play(sound::menuhud);
			Game::currentMap->ChangeState();
			Game::map_type = 8;
			Game::income_type = 0;
			Game::currentMap = &UI::controls::incomeMapBtn;
			Game::currentMap->ChangeState();
			UI::controls::incomeMapType.SetText("Z�oto               ");
			mgr->UpdateMap();
		}
	}
	inline void mainMapFunc(GameManager* mgr)
	{
		if (Game::currentMap != &UI::controls::mainMapBtn)
		{
			mgr->sound.Play(sound::menuhud);
			Game::currentMap->ChangeState();
			Game::map_type = 0;
			Game::currentMap = &UI::controls::mainMapBtn;
			Game::currentMap->ChangeState();
			UI::controls::incomeMapType.SetText("                    ");
			mgr->UpdateMap();
		}
	}
	inline void terMapFunc(GameManager* mgr)
	{
		if (Game::currentMap != &UI::controls::terMapBtn)
		{
			mgr->sound.Play(sound::menuhud);
			Game::currentMap->ChangeState();
			Game::map_type = 1;
			Game::currentMap = &UI::controls::terMapBtn;
			Game::currentMap->ChangeState();
			UI::controls::incomeMapType.SetText("                    ");
			mgr->UpdateMap();
		}
	}
	inline void prevInfoF(GameManager* mgr)
	{
		if (Game::current_narrator_page > 0)
		{
			Game::current_narrator_page--;
			mgr->sound.Play(sound::page[rand()%3]);
			UI::strings::narratorText.SetText(mgr->players[Game::currentPlayer].narrator.info[Game::current_narrator_page]);
			if (mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] == false)
			{
				mgr->players[Game::currentPlayer].narrator.read_count++;
				mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] = true;
				mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] = true;
				if (mgr->players[Game::currentPlayer].narrator.read_count < mgr->players[Game::currentPlayer].narrator.read.size() - 1)UI::Lights::narrator_unread.active = true;
				else UI::Lights::narrator_unread.active = false;
			}

		}
	}
	inline void nextInfoF(GameManager* mgr)
	{
		if (Game::current_narrator_page < mgr->players[Game::currentPlayer].narrator.info.size() - 1)
		{
			mgr->sound.Play(sound::page[rand() % 3]);
			Game::current_narrator_page++;
			UI::strings::narratorText.SetText(mgr->players[Game::currentPlayer].narrator.info[Game::current_narrator_page]);
			if (mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] == false)
			{
				mgr->players[Game::currentPlayer].narrator.read_count++;
				mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] = true;
				if (mgr->players[Game::currentPlayer].narrator.read_count < mgr->players[Game::currentPlayer].narrator.read.size() - 1)UI::Lights::narrator_unread.active = true;
				else UI::Lights::narrator_unread.active = false;
			}
		}
	}
	inline void lastInfoF(GameManager* mgr)
	{
		if (Game::current_narrator_page < mgr->players[Game::currentPlayer].narrator.info.size() - 1)
		{
			mgr->sound.Play(sound::page[rand() % 3]);
			Game::current_narrator_page = mgr->players[Game::currentPlayer].narrator.info.size() - 1;
			UI::strings::narratorText.SetText(mgr->players[Game::currentPlayer].narrator.info[Game::current_narrator_page]);
			if (mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] == false)
			{
				mgr->players[Game::currentPlayer].narrator.read_count++;
				mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] = true;
				if (mgr->players[Game::currentPlayer].narrator.read_count < mgr->players[Game::currentPlayer].narrator.read.size() - 1)UI::Lights::narrator_unread.active = true;
				else UI::Lights::narrator_unread.active = false;
			}
		}
	}
	inline void firstInfoF(GameManager* mgr)
	{
		Game::current_narrator_page = 0;
		mgr->sound.Play(sound::page[rand() % 3]);
		UI::strings::narratorText.SetText(mgr->players[Game::currentPlayer].narrator.info[Game::current_narrator_page]);
		if (mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] == false)
		{
			mgr->players[Game::currentPlayer].narrator.read_count++;
			mgr->players[Game::currentPlayer].narrator.read[Game::current_narrator_page] = true;
			if (mgr->players[Game::currentPlayer].narrator.read_count < mgr->players[Game::currentPlayer].narrator.read.size() - 1)UI::Lights::narrator_unread.active = true;
			else UI::Lights::narrator_unread.active = false;
		}


	}
	inline void deleteInfoF(GameManager * mgr)
	{
		if (Game::current_narrator_page == 0)
		{
			return;
		}
		else
		{
			mgr->sound.Play(sound::page[rand() % 3]);
			mgr->players[Game::currentPlayer].narrator.info.erase(mgr->players[Game::currentPlayer].narrator.info.begin() + Game::current_narrator_page);
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

	inline void deleteAllNoti(GameManager * mgr)
	{
		mgr->sound.Play(sound::page[rand() % 3]);
		Game::current_narrator_page = 0;
		mgr->players[Game::currentPlayer].narrator.Reset();
		UI::strings::narratorText.SetText(mgr->players[Game::currentPlayer].narrator.info[Game::current_narrator_page]);
		UI::Lights::narrator_unread.active = false;
	}
	inline void goldIncomeF(GameManager* mgr)
	{
		if (Game::map_type == 8)
		{
			mgr->sound.Play(sound::menuhud);
			Game::income_type = 0;
			UI::controls::incomeMapType.SetText("Z�oto               ");
			mgr->UpdateMap();
		}
	}
	inline void woodIncomeF(GameManager* mgr)
	{
		if (Game::map_type == 8)
		{
			mgr->sound.Play(sound::menuhud);
			Game::income_type = 1;
			UI::controls::incomeMapType.SetText("Drewno              ");
			mgr->UpdateMap();
		}
	}
	inline void stoneIncomeF(GameManager* mgr)
	{
		if (Game::map_type == 8)
		{
			mgr->sound.Play(sound::menuhud);
			Game::income_type = 2;
			UI::controls::incomeMapType.SetText("Kamie�              ");
			mgr->UpdateMap();
		}
	}
	inline void ironIncomeF(GameManager* mgr)
	{
		if (Game::map_type == 8)
		{
			mgr->sound.Play(sound::menuhud);
			Game::income_type = 3;
			UI::controls::incomeMapType.SetText("�elazo              ");
			mgr->UpdateMap();
		}
	}
	inline void foodIncomeF(GameManager* mgr)
	{
		if (Game::map_type == 8)
		{
			mgr->sound.Play(sound::menuhud);
			Game::income_type = 4;
			UI::controls::incomeMapType.SetText("�ywno��             ");
			mgr->UpdateMap();
		}
	}
	inline void productionIncomeF(GameManager* mgr)
	{
		if (Game::map_type == 8)
		{
			mgr->sound.Play(sound::menuhud);
			Game::income_type = 5;
			UI::controls::incomeMapType.SetText("Produkcja           ");
			mgr->UpdateMap();
		}
	}
	inline void luxuryIncomeF(GameManager* mgr)
	{
		if (Game::map_type == 8)
		{
			mgr->sound.Play(sound::menuhud);
			Game::income_type = 6;
			UI::controls::incomeMapType.SetText("Tow. Luksusowe      ");
			mgr->UpdateMap();
		}
	}
	inline void faithIncomeF(GameManager* mgr)
	{
		if (Game::map_type == 8)
		{
			mgr->sound.Play(sound::menuhud);
			Game::income_type = 7;
			UI::controls::incomeMapType.SetText("Wiara               ");
			mgr->UpdateMap();
		}
	}
	inline void knowledgeIncomeF(GameManager* mgr)
	{
		if (Game::map_type == 8)
		{
			mgr->sound.Play(sound::menuhud);
			Game::income_type = 8;
			UI::controls::incomeMapType.SetText("Nauka               ");
			mgr->UpdateMap();
		}
	}

}


#endif UI_
