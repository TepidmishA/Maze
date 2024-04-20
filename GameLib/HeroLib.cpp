#include "HeroLib.h"

ostream& operator<<(ostream& out, const Hero& hero)
{
	out << "^";
	return out;
}

void Hero::getDamage(int val)
{
	hp -= val;
	if (hp == 0) throw ExceptionZeroHP();
}
