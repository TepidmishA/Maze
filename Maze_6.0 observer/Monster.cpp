#include "Monster.h"

bool Monster::canSetHero()
{
	return true;
}

Cell* Monster::copy()
{
	return new Monster(*this);
}

Cell* Monster::operator+(Hero& hero)
{
	hero.getDamage();
	this->getDamage();
	if (!this->checkHP()) throw ExceptionCellAdd();
	return new HeroCell();
}

Cell* Monster::operator-(Hero& hero)
{
	throw ExceptionCellAdd();
	return this;
}

void Monster::visit(ostream& out)
{
	out << "*";
}