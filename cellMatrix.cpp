////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Autor: Dawid Garnczarek
//	Data utworzenia: 28.02.2020r
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "cellMatrix.h"

CellMatrix::CellMatrix()
	:
	mapWidth(0)
	,mapHeight(0)
	,matrix(nullptr)
	{
	}

CellMatrix::CellMatrix(int mapWidth, int mapHeight)
	:
	mapWidth(mapWidth)
	,mapHeight(mapHeight)
	,matrix(nullptr)
	{
	matrix = new SingleCell * [mapHeight];
	for (int i = 0; i < mapHeight; ++i)
		matrix[i] = new SingleCell[mapWidth];
	}

CellMatrix::CellMatrix(const CellMatrix& cellMatrixCopy)
	:
	mapWidth(cellMatrixCopy.mapWidth)
	,mapHeight(cellMatrixCopy.mapHeight)
	{
		matrix = new SingleCell * [cellMatrixCopy.mapHeight];
		for (int i = 0; i < cellMatrixCopy.mapHeight; ++i)
			matrix[i] = new SingleCell[cellMatrixCopy.mapWidth];

		for (int i = 0; i < cellMatrixCopy.mapHeight; ++i)
		{
			for (int j = 0; j < cellMatrixCopy.mapWidth; ++j)					
				matrix[i][j] = cellMatrixCopy.matrix[i][j];
		}
	}

CellMatrix::~CellMatrix()
{
	for (int i = 0; i < mapHeight; i++)
		delete[] matrix[i];
	delete[] matrix;
}

CellMatrix& CellMatrix::operator=(const CellMatrix& cellMatrixCopy)
{

	if (&cellMatrixCopy != this)
	{
		mapWidth = cellMatrixCopy.mapWidth;
		mapHeight = cellMatrixCopy.mapHeight;

		matrix = new SingleCell * [cellMatrixCopy.mapHeight];
		for (int i = 0; i < cellMatrixCopy.mapHeight; ++i)
			matrix[i] = new SingleCell[cellMatrixCopy.mapWidth];

		for (int i = 0; i < cellMatrixCopy.mapHeight; ++i)
		{
			for (int j = 0; j < cellMatrixCopy.mapWidth; ++j)
				matrix[i][j] = cellMatrixCopy.matrix[i][j];
		}

	}
	else
	{
	}
	return *this;
}

void CellMatrix::setMapWidth(int width)
{
	mapWidth = width;
}

void CellMatrix::setMapHeight(int height)
{
	mapHeight = height;
}

void CellMatrix::setSingleCell(int x, int y, bool state)
{
	matrix[y][x] = state; //odwrotnie poniewaz y jest numerem naszego wiersza pierwszym elementem talbicy dwu-wymiarowej
}

int CellMatrix::getMapWidth()
{
	return mapWidth;
}

int CellMatrix::getMapHeight()
{
	return mapHeight;
}

bool CellMatrix::getCellState(int x, int y)
{
	SingleCell temp;
	temp = matrix[y][x]; //odwrotnie poniewaz y jest numerem naszego wiersza pierwszym elementem talbicy dwu-wymiarowej
	return temp.getCellState();
}

std::ostream& operator<<(std::ostream& out, const CellMatrix& cellMatrixCopy)
{
	for (int i = 0; i < cellMatrixCopy.mapHeight; i++)
	{
		for (int j = 0; j < cellMatrixCopy.mapWidth; j++)
		{
			out << cellMatrixCopy.matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return out;
}
