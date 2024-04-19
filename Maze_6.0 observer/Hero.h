#pragma once
#include <stdio.h>
#include <iostream>

#include "ExceptionZeroHP.h"

using namespace std;

class Hero
{
	int x, y;
	int viewField = 2;
	int coins = 0;
	int hp = 10;
	bool exit = false;

public:
	Hero(int _x = 1, int _y = 1):x(_x), y(_y) {};

	int getX() { return x; };
	int getY() { return y; };
	int getView() { return viewField; };
	int getCoin() { return coins; }
	int getHP() { return hp; }
	
	void setExit() { exit = true; }
	int isExit() { return exit; }

	void move(int _x = 1, int _y = 1) { x = _x, y = _y; };
	void addCoin(int val = 1) { coins += val; }
	void getDamage(int val = 1);

	friend ostream& operator<<(ostream& out, const Hero& hero);
};