#pragma once

#include <utility>
#include <windows.h>
#include "Maze.h"
#include "Item.h"

class Robot {
	void set_random_item();
public:
	int r, c;
	Item* item;
	void set_position(pii pos);
	Robot();
	void play(Maze& m);
};