#include "CoinLib.h"

bool Coin::canSetHero()
{
	return false;
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

void Coin::visit(painter* p, int x, int y)
{
	p->coin(x, y);
}

string Coin::getIcon()
{
	return "coin";
}
