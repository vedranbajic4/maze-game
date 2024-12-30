// ==============================================
// Description:
// This module contains declaration of functions used for game engine (run, save_game...)
// 
// Author:
// Vedran Bajic SV10/2023
//
// Last Modified: 2024-29-12
// ==============================================
#pragma once
#include "Robot.h"
#include "Minotaur.h"

class Game_engine {
	// Robot in game
	Robot r;

	// Minotaur in game
	Minotaur m;

	// Maze in game
	Maze maze;

	void display_start();
public:
	Game_engine(int n, int m, int items_number);

	// Run function. It is responsible for robot and minotaur playing, game interaction, etc...
	void run();

	// Saves last modification of game in file maze.txt
	void save_game();
};