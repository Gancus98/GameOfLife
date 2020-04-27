////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Klasa zawiera pola oraz metody pozwalajace na gre w ¿ycie zawiera w sobie plansze na ktorej odbywaja sie przeksztalcenia
//
//ZAWARTOSC:	
//
//		POLA:
//
//				CellMatrix map - pole przechowuje aktualna plansze na ktorej odbywa sie gra
//				std::vector<short> whenNewCell - przechowuje wartosci dla ktorych ma rodziæ sie nowa komorka
//				std::vector<short> whenNoChange - przechowuje wartosci dla ktorych ma nie nastepowac rzadna zmiana
//				std::vector<short> whenCellDie - przechowuje wartosci dla ktorych komorka ma umierac
//
//		KONSTRUKTORY:
//
//				GameEngine() - bezparametrowy konstruktor inicjalizujacy wszystkie pola zerami
//				GameEngine(int width, int height) - konstruktor tworzacy mape o okreslonej wielksci
//				GameEngine(const GameEngine& gameEngineCopy) - konstruktor kopiujacy
//
//		DESTRUKTOR:
//
//				virtual ~GameEngine(); - virtualny destruktor
//
//		PRZECIAZENIA OPERATOROW:
//
//				GameEngine& operator=(const GameEngine& gameEngineCopy) - przeciazony operator przypisania
//				friend std::ostream& operator<<(std::ostream& out, const GameEngine& gameEngineCopy) - przeciazony operator strumienia pozwala wyswietlic aktualne parametry gry
//
//		METODY:
//
//				virtual void drawMap() = 0 - czysto wirtualna metoda ktorej poszczegolne inplementacje maja odpowiadac za wyswietlanie gry
//				virtual void inputSetings() - czysto wirtualna metoda odpowiadajaca za wprowadzanie parametrow wejsciowych gry (kiedy ma umieraæ/kiedy ma siê rodziæ/kiedy bez zmian)
//
//				void play() - glowna petla w ktorej odbywa sie gra
//				void calculate() - metoda obliczajaca kolejne stany i zapisujaca je do mapy
//				int numberOfFriends(int i, int j) - metoda zlicza liczbe ¿ywych dooko³a komórek (i, j to wspolrzedne komorki dla ktorej liczymy przyjaciol)
//
//		METODY PRYWATNE:
//
//				CellMatrix& getMap() - metoda pozwalajaca pobrac mape
//				std::vector<short>& getWhenNewCell() - metoda pozwalajaca pobrac wartosci kiedy ma rodzic sie komorka
//				std::vector<short>& getWhenNoChange() - metoda pozwalajaca probrac wartosci kiedy ma nie nastepowac zmiana
//				std::vector<short>& getWhenCellDie()- metoda pozwalajaca pobrac wartosci kiedy ma umierac komorka
//
//				void setMap(const CellMatrix& copy) - metoda pozwalajaca na ustawienie mapy
//				void setWhenNewCell(const std::vector<short>& copy) - metoda pozwalajaca na ustawienie wartosci kiedy komorka ma sie rodzic
//				void setWhenNoChange(const std::vector<short>& copy) - metoda pozwalajca na ustwaienie wartosci kiedy komorka ma sie nie zmieniac
//				void setWhenCellDie(const std::vector<short>& copy) -metoda pozwalacjca na ustawienie wartosci kiedy komorka ma umierac
//
//
//	Autor: Dawid Garnczarek
//	Data utworzenia: 28.02.2020r
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef gameEngine_h
#define gameEngine_h
#include "cellMatrix.h"
#include <Windows.h>
#include <vector>
#include <fstream>

class GameEngine
{

	// POLA

	protected:

		CellMatrix map;
		std::vector<short> whenNewCell = {3};
		std::vector<short> whenNoChange = {2};
		std::vector<short> whenCellDie = {0,1,4,5,6,7,8};

	// KONSTRUKTORY I DESTRUKTOR

	public:

		GameEngine();
		GameEngine(int width, int height);
		GameEngine(std::string fileName);
		GameEngine(const GameEngine& gameEngineCopy);

		virtual ~GameEngine();

	// OPERATORY

		GameEngine& operator=(const GameEngine& gameEngineCopy);
		friend std::ostream& operator<<(std::ostream& out, const GameEngine& gameEngineCopy);

	// METODY

		virtual void drawMap() = 0;
		virtual void inputSetings() = 0;
		void play();
		void calculate();
		

	private:

		CellMatrix& getMap();
		std::vector<short>& getWhenNewCell();
		std::vector<short>& getWhenNoChange();
		std::vector<short>& getWhenCellDie();

		void setMap(const CellMatrix& copy);
		void setWhenNewCell(const std::vector<short>& copy);
		void setWhenNoChange(const std::vector<short>& copy);
		void setWhenCellDie(const std::vector<short>& copy);

		int numberOfFriends(int i, int j);
};

#endif