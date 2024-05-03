#pragma once

#include "CellLib.h"
#include "HeroLib.h"

#include "funcLib.h"
#include "LabyrinthLib.h"

#include "ExceptionCellAddLib.h"
#include "ExceptionExitLib.h"
#include "ExceptionZeroHPLib.h"

class Game
{
	Labirinth lab;
	Hero hero;

	void randCoord(int& x, int& y);
	void randCoordGrid(int& x, int& y);

	void startCell();

public:
	Game(int _height = 3, int _width = 3);
	void move(MoveAction action);

	void printMaze() { cout << lab; };
	void printAround();

	void newMaze(const int& width, const int& height) { lab = Labirinth(height * 2 + 1, width * 2 + 1); };
	void readMaze(const string& fileName);
	void saveMaze(const string& fileName);

	void genMaze();
};