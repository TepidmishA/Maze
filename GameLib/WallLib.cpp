#include "WallLib.h"

bool Wall::canSetHero()
{
	return false;
}

Cell* Wall::copy()
{
	return new Wall(*this);
}

Cell* Wall::operator+(Hero& hero)
{
	hero.getDamage();
	throw ExceptionCellAdd();
	return this;
}

Cell* Wall::operator-(Hero& hero)
{
	throw ExceptionCellAdd();
	return this;
}

void Wall::visit(painter* p, int x, int y)
{
	p->wall(x, y);
}

string Wall::getIcon()
{
	return "wall";
}