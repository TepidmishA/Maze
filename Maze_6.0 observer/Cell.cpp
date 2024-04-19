#include "Cell.h"
#include "Labyrinth.h"

Cell::Cell(const Cell& cell)
{
	visited = cell.visited;
	color = cell.color;
}

Cell& Cell::operator=(const Cell& cell)
{
	if (this == &cell) return *this;
	visited = cell.visited;
	color = cell.color;
	return *this;
}

istream& operator>>(istream& in, Cell*& cell)
{
	char val;
	in >> val;
	switch (val)
	{
	case '@':
		cell = new Coin();
		break;
	case '*':
		cell = new Monster();
		break;
	case '#':
		cell = new Wall();
		break;
	default:
		cell = new EmptyCell();
		break;
	}
	return in;
}