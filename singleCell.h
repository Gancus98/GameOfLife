////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Klasa zawiera pola oraz metody reprezentujace pojedyncza kom�rke w tablicy/grze reprezentuje stan 0 lub 1
//
//ZAWARTOSC:	
//
//		POLA:
//
//				cellState - pole ktore przechowuje stan kom�rki 0 lub 1
//
//		KONSTRUKTORY:
//
//				SingleCell(bool state = 0) - konstruktor parametrowy bed�cy jednoczesnie konstruktorem domy�lnym, w przypadku braku argumentu inicjuje pole zerem	
//				SingleCell(const SingleCell& singleCellCopy) - konstruktor kopiujacy
//
//		DESTRUKTOR:
//
//				~SingleCell() - virtualny destruktor
//
//		PRZECIAZENIA OPERATOROW:
//
//				SingleCell& operator=(const SingleCell& singleCellCopy) - przeciazony operator przypisania
//				friend std::ostream& operator<<(std::ostream& out, const SingleCell& singleCellCopy) - przeciazony operator strumienia, wyswietla aktualny stan komorki
//
//		METODY PRYWATNE - nie chce dawa� u�ytkownikowi mo�liwo�ci manipulowania polami 
//
//				void setCellState(bool state) - metoda pozwalaj�ca ustawi� stan kom�rki
//				bool getCellState() - metoda pozwalajaca pobra� stan kom�rki
//
//
//	Autor: Dawid Garnczarek
//	Data utworzenia: 28.02.2020r
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef singleCell_h
#define singleCell_h
#include <iostream>

class SingleCell
{
	friend class CellMatrix;
	// POLA

	private:
		
		bool cellState;

	// KONSTRUKTORY I DESTRUKTOR

	public:

		SingleCell(bool state = 0);
		SingleCell(const SingleCell& singleCellCopy);

		virtual ~SingleCell();

	// OPERATORY DLA OBIEKTU

		SingleCell& operator=(const SingleCell& singleCellCopy);
		friend std::ostream& operator<<(std::ostream& out, const SingleCell& singleCellCopy);

	// METODY

	private:

		void setCellState(bool state);
		bool getCellState();

};

#endif