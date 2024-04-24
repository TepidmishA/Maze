#include "ControllerNET.h"

void Controller::step(int val)
{
	//int val = (int)e.KeyCode;

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