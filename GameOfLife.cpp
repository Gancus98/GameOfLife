////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Autor: Dawid Garnczarek
//	Data utworzenia: 28.02.2020r
//
//
//
//	INSTURKCJA URUCHOMIENIA GRY W ŻYCIE
//
//	1.Aby zagrac należy utworzyć obiekt ConsoleGame w parametrze nalezy podac sciezke dostepu do pliku 		->		ConsoleGame game("gameMap.txt");
//	2.Kolejnym krokiem jest już uruchomienie metody play() ktora uruchamia nasza gre						->		game.gameLoop();
//
//
//	Standard zapisu pliku:
//	W pierwszej lini podajemy szerokosc i wysokosc a w kolejnych liniach kolejne wiersze wypełnione 0-brak zycia 1-zycie np.
//	3 4
//	0 0 1
//  0 1 1
//  1 0 0
//  0 0 0
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "consoleGame.h"

int main()
{
	GameEngine* game;
	game = new ConsoleGame("gameMap.txt");  
	game->play();

	return 0;
}
