#include "ExitCellLib.h"

bool ExitCell::canSetHero()
{
	return true;
}

Cell* ExitCell::copy()
{
	return new ExitCell(*this);
}

Cell* ExitCell::operator+(Hero& hero)
{
	if (!checkCoins(hero)) throw ExceptionExit();
	throw ExceptionWin();
	//hero.setExit();
	return new HeroCell();
}

Cell* ExitCell::operator-(Hero& hero)
{
	throw ExceptionCellAdd();
	return this;
}

void ExitCell::visit(painter* p, int x, int y)
{
	p->emptyCell(x, y);
}

string ExitCell::getIcon()
{
	return "emptyCell";
}

bool ExitCell::checkCoins(Hero& hero)
{
	return hero.getCoin() == this->coins;
}