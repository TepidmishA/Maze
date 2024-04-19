#include "Model.h"

Model::Model(int _height, int _width)
{
	lab = Labirinth(_height * 2 + 1, _width * 2 + 1);
}

void Model::move(MoveAction action)
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


void ShowAround::evnt(Model& model)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	Labirinth& lab = model.getLab();
	Hero& hero = model.getHero();

	out << endl;
	for (int y = hero.getY() - hero.getView(); y < hero.getY() + 1 + hero.getView(); y++) {
		for (int x = hero.getX() - hero.getView(); x < hero.getX() + 1 + hero.getView(); x++) {
			for (int k = 0; k < CELL_SIZE; k++) {
				if ((x < 0) || (y < 0) || (x >= lab.getW()) || (y >= lab.getH())) out << " ";
				else {
					SetConsoleTextAttribute(hConsole, lab.get(x, y)->getColor());
					lab.get(x, y)->visit(out);
				}
			}
		}
		out << endl;
	}
	out << endl;
}

