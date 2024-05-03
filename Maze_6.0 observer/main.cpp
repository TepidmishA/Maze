#include "ModelLib.h"
#include "ControllerLib.h"

int main() {
	srand(time(NULL));

	Model game(10, 10);
	Controller c(&game);

	ShowStepCnt viewCnt(cout);
	ShowCollectedCoin viewCoin(cout);
	ShowHP viewHP(cout);
	ShowAround viewAround(cout);
	ShowAllMap viewMap(cout);
	
	game.addObserver(&viewCnt);
	game.addObserver(&viewCoin);
	game.addObserver(&viewHP);
	game.addObserver(&viewAround);
	game.addObserver(&viewMap);

	game.genMaze();
	game.saveMaze("test.txt");
	//c.readMaze("test.txt");

	c.start();

	return 0;
}