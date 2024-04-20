#pragma once
#include <iostream>
#include <fstream>

#include "CellLib.h"
#include "WallLib.h"
#include "CoinLib.h"
#include "MonsterLib.h"
#include "HeroLib.h"
#include "ExitCellLib.h"
#include "funcLib.h"

using namespace std;

#define CELL_SIZE 2
#define	MONSTER_COUNT 4
#define	COIN_COUNT 5

enum MoveAction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Labirinth
{
	int height;
	int width;

	Cell ***maze;
	Hero builder;

	void randCoord(int& x, int& y);
	void randCoordGrid(int& x, int& y);

	char genDir(int& now_x, int& now_y);
	bool moveBuilt(MoveAction action);

	void newCoin();
	void newMonster();

public:
	Labirinth(int _height = 3, int _width = 3);
	int getH() { return height; };
	int getW() { return width; };

	Cell*& get(int x, int y) { return maze[y][x]; };
	void genMaze();

	Labirinth(const Labirinth& lab);
	Labirinth& operator=(const Labirinth& lab);
	~Labirinth();

	friend ostream& operator<<(ostream& out, const Labirinth& lab);

	friend ofstream& operator<<(ofstream& ofs, const Labirinth& lab);
	friend ifstream& operator>>(ifstream& ifs, Labirinth& lab);
};
