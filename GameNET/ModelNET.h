#pragma once
#include "ModelLib.h"
#include "ExceptionNET.h"

#include <vcclr.h>
#include <vector>

using namespace std;

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices; // for GCHandle
using namespace System::Windows::Forms;

// change
class GrPainter : public painter {
	gcroot < Graphics^> g;
	gcroot < Pen^> p;
public:
	GrPainter(Graphics^ _g, Pen^ _p) :g(_g), p(_p) {}

	void setGr(Graphics^ _g, Pen^ _p) {
		g = _g; p = _p;
	}

	virtual void paint(std::string s)
	{
		//    String^ res = gcnew String(s.c_str());
		g->DrawRectangle(p, 10, 10, 20, 20);
	}

	virtual void paintPoint(int x, int y) {
		g->DrawRectangle(p, x - 10, y - 10, 20, 20);

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
	//int getLabW() { return lab.getW(); }

	// void paintAround(Graphics^ g);
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