#pragma once
#include "Maze.h"

class Minotaur {
public:
	int r, c;
	Minotaur();
	Minotaur(int x, int y);
	int play(Maze& m);
	void set_position(pii pos);
};