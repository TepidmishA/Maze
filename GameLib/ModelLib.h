#pragma once

#include "LabyrinthLib.h"

#include "ExceptionCellAddLib.h"
#include "ExceptionExitLib.h"
#include "ExceptionZeroHPLib.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Model;

class Observer
{

public:
	virtual void evnt(Model& model) = 0;
};

class Model
{
	Labirinth lab;
	Hero hero;
	int stepCnt = 0;

	vector<Observer*> allO;

	void update() {
		for (Observer* o : allO) o->evnt(*this);
	}

	void randCoord(int& x, int& y);
	void randCoordGrid(int& x, int& y);

	void startCell();

public:
	Model(int _height = 3, int _width = 3);

	void genMaze();
	void newMaze(const int& width, const int& height) { lab = Labirinth(height * 2 + 1, width * 2 + 1); };
	void readMaze(const string& fileName);
	void saveMaze(const string& fileName);

	void start() { update(); }

	int getHp() { return hero.getHP(); }
	int getCollectedCoins() { return hero.getCoin(); }
	int getStepCnt() { return stepCnt; }

	void move(MoveAction action);

	Labirinth& getLab() { return lab; }
	Hero& getHero() { return hero; }

	void addObserver(Observer* o) {	allO.push_back(o);	}
};

class ShowAround : public Observer {
	ostream& out;

public:
	ShowAround(ostream& _out) :out(_out) {}

	virtual void evnt(Model& model);
};

class ShowAllMap : public Observer {
	ostream& out;

public:
	ShowAllMap(ostream& _out) :out(_out) {}

	virtual void evnt(Model& model) { out << model.getLab(); }
};

class ShowcollectedCoin : public Observer {
	ostream& out;

public:
	ShowcollectedCoin(ostream& _out) :out(_out) {}

	virtual void evnt(Model& model) {
		out << "Coins collected: " << model.getCollectedCoins() << endl;
	}
};

class ShowHP : public Observer {
	ostream& out;

public:
	ShowHP(ostream& _out) :out(_out) {}

	virtual void evnt(Model& model) {
		out << "HP: " << model.getHp() << endl;
	}
};

class ShowStepCnt : public Observer {
	ostream& out;

public:
	ShowStepCnt(ostream& _out) :out(_out) {}

	virtual void evnt(Model& model) {
		out << "Count step: " << model.getStepCnt() << endl;
	}
};