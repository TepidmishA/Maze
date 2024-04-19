#include "func.h"
//#include "Game.h"
#include "Model.h"
#include "Controller.h"

/*
int main() {
	srand(time(NULL));

	Game g(10, 10);
	g.genMaze();
	g.saveMaze("test.txt");
	//g.readMaze("test.txt");

	unsigned char val = 0;

	try {
		while (val != 27)
		{
			g.printAround();
			g.printMaze();

			val = _getch();
			if (val == 224) {
				system("cls");
				val = _getch();
			}

			switch (val)
			{
			case 80:
				g.move(DOWN);
				break;
			case 72:
				g.move(UP);
				break;
			case 77:
				g.move(RIGHT);
				break;
			case 75:
				g.move(LEFT);
				break;
			}
		}
	}
	catch (ExceptionZeroHP e) {
		cout << e.what();
		cout << endl << "You lose!";
	}
	catch (ExceptionWin e) {
		cout << e.what();
	}
	return 0;
}
*/

int main() {
	srand(time(NULL));

	Model game(10, 10);
	Controller c(&game);

	ShowStepCnt viewCnt(cout);
	ShowcollectedCoin viewCoin(cout);
	ShowHP viewHP(cout);
	ShowAround viewAround(cout);
	ShowAllMap viewMap(cout);
	
	game.addObserver(&viewCnt);
	game.addObserver(&viewCoin);
	game.addObserver(&viewHP);
	game.addObserver(&viewAround);
	game.addObserver(&viewMap);

	c.genMaze();
	c.saveMaze("test.txt");
	//c.readMaze("test.txt");

	c.start();

	return 0;
}