#pragma once

#include "CellLib.h"
#include "HeroCellLib.h"
#include "LabyrinthLib.h"

class Coin : public Cell
{
public:
    Coin() {
        setColor(YELLOW);
    }

	virtual bool canSetHero();
	virtual Cell* copy(); // { return new Cell(*this); } 

	virtual Cell* operator+(Hero& hero);
	virtual Cell* operator-(Hero& hero);

	virtual void visit(ostream& out);
	virtual string getIcon();
};

