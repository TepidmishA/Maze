#pragma once
#include "Cell.h"
#include "HeroCell.h"

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

    virtual void visit(ostream& out);

    bool checkCoins(Hero& hero);
};