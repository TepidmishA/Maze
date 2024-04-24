#pragma once
#include "ModelNET.h"

public ref class Controller {
	ModelNET^ model;

public:
	Controller(ModelNET^ _model) :model(_model) {}

	//void start();
	//void step(KeyEventArgs e);
	void step(int val);
};
