// ==============================================
// Description:
// This module contains declaration of functions used mainly for displaying  
// game to the player through the console, on standard output
// 
// Author:
// Vedran Bajic SV10/2023
//
// Last Modified: 2024-25-12
// ==============================================

#pragma once
#include <iostream>
#include <windows.h>
#include <fstream>

class Render {
	int n, m; // Number of rows (n) and columns (m) of the game board

public:
	Render();

	// Constructor with parameters (dimension of the board)
	Render(int n, int m);
	
	// Displaying board on the console
	void display(char** board);

	// Saving game on the end, displaying the outcome and the maze image after the last move.
	// Save content is in maze.txt
	void save_game(char** board);
};