#pragma once
#include "Model.h"

class Controller {
	Model* model;

	void randCoord(int& x, int& y);
	void randCoordGrid(int& x, int& y);

	void startCell();

public:
	Controller(Model* _model) :model(_model) {}

	void start();
	void step(char val);

	void genMaze();

	void newMaze(const int& width, const int& height) { model->getLab() = Labirinth(height * 2 + 1, width * 2 + 1); };
	void readMaze(const string& fileName);
	void saveMaze(const string& fileName);
};
