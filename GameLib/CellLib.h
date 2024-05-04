#pragma once
#include <stdio.h>
#include "HeroLib.h"

#include "ExceptionCellAddLib.h"
#include "ExceptionExitLib.h"
#include "ExceptionZeroHPLib.h"
#include "ExceptionWinLib.h"

#include "Windows.h"

enum ConsoleColor {
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	YELLOW,
	WHITE,
};

class Cell
{
	bool visited = false;
	ConsoleColor color;

public:
	bool isVisited() { return visited; }
	void isVisited(bool thing) { visited = thing; }

	ConsoleColor getColor() { return color; }
	void setColor(ConsoleColor _color) { color = _color; }

	Cell(const Cell& cell);
	Cell& operator=(const Cell& cell);

	Cell() = default;

	virtual bool canSetHero() = 0;
	virtual Cell* copy() = 0; // { return new Cell(*this); } 

	virtual Cell* operator+(Hero& hero) = 0;
	virtual Cell* operator-(Hero& hero) = 0;

	//virtual void visit(ostream& out) = 0;
	virtual void visit(ostream& out) = 0;

	friend istream& operator>>(istream& in, Cell*& cell);
};
