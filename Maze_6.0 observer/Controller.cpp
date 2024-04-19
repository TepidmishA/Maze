#include "Controller.h"

void Controller::randCoord(int& x, int& y)
{
	Labirinth& lab = model->getLab();
	while (x < 1 || y < 1 || !lab.get(x, y)->canSetHero()) {
		x = (int)(((double)rand() / RAND_MAX) * (lab.getW() - 1));
		y = (int)(((double)rand() / RAND_MAX) * (lab.getH() - 1));
	}
}

void Controller::randCoordGrid(int& x, int& y)
{
	Labirinth& lab = model->getLab();
	while (x % 2 != 1 || y % 2 != 1 || !lab.get(x, y)->canSetHero()) {
		x = (int)(((double)rand() / RAND_MAX) * (lab.getW() - 1));
		y = (int)(((double)rand() / RAND_MAX) * (lab.getH() - 1));
	}
}

void Controller::startCell()
{
	Labirinth& lab = model->getLab();
	Hero& hero = model->getHero();

	int x = 0, y = 0;
	randCoord(x, y);

	lab.get(x, y) = new HeroCell();
	hero.move(x, y);
}

void Controller::start()
{
	model->start();
	unsigned char val = 0;

	try {
		while (val != 27)
		{
			val = _getch();
			if (val == 224) {
				system("cls");
				val = _getch();
			}

			step(val);
		}
	}
	catch (ExceptionZeroHP e) {
		cout << e.what();
		cout << endl << "You lose!";
	}
	catch (ExceptionWin e) {
		cout << e.what();
	}
}

void Controller::step(char val)
{
	switch (val)
	{
	case 80:
		model->move(DOWN);
		break;
	case 72:
		model->move(UP);
		break;
	case 77:
		model->move(RIGHT);
		break;
	case 75:
		model->move(LEFT);
		break;
	}
}

void Controller::genMaze()
{
	model->getLab().genMaze();
	startCell();
}

void Controller::readMaze(const string& fileName)
{
	Labirinth& lab = model->getLab();

	ifstream file(fileName);
	int height, width;
	file >> width >> height;
	file.ignore();

	lab = Labirinth(height, width);
	file >> lab;

	startCell();
}

void Controller::saveMaze(const string& fileName)
{
	Labirinth& lab = model->getLab();
	Hero& hero = model->getHero();

	ofstream file(fileName);
	int playerX = hero.getX(), playerY = hero.getY();
	*lab.get(playerX, playerY) = EmptyCell();

	file << lab.getW() << ' ' << lab.getH() << endl;
	file << lab;
	*lab.get(playerX, playerY) = HeroCell();
}
