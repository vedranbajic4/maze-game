// ==============================================
// Description:
// This module contains declaration for functions Robot
// 
// Author:
// Vedran Bajic SV10/2023
//
// Last Modified: 2024-29-12
// ==============================================
#pragma once

#include <utility>
#include <windows.h>
#include "Maze.h"
#include "Item.h"

class Robot {
	// function for assignign random item to robot
	void set_random_item();
public:
	// coridinates of robot
	int r, c;

	// Robot's item
	Item* item;

	// set position for robot, taking pair<int, int> as r, c
	void set_position(pii pos);

	// default constructor
	Robot();

	// main function play, taking maze, returning state of robot (exit, won, lost)
	int play(Maze& m);
};