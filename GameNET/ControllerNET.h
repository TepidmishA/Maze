#pragma once
#include "ModelNET.h"

public ref class Controller {
	ModelNET^ model;

public:
	Controller(ModelNET^ _model) :model(_model) {}

	void step(int val);
};
