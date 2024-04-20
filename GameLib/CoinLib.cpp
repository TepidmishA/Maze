#include "CoinLib.h"

bool Coin::canSetHero()
{
	return true;
}

Cell* Coin::copy()
{
	return new Coin(*this);
}

Cell* Coin::operator+(Hero& hero)
{
	hero.addCoin();
	return new HeroCell();
}

Cell* Coin::operator-(Hero& hero)
{
	throw ExceptionCellAdd();
	return this;
}

void Coin::visit(ostream& out)
{
	out << "@";
}