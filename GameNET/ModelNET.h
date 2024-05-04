#pragma once
#include "ModelLib.h"
#include "ExceptionNET.h"

#include <vcclr.h>
#include <vector>

#include <sstream>

using namespace std;

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices; // for GCHandle
using namespace System::Windows::Forms;

// change
class GrPainter : public painter {
	gcroot < Graphics^> g;
	gcroot < Brush^> brush = gcnew SolidBrush(Color::Black);
	gcroot < Panel^> panel;
	int cellPixelSize = 14;

public:
	//(Graphics^ _g, Brush^ _b) :g(_g), b(_b) {}
	GrPainter(Graphics^ _g) :g(_g) {}

	void setGr(Graphics^ _g) {
		g = _g;
		g->Clear(Color::White);
	}

	virtual void paintCell(ostream& out, Cell*& cell, int x, int y) {
		char val;
		ostringstream ss;
		cell->visit(ss);
		val = ss.str()[0];
		String^ symbolStr = Char::ToString(val);

		int drawX = x * cellPixelSize;
		int drawY = y * cellPixelSize;

		g->DrawString(symbolStr, gcnew Font("Verdana", cellPixelSize), brush, drawX, drawY);
	}
};

ref class ModelNET;

public ref class ObserverNET 
{
public:
	virtual void event_m(ModelNET^ model) = 0;
};

public ref class ModelNET
{
	GrPainter* painter;
	Model* modelC;
	List<ObserverNET^>^ allODLL;
	int obsDeltaY = 0;

	void addObsC();

public:
	ModelNET();

	ModelNET(int h, int w);

	void update() {
		for each (ObserverNET ^ observer in allODLL)
			observer->event_m(this);
	}

	void addObserver(ObserverNET^ o) {
		allODLL->Add(o);
		obsDeltaY += 20;
		update();
	}

	void move(MoveAction action) {
		try {
			modelC->move(action);
		}
		catch (ExceptionZeroHP e) {
			throw gcnew ExceptionZeroHPNET();
		}
		catch (ExceptionWin e) {
			throw gcnew ExceptionWinNET();
		}
		//update();
	}

	~ModelNET() { delete modelC; }

	int getObsDeltaY() { return obsDeltaY; }
	void addObsDeltaY(int val) { obsDeltaY += val; }
	int getViewField() { return modelC->getHero().getView(); }

	int getHp() { return modelC->getHp(); }
	int getCollectedCoins() { return modelC->getCollectedCoins();}
	int getStepCnt() { return modelC->getStepCnt(); }

	Labirinth getLab() { return modelC->getLab(); }

	void showAround(Panel^ panel, ostream& out) {
		if (painter == nullptr) {
			painter = new GrPainter(panel->CreateGraphics());
			modelC->initPainter(painter);
		}
		painter->setGr(panel->CreateGraphics());
		modelC->showAround(cout); // убрать cout
	}

	void showAll(Panel^ panel, ostream& out) {
		if (painter == nullptr) {
			painter = new GrPainter(panel->CreateGraphics());
			modelC->initPainter(painter);
		}
		painter->setGr(panel->CreateGraphics());
		
		modelC->showAll(cout); // убрать cout
	}
};

class Omodel : public Observer
{
	gcroot <ModelNET^> mNET;

public:
	Omodel(ModelNET^ _mNET) :mNET(_mNET) {}

	void evnt(Model& model) {
		mNET->update();
	}
};