#pragma once
#include "CellLib.h"
#include "HeroCellLib.h"

class ExitCell : public Cell
{
    int coins;
public:
    ExitCell(int _coins) {
        setColor(WHITE);
        coins = _coins;
    }

    virtual bool canSetHero();
    virtual Cell* copy(); // { return new Cell(*this); } 

    virtual Cell* operator+(Hero& hero);
    virtual Cell* operator-(Hero& hero);

    virtual void visit(painter* p, int x, int y);
    virtual string getIcon();

    bool checkCoins(Hero& hero);
};