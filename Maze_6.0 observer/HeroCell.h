#pragma once
#include "Cell.h"
#include "EmptyCell.h"

class HeroCell : public Cell
{

public:
	HeroCell() {
		isVisited(true);
		setColor(GREEN);
	}
	HeroCell(Cell* cell) {
		isVisited(true);
		setColor(GREEN);
	}

	virtual bool canSetHero();
	virtual Cell* copy();

	virtual Cell* operator+(Hero& hero);
	virtual Cell* operator-(Hero& hero);

	virtual void visit(ostream& out);
};