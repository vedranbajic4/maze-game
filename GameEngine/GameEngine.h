#pragma once
#include "Robot.h"
#include "Minotaur.h"

class Game_engine {
	Robot r;
	Minotaur m;
	Maze maze;
public:
	Game_engine(int n, int m, int items_number);
	void run();
};