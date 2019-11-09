
#include "GameManager.h"
#include "UI.h"



int main()
{
	
	game.LoadEngine();
	std::cout << " - Game Loaded";
	system("CLS");

	//this only works here
	game.wind.Init();


	//debug news
	game.players[Game::currentPlayer].narrator.AddInfo("Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.");
	game.players[Game::currentPlayer].narrator.AddInfo("Dostałeś 200 sztuk drewna gościu!");
	game.players[Game::currentPlayer].narrator.AddInfo("Dostałeś 200 sztuk złota gościu!");
	UI::strings::narratorText.SetText(game.players[Game::currentPlayer].narrator.info[0]);
	
	

	//
	game.DrawAllBoxes();
	game.UpdateMap();
	RedrawAll(&game);
	do
	{
		game.Update2();
		game.UpdateTime();

	
		//game.wind.gotoxy(100, 50);
		//std::cout << game.music.calmSongsCount;

		game.updateSheme = game.Update();
		
			
		if (game.updateSheme == 2)
			game.UpdateMap();
		if (game.updateSheme == 1)
		{
			game.CheckAllBtns();
			game.DrawAllItems();
			game.DrawAllStr();

			game.music.PlaySong(2);
			game.wind.cls();
		}
		
			
		

	} while (Game::e == 0);
	
	system("CLS");
	std::cout << "Zakonczono program\n\n";

}
