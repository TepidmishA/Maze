#pragma once
#include "LabyrinthLib.h"

#include <vcclr.h>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

ref class ModelNET;

public ref class IObserverDLL {
public:
	virtual void event_m(ModelNET^ model) = 0;
};

/*
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
*/



public ref class ModelNET
{
	Labirinth& lab = *(new Labirinth);
	Hero& hero = *(new Hero);

	List<IObserverDLL^>^ allODLL;
	int obsCnt = 0;
	int stepCnt = 0;

	void randCoord(int& x, int& y);
	void randCoordGrid(int& x, int& y);

	void startCell();

	void evnt() { // оповещение всех наблюдателей
		for each (IObserverDLL ^ observer in allODLL)
			observer->event_m(this);
	}

public:
	ModelNET() {
		lab = Labirinth(7, 7);
		allODLL = gcnew List<IObserverDLL^>(5);
	}

	ModelNET(int h, int w) {
		lab = Labirinth(h * 2 + 1, w * 2 + 1);
		allODLL = gcnew List<IObserverDLL^>(5);
	}

	void genMaze();
	void newMaze(const int& width, const int& height) { lab = Labirinth(height * 2 + 1, width * 2 + 1); };

	int getHp() { return hero.getHP(); }
	int getCollectedCoins() { return hero.getCoin(); }
	int getStepCnt() { return stepCnt; }
	int getObsCnt() { return obsCnt; }

	//Color getColor(int consoleColor) {
	//	return colors[consoleColor];
	//}

	void move(MoveAction action);

	Labirinth& getLab() { return lab; }
	Hero& getHero() { return hero; }

	void addObserver(IObserverDLL^ o) {
		allODLL->Add(o);
		obsCnt++;
	}

	void paintAround(Panel^ p);
};
