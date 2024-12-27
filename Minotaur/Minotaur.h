#pragma once
#include "Maze.h"
#include <vector>
#include <utility>

using namespace std;
typedef pair<int, int> pii;

class Minotaur {
	int r, c;
public:
	Minotaur();
	Minotaur(int x, int y);
	int play(Maze& m);
	void set_position(pii pos);
};