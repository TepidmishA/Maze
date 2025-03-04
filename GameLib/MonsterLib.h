#pragma once

#include "CellLib.h"
#include "HeroCellLib.h"
#include "LabyrinthLib.h"

class Monster : public Cell
{
	int hp;
public:
    Monster() {
        setColor(RED);
		hp = 2;
    }

	virtual bool canSetHero();
	virtual Cell* copy(); // { return new Cell(*this); } 

	virtual Cell* operator+(Hero& hero);
	virtual Cell* operator-(Hero& hero);

	virtual void visit(painter* p, int x, int y);
	virtual string getIcon();

	void getDamage(int val = 1) { hp -= val; }
	bool checkHP() { return hp == 0; }
};

