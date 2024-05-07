#pragma once
#include "ModelLib.h"

#include <vcclr.h>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;


class GrPainter : public painter {
	gcroot < Graphics^> g;
	map<string, gcroot < Icon^>> icons;
	vector<string> names;

	int cellPixelSize = 30;
	Drawing::Rectangle rect;

public:
	GrPainter() { initIcons(); }
	GrPainter(Graphics^ _g) :g(_g) { initIcons(); }

	void setGr(Graphics^ _g) {
		g = _g;
	}

	void initIcons() {
		names = { "wall", "coin", "emptyCell", "monster", "hero" };
		for each (string name in names) {
			String^ tmp = gcnew String((name + ".ico").c_str());
			gcroot<Icon^> newIcon = gcnew Icon(tmp);

			icons[name] = newIcon;
		}
	}

	virtual void paintCell(string fileName, int x, int y) {
		int drawX = x * cellPixelSize;
		int drawY = y * cellPixelSize;
		rect = Drawing::Rectangle(drawX, drawY, cellPixelSize, cellPixelSize);

		g->DrawIcon(icons[fileName], rect);
	}

	virtual void wall(int x, int y) {
		paintCell("wall", x, y);
	}
	virtual void coin(int x, int y) {
		paintCell("coin", x, y);
	}
	virtual void emptyCell(int x, int y) {
		paintCell("emptyCell", x, y);
	}
	virtual void monster(int x, int y) {
		paintCell("monster", x, y);
	}
	virtual void hero(int x, int y) {
		paintCell("hero", x, y);
	}
};
