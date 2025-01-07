// ==============================================
// Description:
// This module contains declaration of class Maze
// 
// Author:
// Vedran Bajic SV10/2023
//
// Last Modified: 2024-29-12
// ==============================================
#pragma once
#include "Render.h"
#include "MazeGenerator.h"
#include <cstring>

// maximal dimension for Maze
const unsigned int MXN = 300;

class Maze {
	// board** represent 2D matrix for playing board (maze)
	char** board;

	// render class used for displaying maze
	Render render;

public:
	// dimensions of maze
	unsigned int n, m;

	// constructor with paramters
	Maze(unsigned int n, unsigned int m, unsigned int items_number);

	// returns position of character Robot('R') or Minotaur('M')
	pii get_position(const char target);
	
	void display_maze();
	void save_game();

	~Maze();

	// overloaded operator, returns board[i][j]
	char*& operator[](int row);
};