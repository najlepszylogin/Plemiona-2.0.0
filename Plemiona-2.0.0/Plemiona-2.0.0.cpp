#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "WindowManager.h"
#include "GameManager.h"
#include "UI.h"
#include "SettingsManager.h"
#include "Names.h"
#include "VariableManager.h"




int main()
{
	
	game.LoadEngine();
	std::cout << " - Game Loaded";
	system("CLS");

	//this only works here
	game.wind.Init();


	do
	{
		game.Update2();

		if (game.Update())
		{
			game.CheckAllBtns();
			game.DrawAllBoxes();
			game.DrawAllStr();
			if (Game::menu == 0)
				game.UpdateMap();
			//game.DrawTst();
			game.wind.cls();
		}
		
		


	} while (Game::e == 0);
	
	system("CLS");
	std::cout << "Zakonczono program\n\n";


}
