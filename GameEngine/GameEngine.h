#pragma once
#include "Player.h"
#include "Maze.h"

class Game_engine {
	Player p;
	Maze m;
public:
	Game_engine(int n, int m, int items_number);
	void run();
};