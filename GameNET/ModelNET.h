#pragma once
#include "ModelLib.h"
#include "ExceptionNET.h"
#include "GrPainter.h"

using namespace System::Windows::Forms;

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
	}

	~ModelNET() { delete modelC; }

	int getHp() { return modelC->getHp(); }
	int getCollectedCoins() { return modelC->getCollectedCoins();}
	int getStepCnt() { return modelC->getStepCnt(); }

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