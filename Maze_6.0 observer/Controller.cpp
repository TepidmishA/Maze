#include "Controller.h"

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