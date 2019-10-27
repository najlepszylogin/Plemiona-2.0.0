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
	
	
	std::cout << " - Game Loaded";
	system("CLS");

	//this only works here
	game.wind.Init();


	//debug news
	game.players[Game::currentPlayer].narrator.AddInfo("Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.");
	game.players[Game::currentPlayer].narrator.AddInfo("Dostales 200 sztuk drewna gosciu!");
	game.players[Game::currentPlayer].narrator.AddInfo("Dostales 200 sztuk kamienia gosciu!");
	UI::strings::narratorText.SetText(game.players[Game::currentPlayer].narrator.info[0]);
	//


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
			game.wind.cls();
			
		}

	} while (Game::e == 0);
	
	system("CLS");
	std::cout << "Zakonczono program\n\n";

}
