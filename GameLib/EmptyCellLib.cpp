#include "EmptyCellLib.h"

bool EmptyCell::canSetHero()
{
	return true;
}

Cell* EmptyCell::copy() 
{
	return new EmptyCell(*this);
}

Cell* EmptyCell::operator+(Hero& hero)
{
	return new HeroCell(this);
}

Cell* EmptyCell::operator-(Hero& hero)
{
	return this;
}

void EmptyCell::visit(painter* p, int x, int y)
{
	p->emptyCell(x, y);
}

string EmptyCell::getIcon()
{
	return "emptyCell";
}
