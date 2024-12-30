// ==============================================
// Description:
// This module contains declaration of functions used for generating maze
// 
// Author:
// Vedran Bajic SV10/2023
//
// Last Modified: 2024-26-12
// ==============================================

#pragma once
#include <utility>
#include <vector>
#include <chrono>
#include <iostream>

typedef std::pair<int, int> pii;

// direction is 4 elements array, containing all 4 direction (UP, DOWN, LEFT, RIGHT)
extern const pii direction[4];

// visited and glob are used for dfs algorithm, marking visited cells with glob, and that way
// preventing loops in searching for exit
extern int glob;
extern int visited[303][303];

class Maze_generator {
	// parameters used for generating maze, dimension and number of items
	int n, m, items_number;
public:
	// constructors, default and with parameters
	Maze_generator();
	Maze_generator(int n, int m, int x);
	
	// method for generating maze. Putting blocks on random places, then checking if path from
	// Robot to exit exists. If not, remove the block, and repeat it until condition for number
	// of blocks isn't satisfied (at least 3 * dimension of maze)
	void generate(char** board);

	// find path use depth first search tehniqe to traverse the board, and find path from Robot to exit
	// it is recursive function and takes current cordinates (r, c) and board
	// returns true if path exists, false othervise
	bool find_path(int r, int c, char** board);
};