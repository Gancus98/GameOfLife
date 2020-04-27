////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Autor: Dawid Garnczarek
//	Data utworzenia: 28.02.2020r
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "consoleGame.h"

ConsoleGame::ConsoleGame()
	:
	GameEngine()
	{
	}

ConsoleGame::ConsoleGame(int width, int height)
	:
	GameEngine(width,height)
	{
	}

ConsoleGame::ConsoleGame(std::string fileName)
	:
	GameEngine(fileName)
{
}

ConsoleGame::ConsoleGame(const ConsoleGame& consoleGameCopy)
	:
	GameEngine(consoleGameCopy)
	{
	}

ConsoleGame::~ConsoleGame()
{
}

ConsoleGame& ConsoleGame::operator=(const ConsoleGame& consoleGameCopy)
{
	if (&consoleGameCopy != this) // sprawdzenie czy to nie ten sam obiekt
	{
	}
	else
	{
	}
	return *this;
}

void ConsoleGame::drawMap()
{
	
	for (int i = 0; i < map.getMapHeight(); i++)
	{
		for (int j = 0; j < map.getMapWidth(); j++)
		{
			if (map.getCellState(j, i) == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
			}
			std::cout << map.getCellState(j,i) << " ";
		}
		std::cout<<std::endl;
	}
}

void ConsoleGame::inputSetings()
{
	std::cout << "Czy chcesz podac ustawienia gry? Tak - wpisz 1 Nie - wpisz 0" << std::endl;
	bool a;
	std::cin >> a;
	if (a == 0) return;	
	else
	{
		whenNewCell.clear();
		whenCellDie.clear();
		whenNoChange.clear();


		std::cout << "Dla jakich wartosci ma rodzic sie nowa komorka? Aby zakonczyc podawanie wpisz '1000'" << std::endl;
		short temp = 0;
		while (temp != 1000)
		{
			std::cin >> temp;
			whenNewCell.push_back(temp);
		}
		whenNewCell.pop_back();

		std::cout << "Dla jakich wartosci ma nie nastepowac zmiana? Aby zakonczyc podawanie wpisz '1000'" << std::endl;
		temp = 0;
		while (temp != 1000)
		{
			std::cin >> temp;
			whenNoChange.push_back(temp);
		}
		whenNoChange.pop_back();

		std::cout << "Dla jakich wartosci komorka ma umierac? Aby zakonczyc podawanie wpisz '1000'" << std::endl;
		temp = 0;
		while (temp != 1000)
		{
			std::cin >> temp;
			whenCellDie.push_back(temp);
		}
		whenCellDie.pop_back();
	}
}