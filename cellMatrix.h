////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Klasa zawiera pola oraz metody reprezentujace nasz¹ tabelê/plansze gry
//
//ZAWARTOSC:	
//
//		POLA:
//
//				int mapWidth - pole przechowujace szerokosc (ilsc komorek w pojedynczym wierszu tablicy)
//				int mapHeight - pole przechowywujace wysokosc (ilosc komorek w pojedynczej kolumnie)
//				SingleCell** matrix - jest to dwu wymiarowa tablica bedaca odwzorowaniem naszej planszy
//
//		KONSTRUKTORY:
//
//				CellMatrix() - konstruktor bezparametrowy tworzacy wskaznik pusty na tablice oraz inicjujacy wysokosc i szerokosc zerami
//				CellMatrix(int mapWidth, int mapHeight) - konstruktor przyjmujacy rozmiary mapy ktora domyslnie wypelniana jest zerami
//				CellMatrix(const CellMatrix& cellMatrixCopy) - konstruktor kopiujacy mapy
//
//		DESTRUKTOR:
//
//				virtual ~CellMatrix() - virtualny destruktor
//
//		PRZECIAZENIA OPERATOROW:
//
//				CellMatrix& operator=(const CellMatrix& cellMatrixCopy) - przeciazony operator przypisania
//				friend std::ostream& operator<<(std::ostream& out, const CellMatrix& cellMatrixCopy) - przeciazony operator strumienia wyswietla na konsole nasza plansze
//
//		METODY:
//
//				void setMapWidth(int width) - pozwala ustawic szerokosc mapy
//				void setMapHeight(int height) pozwala ustawic wysokosc mapy
//				void setSingleCell(int x, int y, bool state) - pozwala ustawic stan komorki o danej pozycji
//
//				int getMapWidth() - pozwala pobrac szerokosc mapy
//				int getMapHeight() - pozwala pobrac wysokosc mapy
//				bool getCellState(int x, int y) - pozwala pobrac wartosc pola z danej pozycji mapy
//
//
//	Autor: Dawid Garnczarek
//	Data utworzenia: 28.02.2020r
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef cellMatrix_h
#define cellMatrix_h
#include "singleCell.h"

class CellMatrix
{
	friend class GameEngine;


	// POLA

	private:

		int mapWidth;
		int mapHeight;
		SingleCell** matrix;

	// KONSTRUKTORY I DESTRUKTOR

	public:

		CellMatrix();
		CellMatrix(int mapWidth,int mapHeight);
		CellMatrix(const CellMatrix& cellMatrixCopy);
	
		virtual ~CellMatrix();

	// OPERATORY

		CellMatrix& operator=(const CellMatrix& cellMatrixCopy);
		friend std::ostream& operator<<(std::ostream& out, const CellMatrix& cellMatrixCopy);

	// METODY
	
	

		void setMapWidth(int width);
		void setMapHeight(int height);
		void setSingleCell(int x, int y, bool state);

		int getMapWidth();
		int getMapHeight();
		bool getCellState(int x, int y);
	
	
};

#endif
