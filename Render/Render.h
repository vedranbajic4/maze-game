// ==============================================
// Description:
// This module contains declaration of functions used mainly for displaying  
// game to the player through the console, on standard output
// 
// Author:
// Vedran Bajic SV10/2023
//
// Last Modified: 2024-5-1
// ==============================================

#pragma once
#include <iostream>
#include <windows.h>
#include <fstream>

class Render {
	unsigned int n, m; // Number of rows (n) and columns (m) of the game board

public:
	Render();

	// Constructor with parameters (dimension of the board)
	Render(unsigned int n, unsigned int m);
	
	// Displaying board on the console
	void display(char** board);

	// Saving game on the end, displaying the outcome and the maze image after the last move.
	// Save content is in maze.txt
	void save_game(char** board);
};