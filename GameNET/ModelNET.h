#pragma once
#include "ModelLib.h"

#include <vcclr.h>
#include <vector>

using namespace std;

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;


ref class ModelNET;

public ref class IObserverDLL {
public:
	virtual void event_m(ModelNET^ model) = 0;
};


public ref class ModelNET
{
	Model* obj;
	//IObserverDLL^ observer;
	List<IObserverDLL^>^ allODLL;
	int obsCnt = 0;

public:
	ModelNET() {
		obj = new Model(10, 10);
		obj->genMaze();
		allODLL = gcnew List<IObserverDLL^>(5);
		//observer = _observer;
	}

	ModelNET(int h, int w) {
		obj = new Model(h, w);
		obj->genMaze();
		allODLL = gcnew List<IObserverDLL^>(5);
		//observer = _observer;
	}

	int getHp() { return obj->getHp(); }
	int getCollectedCoins() { return obj->getCollectedCoins();}
	int getStepCnt() { return obj->getStepCnt(); }

	int getObsCnt() { return obsCnt; }

	// ????
	Model* getObj() {
		return obj;
	}

	void addObserver(IObserverDLL^ o) {
		allODLL->Add(o); 
		obsCnt++;
	}

	void paintAround(Graphics^ g);

	void move(MoveAction action) {
		obj->move(action);
		for each (IObserverDLL ^ observer in allODLL)
			observer->event_m(this);
	}

	~ModelNET() { delete obj; }
};
