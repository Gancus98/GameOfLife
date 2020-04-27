////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Autor: Dawid Garnczarek
//	Data utworzenia: 28.02.2020r
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "singleCell.h"

SingleCell::SingleCell(bool state)
	:
	cellState(state)
	{
	}

SingleCell::SingleCell(const SingleCell& singleCellCopy)
	:
	cellState(singleCellCopy.cellState)
	{
	}

SingleCell::~SingleCell()
{
}

SingleCell& SingleCell::operator=(const SingleCell& singleCellCopy)
{
	if (&singleCellCopy != this) // sprawdzenie czy to nie ten sam obiekt
	{
		cellState = singleCellCopy.cellState;
	}
	else
	{
	}

	return *this;
}

void SingleCell::setCellState(bool state)
{
	this->cellState = state;
}

bool SingleCell::getCellState()
{
	return cellState;
}

std::ostream& operator<<(std::ostream& out, const SingleCell& singleCellCopy)
{
	out << singleCellCopy.cellState;
	return out;
}
