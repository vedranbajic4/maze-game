#pragma once

#include <utility>
#include <windows.h>
#include "Maze.h"

using namespace std;
typedef pair<int, int> pii;

class Robot {
	int r, c;
public:
	void set_position(pii pos);
	Robot();
	Robot(pair<int, int> par);
	int play(Maze& m);
};