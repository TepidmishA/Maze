#pragma once
#include "CellLib.h"


class Wall : public Cell
{
public:
	Wall() {
		setColor(WHITE);
	}

	virtual bool canSetHero();
	virtual Cell* copy(); // { return new Cell(*this); } 

	virtual Cell* operator+(Hero& hero);
	virtual Cell* operator-(Hero& hero);

	virtual void visit(painter* p, int x, int y);
	virtual string getIcon();
};

