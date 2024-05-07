#pragma once
#include <iostream>

using namespace std;

class painter {
	ostream& out;

public:
	painter(ostream& _out = cout) :out(_out) {}

	virtual void wall(int x, int y) { out << "#"; }
	virtual void coin(int x, int y) { out << "@"; }
	virtual void emptyCell(int x, int y) { out << " "; }
	virtual void monster(int x, int y) { out << "*"; }
	virtual void hero(int x, int y) { out << "^"; }
};