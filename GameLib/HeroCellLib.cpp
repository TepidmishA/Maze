#include "HeroCellLib.h"

bool HeroCell::canSetHero()
{
	return false;
}

Cell* HeroCell::copy()
{
	return new HeroCell(*this);
}

Cell* HeroCell::operator+(Hero& hero)
{
	throw ExceptionCellAdd();
	return this;
}

Cell* HeroCell::operator-(Hero& hero)
{
	return new EmptyCell(this);
}

void HeroCell::visit(ostream& out)
{
	out << "^";
}