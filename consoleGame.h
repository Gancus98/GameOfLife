////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Klasa zawiera inplementacje tekstow¹ (konsolowa) gry w zycie // UWAGA klasa dziedziczy po GameEngine
//
//ZAWARTOSC:	
//
//		POLA:
//
//
//		KONSTRUKTORY:
//
//				ConsoleGame() - konstruktor bezparametrwoy
//				ConsoleGame(int width, int height) - konstruktor parametrowy tworzacy gre z mapa o podanych wymiarach
//				ConsoleGame(std::string fileName) - konstruktor parametrowy tworzacy mape na podstawie pliku tekstowego
//				ConsoleGame(const ConsoleGame& consoleGameCopy) - konstruktor kopiujacy
//
//		DESTRUKTOR:
//
//				~ConsoleGame(); - destruktor
//
//		PRZECIAZENIA OPERATOROW:
//
//				ConsoleGame& operator=(const ConsoleGame& consoleGameCopy) - przeciazony operator przypisania
//
//		METODY:
//
//				void drawMap() - nadpisana metoda ktora odpowiada za graficzna interpretacje gry na ekranie konsoli
//				void inputSetings() - nadpisana metoda ktora pozwala uzytkownikowi na wpisanie danych startowych z konsoli
//
//
//	Autor: Dawid Garnczarek
//	Data utworzenia: 28.02.2020r
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef consoleGame_h
#define consoleGame_h
#include "gameEngine.h"


class ConsoleGame : public GameEngine
{

// KONSTRUKTORY I DESTRUKTOR

public:

	ConsoleGame();
	ConsoleGame(int width, int height);
	ConsoleGame(std::string fileName);
	ConsoleGame(const ConsoleGame& consoleGameCopy);

	virtual ~ConsoleGame();

// OPERATORY:

	ConsoleGame& operator=(const ConsoleGame& consoleGameCopy);
	
// METODY:

	void drawMap();
	void inputSetings();
};

#endif