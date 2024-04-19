#pragma once

#include "Cell.h"
#include "Hero.h"

#include "func.h"
#include "Labyrinth.h"

#include "ExceptionCellAdd.h"
#include "ExceptionExit.h"
#include "ExceptionZeroHP.h"

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