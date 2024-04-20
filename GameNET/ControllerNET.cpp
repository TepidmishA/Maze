#include "ControllerNET.h"

/*
void Controller::start()
{
	//model->start();
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
*/

void Controller::step(int val)
{
	switch (val)
	{
	case 40:
		(*model).move(DOWN);
		break;
	case 38:
		(*model).move(UP);
		break;
	case 39:
		(*model).move(RIGHT);
		break;
	case 37:
		(*model).move(LEFT);
		break;
	}
}