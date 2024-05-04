#include "ModelNET.h"

void ModelNET::addObsC()
{
	Omodel* tmp = new Omodel(this);
	modelC->addObserver(tmp);
}

ModelNET::ModelNET()
{
	modelC = new Model(10, 10);
	srand(time(NULL));
	modelC->genMaze();
	allODLL = gcnew List<ObserverNET^>(5);

	addObsC();
}

ModelNET::ModelNET(int h, int w)
{
	modelC = new Model(h, w);
	srand(time(NULL));
	modelC->genMaze();
	allODLL = gcnew List<ObserverNET^>(5);

	addObsC();
}
