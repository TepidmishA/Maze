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

void HeroCell::visit(painter* p, int x, int y)
{
	p->hero(x, y);
}

string HeroCell::getIcon()
{
	return "hero";
}