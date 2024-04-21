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
		//throw gcnew ExceptionCellAddNET();
		// cout << e.what()
	}
	catch (ExceptionExit e) {
		//throw gcnew ExceptionExitNET();
		// cout << e.what()
	}
	catch (ExceptionZeroHP e) {
		throw gcnew ExceptionZeroHPNET();
	}
	catch (ExceptionWin e) {
		throw gcnew ExceptionWinNET();
	}
	stepCnt++;
	evnt();
}

void ModelNET::paintAround(Panel^ p)
{
	Graphics^ g = p->CreateGraphics();
	g->Clear(Color::White);


	for (int y = hero.getY() - hero.getView(); y < hero.getY() + 1 + hero.getView(); y++) {
		for (int x = hero.getX() - hero.getView(); x < hero.getX() + 1 + hero.getView(); x++) {
			//for (int k = 0; k < CELL_SIZE; k++) {
			int drawX = (x - (hero.getX() - hero.getView())) * CELLSIZE;
			int drawY = (y - (hero.getY() - hero.getView())) * CELLSIZE;

			char val = ' ';
			Color color = Color::White;

			if ((x < 0) || (y < 0) || (x >= lab.getW()) || (y >= lab.getH())) val = ' ';
			else {
				ostringstream ss;
				lab.get(x, y)->visit(ss);
				val = ss.str()[0];
				//color = Color::FromArgb(lab.get(x, y)->getColor());
				color = Color::Black;
			}
			Brush^ brush = gcnew SolidBrush(color);
			String^ symbolStr = Char::ToString(val);
			g->DrawString(symbolStr, gcnew Font("Verdana", CELLSIZE), brush, drawX, drawY);
		}
	}
}

void ModelNET::paintAll(Panel^ p)
{
	Graphics^ g = p->CreateGraphics();
	g->Clear(Color::White);

	for (int y = 0; y < lab.getH(); y++) {
		for (int x = 0; x < lab.getW(); x++) {
			int drawX = x * CELLSIZE;
			int drawY = y * CELLSIZE;

			char val = ' ';
			Color color = Color::White;
			ostringstream ss;
			lab.get(x, y)->visit(ss);
			val = ss.str()[0];
			//color = Color::FromArgb(lab.get(x, y)->getColor());
			color = Color::Black;

			Brush^ brush = gcnew SolidBrush(color);
			String^ symbolStr = Char::ToString(val);
			g->DrawString(symbolStr, gcnew Font("Verdana", CELLSIZE), brush, drawX, drawY);

		}
	}
}
