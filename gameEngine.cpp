////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Autor: Dawid Garnczarek
//	Data utworzenia: 28.02.2020r
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "gameEngine.h"

GameEngine::GameEngine()
	:
	map()
	,whenNewCell(0)
	,whenNoChange(0)
	,whenCellDie(0)
	{
	}

GameEngine::GameEngine(int width, int height)
	:map(CellMatrix(width,height))
	{
	}

GameEngine::GameEngine(std::string fileName)
{
	short width = 0, height = 0;
	bool state;
	std::ifstream file;
	file.open(fileName);


	if (file.good())
	{
		file >> width >> height;
		map = CellMatrix(width, height);
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				file >> state;
				map.setSingleCell(j, i, state);
			}
		}
	}
	else
	{
		std::cerr << "Error";
	}
	file.close();
}

GameEngine::GameEngine(const GameEngine& gameEngineCopy)
	:
	map(gameEngineCopy.map)
	,whenNewCell(gameEngineCopy.whenNewCell)
	,whenNoChange(gameEngineCopy.whenNoChange)
	,whenCellDie(gameEngineCopy.whenCellDie)
	{
	}

GameEngine::~GameEngine()
{
}


GameEngine& GameEngine::operator=(const GameEngine& gameEngineCopy)
{
	if (&gameEngineCopy != this) // sprawdzenie czy to nie ten sam obiekt
	{
		map = gameEngineCopy.map;
		whenNewCell = gameEngineCopy.whenNewCell;
		whenNoChange = gameEngineCopy.whenNoChange;
		whenCellDie = gameEngineCopy.whenCellDie;
	}
	else
	{
	}
	return *this;
}





void GameEngine::play()
{
	this->inputSetings();
	while (1)
	{
		
		this->drawMap();
		Sleep(100);
		calculate();
		std::system("CLS");
	}
}

void GameEngine::calculate()
{
	short howManyFriends = 0;
	CellMatrix tempMap(map.mapWidth, map.mapHeight);

	for (int i = 0; i < map.mapHeight; i++)
	{
		for (int j = 0; j < map.mapWidth; j++)
		{
			howManyFriends = numberOfFriends(i,j);

			for (int k = 0; k < whenNewCell.size(); ++k)
			{
				if (howManyFriends == whenNewCell[k]) {
					tempMap.matrix[i][j] = 1;
					continue;
				}
			}
			for (int k = 0; k < whenCellDie.size(); ++k)
			{
				if (howManyFriends == whenCellDie[k]) {
					tempMap.matrix[i][j] = 0;
					continue;
				}
			}
			for (int k = 0; k < whenNoChange.size(); ++k)
			{
				if (howManyFriends == whenNoChange[k]) {
					tempMap.matrix[i][j] = map.matrix[i][j];
					continue;
				}
			}
		}	
	}

	for (int i = 0; i < map.mapHeight; i++)
	{
		for (int j = 0; j < map.mapWidth; j++)
		{
			map.matrix[i][j] = 0;
			map.matrix[i][j] = tempMap.matrix[i][j];
		}
	}
}


CellMatrix& GameEngine::getMap()
{
	return map;
}

std::vector<short>& GameEngine::getWhenNewCell()
{
	return whenNewCell;
}

std::vector<short>& GameEngine::getWhenNoChange()
{
	return whenNoChange;
}

std::vector<short>& GameEngine::getWhenCellDie()
{
	return whenCellDie;
}

void GameEngine::setMap(const CellMatrix& copy)
{
	map = copy;
}

void GameEngine::setWhenNewCell(const std::vector<short>& copy)
{
	whenNewCell = copy;
}

void GameEngine::setWhenNoChange(const std::vector<short>& copy)
{
	whenNoChange = copy;
}

void GameEngine::setWhenCellDie(const std::vector<short>& copy)
{
	whenCellDie = copy;
}

int GameEngine::numberOfFriends(int i, int j)
{
	int howManyFriends = 0;

	if (i == 0 && j == 0)
	{
		//std::cout << "lg";
		if (map.getCellState(j + 1, i) == 1) howManyFriends++;
		if (map.getCellState(j + 1, i + 1) == 1) howManyFriends++;
		if (map.getCellState(j, i + 1) == 1) howManyFriends++;
	}
	else if (i == 0 && j == map.mapWidth - 1)
	{
		//std::cout << "pg";
		if (map.getCellState(j, i + 1) == 1) howManyFriends++;
		if (map.getCellState(j - 1, i + 1) == 1) howManyFriends++;
		if (map.getCellState(j - 1, i) == 1) howManyFriends++;

	}
	else if (i == map.mapHeight - 1 && j == 0)
	{
		//std::cout << "ld";
		if (map.getCellState(j, i - 1) == 1) howManyFriends++;
		if (map.getCellState(j + 1, i) == 1) howManyFriends++;//
		if (map.getCellState(j - 1, i - 1) == 1) howManyFriends++;

	}
	else if (i == map.mapHeight - 1 && j == map.mapWidth - 1)
	{
		//std::cout << "pd";
		if (map.getCellState(j, i - 1) == 1) howManyFriends++;
		if (map.getCellState(j - 1, i) == 1) howManyFriends++;
		if (map.getCellState(j - 1, i - 1) == 1) howManyFriends++;

	}
	else if (i == 0)
	{
		//std::cout << "g";
		if (map.getCellState(j + 1, i) == 1) howManyFriends++;
		if (map.getCellState(j + 1, i + 1) == 1) howManyFriends++;
		if (map.getCellState(j, i + 1) == 1) howManyFriends++;
		if (map.getCellState(j - 1, i + 1) == 1) howManyFriends++;
		if (map.getCellState(j - 1, i) == 1) howManyFriends++;

	}
	else if (i == map.mapHeight - 1)
	{
		//std::cout << "d";
		if (map.getCellState(j, i - 1) == 1) howManyFriends++;
		if (map.getCellState(j + 1, i - 1) == 1) howManyFriends++;
		if (map.getCellState(j + 1, i) == 1) howManyFriends++;
		if (map.getCellState(j - 1, i) == 1) howManyFriends++;
		if (map.getCellState(j - 1, i - 1) == 1) howManyFriends++;

	}
	else if (j == 0)
	{
		//std::cout << "l";
		if (map.getCellState(j, i - 1) == 1) howManyFriends++;
		if (map.getCellState(j + 1, i - 1) == 1) howManyFriends++;
		if (map.getCellState(j + 1, i) == 1) howManyFriends++;
		if (map.getCellState(j + 1, i + 1) == 1) howManyFriends++;
		if (map.getCellState(j, i + 1) == 1) howManyFriends++;

	}
	else if (j == map.mapWidth - 1)
	{
		//std::cout << "p";
		if (map.getCellState(j, i + 1) == 1) howManyFriends++;
		if (map.getCellState(j - 1, i + 1) == 1) howManyFriends++;
		if (map.getCellState(j - 1, i) == 1) howManyFriends++;
		if (map.getCellState(j - 1, i - 1) == 1) howManyFriends++;
		if (map.getCellState(j, i - 1) == 1) howManyFriends++;

	}
	else
	{
		//std::cout << "hi";
		if (map.getCellState(j, i - 1) == 1) howManyFriends++;
		if (map.getCellState(j + 1, i - 1) == 1) howManyFriends++;
		if (map.getCellState(j + 1, i) == 1) howManyFriends++;
		if (map.getCellState(j + 1, i + 1) == 1) howManyFriends++;
		if (map.getCellState(j, i + 1) == 1) howManyFriends++;
		if (map.getCellState(j - 1, i + 1) == 1) howManyFriends++;
		if (map.getCellState(j - 1, i) == 1) howManyFriends++;
		if (map.getCellState(j - 1, i - 1) == 1) howManyFriends++;
	}

	return howManyFriends;
}

std::ostream& operator<<(std::ostream& out, const GameEngine& gameEngineCopy)
{
		out << "Kiedy rodzi sie nowa: ";
		for (unsigned short i = 0; i < gameEngineCopy.whenNewCell.size(); ++i)
			std::cout << gameEngineCopy.whenNewCell[i] << " ";
		out << std::endl;

		out << "Kiedy nie ma zmian: ";
		for (unsigned short i = 0; i < gameEngineCopy.whenNoChange.size(); ++i)
			out << gameEngineCopy.whenNoChange[i] << " ";
		out << std::endl;

		out << "Kiedy umiera: ";
		for (unsigned short i = 0; i < gameEngineCopy.whenCellDie.size(); ++i)
			out << gameEngineCopy.whenCellDie[i] << " ";
		out << std::endl;
	
	return out;
}
