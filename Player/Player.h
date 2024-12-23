#pragma once
#include <utility>
#include <windows.h>
#include "Maze.h"

using namespace std;

class Player {
	int r, c;
	int handle_input(Maze& m);
public:
	void set_position(pii pos);
	Player();
	Player(pair<int, int> par);
	bool play(Maze& m);
};