#include "Labyrinth.h"


Labirinth::Labirinth(int _height, int _width)
{
	height = _height;
	width = _width;

	maze = new Cell ** [height];
	for (int i = 0; i < height; i++) {
		maze[i] = new Cell*[width];
	}

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (x % 2 == 1 && y % 2 == 1) maze[y][x] = new EmptyCell();
			else maze[y][x] = new Wall();
		}
	}

}

ostream& operator<<(ostream& out, const Labirinth& lab)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int y = 0; y < lab.height; y++) {
		for (int x = 0; x < lab.width; x++) {
			SetConsoleTextAttribute(hConsole, lab.maze[y][x]->getColor());
			for (int k = 0; k < CELL_SIZE; ++k) {
				lab.maze[y][x]->visit(out);
			}
		}
		out << endl;
	}
	out << endl;
	return out;
}


ofstream& operator<<(ofstream& ofs, const Labirinth& lab)
{
	for (int y = 0; y < lab.height; y++) {
		for (int x = 0; x < lab.width; x++) {
			lab.maze[y][x]->visit(ofs);
		}
		ofs << endl;
	}
	ofs << endl;
	return ofs;
}

ifstream& operator>>(ifstream& ifs, Labirinth& lab)
{
	for (int y = 0; y < lab.getH(); y++) {
		for (int x = 0; x < lab.getW(); x++) {
			ifs >> noskipws >> lab.get(x, y);
		}
		ifs.ignore(); // ignore \n
	}
	return ifs;
}

Labirinth::~Labirinth()
{
	
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			delete maze[i][j];
		}
		delete[] maze[i];
	}
	delete[] maze;
}

Labirinth::Labirinth(const Labirinth& lab)
{
	height = lab.height;
	width = lab.width;
	builder = lab.builder;
	
	maze = new Cell ** [height];
	for (int i = 0; i < height; i++) {
		maze[i] = new Cell*[width];
		for (int j = 0; j < width; j++) {
			maze[i][j] = lab.maze[i][j]->copy();
		}
	}
}

Labirinth& Labirinth::operator=(const Labirinth& lab)
{
	if (this == &lab) return *this;
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			delete maze[i][j];
		}
		delete[] maze[i];
	}
	delete[] maze;

	height = lab.height;
	width = lab.width;
	builder = lab.builder;

	maze = new Cell ** [height];
	for (int i = 0; i < height; i++) {
		maze[i] = new Cell*[width];
		for (int j = 0; j < width; j++) {
			maze[i][j] = lab.maze[i][j]->copy();
		}
	}
	return *this;
}

bool Labirinth::moveBuilt(MoveAction action)
{
	int x = builder.getX();
	int y = builder.getY();

	switch (action)
	{
	case LEFT:
		x -= 2;
		break;
	case RIGHT:
		x += 2;
		break;
	case UP:
		y -= 2;
		break;
	case DOWN:
		y += 2;
		break;
	default:
		break;
	}

	if ((x < 0) || (y < 0) || (x >= getW()) || (y >= getH()))
		return false;

	return !(maze[y][x]->isVisited());
}

char Labirinth::genDir(int& now_x, int& now_y)
{
	int free_dirr = 0;
	char dir[4]; // = { 'l', 'r', 'u', 'd' };

	if (moveBuilt(LEFT)) {
		dir[free_dirr] = 'l';
		free_dirr += 1;
	}
	if (moveBuilt(RIGHT)) {
		dir[free_dirr] = 'r';
		free_dirr += 1;
	}
	if (moveBuilt(UP)) {
		dir[free_dirr] = 'u';
		free_dirr += 1;
	}
	if (moveBuilt(DOWN)) {
		dir[free_dirr] = 'd';
		free_dirr += 1;
	}

	if (free_dirr == 0)	return '0';

	char choise = dir[(int)(((double)rand() / RAND_MAX) * free_dirr)];
	switch (choise)
	{
	case 'l':
		now_x -= 2;
		break;
	case 'r':
		now_x += 2;
		break;
	case 'u':
		now_y -= 2;
		break;
	case 'd':
		now_y += 2;
		break;
	default:
		break;
	}
	return choise;
}

void Labirinth::genMaze()
{
	// pick exit cell
	int exit_x = 0, exit_y = 0;
	while (exit_x % 2 == exit_y % 2) {
		exit_x = (int)(((double)rand() / RAND_MAX) * (getW() - 1));
		exit_y = (int)(((double)rand() / RAND_MAX) * (getH() - 1));
		int tmp = -1 + (int)(((double)rand() / RAND_MAX) * 2);
		if ((int)(((double)rand() / RAND_MAX) * 2) == 0) {
			tmp += getW();
			exit_x = tmp * (tmp == (getW() - 1));
		}
		else {
			tmp += getH();
			exit_y = tmp * (tmp == (getH() - 1));
		}
	}

	//maze[exit_y][exit_x] = new EmptyCell();
	//maze[exit_y][exit_x]->isExit(true);
	maze[exit_y][exit_x] = new ExitCell(COIN_COUNT);

	// pick start cell
	int player_x = 0, player_y = 0;
	randCoordGrid(player_x, player_y);
	builder.move(player_x, player_y);
	maze[player_y][player_x] = new HeroCell();

	// generate maze
	int not_visited_count = ((getH() - 1) / 2) * ((getW() - 1) / 2) - 1;
	int** path = init_matrix(((getH() - 1) / 2) * ((getW() - 1) / 2), 2);

	path[0][0] = player_x;
	path[0][1] = player_y;
	int depth_path = 1;
	int next_x = player_x, next_y = player_y;
	while (not_visited_count) {
		char move = genDir(next_x, next_y);
		if (move != '0') {
			switch (move)
			{
			case 'l':
				maze[next_y][next_x + 1] = new EmptyCell();
				break;
			case 'r':
				maze[next_y][next_x - 1] = new EmptyCell();
				break;
			case 'u':
				maze[next_y + 1][next_x] = new EmptyCell();
				break;
			case 'd':
				maze[next_y - 1][next_x] = new EmptyCell();
				break;
			default:
				break;
			}

			//Ход строителя
			Cell* tmp = maze[next_y][next_x];
			maze[next_y][next_x] = (*maze[next_y][next_x]) + builder;
			delete tmp;

			int builder_x = builder.getX(), builder_y = builder.getY();
			tmp = maze[builder_y][builder_x];
			maze[builder_y][builder_x] = (*maze[builder_y][builder_x]) - builder;
			delete tmp;

			builder.move(next_x, next_y);

			path[depth_path][0] = next_x;
			path[depth_path][1] = next_y;
			depth_path += 1;
			not_visited_count -= 1;
		}
		else { // 0 free cells, go back
			depth_path -= 1;

			Cell* tmp = maze[path[depth_path - 1][1]][path[depth_path - 1][0]];
			maze[path[depth_path - 1][1]][path[depth_path - 1][0]] = (*maze[path[depth_path - 1][1]][path[depth_path - 1][0]]) + builder;
			delete tmp;

			int builder_x = builder.getX(), builder_y = builder.getY();
			tmp = maze[builder_y][builder_x];
			maze[builder_y][builder_x] = (*maze[builder_y][builder_x]) - builder;
			delete tmp;

			builder.move(path[depth_path - 1][0], path[depth_path - 1][1]);
			
			next_x = builder.getX();
			next_y = builder.getY();
		}
	}
	int builder_x = builder.getX(), builder_y = builder.getY();
	Cell* tmp = maze[builder_y][builder_x];
	maze[builder_y][builder_x] = (*maze[builder_y][builder_x]) - builder;
	delete tmp;

	free_matrix(path, ((getH() - 1) / 2) * ((getW() - 1) / 2));

	for (int i = 0; i < COIN_COUNT; i++) newCoin();
	for (int i = 0; i < MONSTER_COUNT; i++) newMonster();
}

void Labirinth::randCoord(int& x, int& y)
{
	while (x < 1 || y < 1 || !maze[y][x]->canSetHero()) {
		x = (int)(((double)rand() / RAND_MAX) * (getW() - 1));
		y = (int)(((double)rand() / RAND_MAX) * (getH() - 1));
	}
}

void Labirinth::randCoordGrid(int& x, int& y)
{
	while (x % 2 != 1 || y % 2 != 1 || !maze[y][x]->canSetHero()) {
		x = (int)(((double)rand() / RAND_MAX) * (getW() - 1));
		y = (int)(((double)rand() / RAND_MAX) * (getH() - 1));
	}
}

void Labirinth::newCoin()
{
	int x = 0, y = 0;
	randCoordGrid(x, y);


	maze[y][x] = new Coin();
}

void Labirinth::newMonster()
{
	int x = 0, y = 0;
	randCoordGrid(x, y);

	maze[y][x] = new Monster();
}