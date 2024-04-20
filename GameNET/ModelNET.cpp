#include "ModelNET.h"

void ModelNET::randCoord(int& x, int& y)
{
	while (x < 1 || y < 1 || !lab.get(x, y)->canSetHero()) {
		x = (int)(((double)rand() / RAND_MAX) * (lab.getW() - 1));
		y = (int)(((double)rand() / RAND_MAX) * (lab.getH() - 1));
	}
}

void ModelNET::randCoordGrid(int& x, int& y)
{
	while (x % 2 != 1 || y % 2 != 1 || !lab.get(x, y)->canSetHero()) {
		x = (int)(((double)rand() / RAND_MAX) * (lab.getW() - 1));
		y = (int)(((double)rand() / RAND_MAX) * (lab.getH() - 1));
	}
}

void ModelNET::startCell()
{

	int x = 0, y = 0;
	randCoord(x, y);

	lab.get(x, y) = new HeroCell();
	hero.move(x, y);
}

void ModelNET::genMaze()
{
	srand(time(NULL));

	lab.genMaze();
	startCell();
}

void ModelNET::move(MoveAction action)
{
	int x = hero.getX();
	int y = hero.getY();

	switch (action)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	if ((x < 0) || (y < 0) || (x >= lab.getW()) || (y >= lab.getH()))
		return;

	try {
		Cell* tmp = lab.get(x, y);
		lab.get(x, y) = (*lab.get(x, y)) + hero;
		delete tmp;

		int hero_x = hero.getX(), hero_y = hero.getY();
		tmp = lab.get(hero_x, hero_y);
		lab.get(hero_x, hero_y) = (*lab.get(hero_x, hero_y)) - hero;
		delete tmp;

		hero.move(x, y);
	}
	catch (ExceptionCellAdd e) {
		// cout << e.what()
	}
	catch (ExceptionExit e) {
		// cout << e.what()
	}
	stepCnt++;
	evnt();
}

void ModelNET::paintAround(Panel^ p)
{
	/*
	for (int y = hero.getY() - hero.getView(); y < hero.getY() + 1 + hero.getView(); y++) {
		for (int x = hero.getX() - hero.getView(); x < hero.getX() + 1 + hero.getView(); x++) {
			for (int k = 0; k < CELL_SIZE; k++) {
				if ((x < 0) || (y < 0) || (x >= lab.getW()) || (y >= lab.getH())) out << " ";
				else {
					lab.get(x, y)->visit(out);
				}
			}
		}
	}
	*/
}
