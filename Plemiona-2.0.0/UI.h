#pragma once
#ifndef UI_
#define UI_
#include "StringManager.h"
#include "Shapes.h"
#include "Functions.h"
#include "Player.h"


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
	}
	namespace strings
	{
		
		inline ClickableBackButton exitBtn(Vector2(208, 72), "Wyjdz", func::endGameLoop,0,_red);
		inline ClickableBackButton saveBtn(207, 69, "Zapisz", func::null, 0);
		inline ClickableBackButton loadBtn(206, 66, "Wczytaj", func::null, 0);
		inline ClickableBackButton settingsBtn(208, 63, "Opcje", func::openSettings, 0);
		inline ClickableBackButton exitBtnStn(208, 72, "Wyjdz", func::openMainMenu,1,_red);
		inline ClickableVarString showPosition(97, 32,mainSettings::showPos, "Pozycja Myszy: ", func::mousePosF, 1);

		
	}
	namespace controls
	{
		
		
		inline ClickableBackButton up(11, 45, "-NORTH-", func::up,0, _green_);
		inline ClickableBackButton down(11, 47, "-SOUTH-", func::down, 0, _green_);
		inline ClickableBackButton left(7, 46, "-WEST-", func::left, 0, _green_);
		inline ClickableBackButton right(16, 46, "-EAST-", func::right, 0, _green_);
		inline ClickableBackButton centerToCapital(14, 46,char(254),func::backToHome,0,_green_);
	}
}


#endif UI_
