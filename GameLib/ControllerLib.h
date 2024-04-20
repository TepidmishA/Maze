#pragma once
#include "ModelLib.h"

class Controller {
	Model* model;

public:
	Controller(Model* _model) :model(_model) {}

	void start();
	void step(char val);
};
