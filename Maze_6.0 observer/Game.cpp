#include "Game.h"

void Game::randCoord(int& x, int& y)
{
	while (x < 1 || y < 1 || !lab.get(x, y)->canSetHero()) {
		x = (int)(((double)rand() / RAND_MAX) * (lab.getW() - 1));
		y = (int)(((double)rand() / RAND_MAX) * (lab.getH() - 1));
	}
}

void Game::randCoordGrid(int& x, int& y)
{
	while (x % 2 != 1 || y % 2 != 1 || !lab.get(x, y)->canSetHero()) {
		x = (int)(((double)rand() / RAND_MAX) * (lab.getW() - 1));
		y = (int)(((double)rand() / RAND_MAX) * (lab.getH() - 1));
	}
}

void Game::startCell()
{
	int x = 0, y = 0;
	randCoord(x, y);

	lab.get(x, y) = new HeroCell();
	hero.move(x, y);
}

Game::Game(int _height, int _width)
{
	lab = Labirinth(_height * 2 + 1, _width * 2 + 1);
}

void Game::move(MoveAction action)
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
}

void Game::printAround()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "HP: " << hero.getHP() << endl;
	cout << "Coins collected: " << hero.getCoin() << endl << endl;
	for (int y = hero.getY() - hero.getView(); y < hero.getY() + 1 + hero.getView(); y++) {
		for (int x = hero.getX() - hero.getView(); x < hero.getX() + 1 + hero.getView(); x++) {
			for (int k = 0; k < CELL_SIZE; k++) {
				if ((x < 0) || (y < 0) || (x >= lab.getW()) || (y >= lab.getH())) cout << " ";
				else {
					SetConsoleTextAttribute(hConsole, lab.get(x, y)->getColor());
					lab.get(x, y)->visit(cout);
				}
			}
		}
		cout << endl;
	}
	cout << endl;
}

void Game::readMaze(const string& fileName)
{
	ifstream file(fileName);
	int height, width;
	file >> width >> height;
	file.ignore();

	lab = Labirinth(height, width);
	file >> lab;

	startCell();
}

void Game::saveMaze(const string& fileName)
{
	ofstream file(fileName);
	int playerX = hero.getX(), playerY = hero.getY();
	*lab.get(playerX, playerY) = EmptyCell();

	file << lab.getW() << ' ' << lab.getH() << endl;
	file << lab;
	*lab.get(playerX, playerY) = HeroCell();
}

void Game::genMaze()
{
	lab.genMaze();
	//for (int i = 0; i < 4; i++) newCoin();
	//for (int i = 0; i < 2; i++) newMonster();
	startCell();
}