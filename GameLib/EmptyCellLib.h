#pragma once
#include "CellLib.h"
#include "HeroCellLib.h"

class EmptyCell : public Cell
{
	
public:
    EmptyCell() {
        setColor(WHITE);
    }
    EmptyCell(Cell* cell) {
        isVisited(cell->isVisited());
       // isExit(cell->isExit());
        setColor(WHITE);
    }

	virtual bool canSetHero();
	virtual Cell* copy(); // { return new Cell(*this); } 

	virtual Cell* operator+(Hero& hero);
	virtual Cell* operator-(Hero& hero);

	virtual void visit(painter* p, int x, int y);
    virtual string getIcon();
};