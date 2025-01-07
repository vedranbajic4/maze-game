// ==============================================
// Description:
// Source file containing definitions for class Maze
//
// Author:
// Vedran Bajic SV10/2023
//
// Last Modified: 2024-29-12
// ==============================================
#include "Maze.h"

Maze::Maze(unsigned int n, unsigned int m, unsigned int items_number) :
	n(n), m(m)
{

	render = Render(n, m);

	// dinamically alocating space for board
	board = new char*[n];
	for (int i = 0; i < n; i++) {
		board[i] = new char[m];
		memset(board[i], '#', m);
	}

	// creating class responsibile for maze generator
	Maze_generator mg(n, m, items_number);

	// Measuring the time for generating the maze
	auto start = std::chrono::high_resolution_clock::now();
	mg.generate(board);
	
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;

	std::cout << "Time to generate maze: " << duration.count() << " seconds" << std::endl;
}

// Destructor: Dynamically deallocating memory for the board
Maze::~Maze() 
{
	for (int i = 0; i < n; i++) {
		delete[] board[i];
	}
	delete[] board;
}

void Maze::display_maze() 
{
	render.display(board);
}

pii Maze::get_position(const char target) 
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == target) {
				return std::make_pair(i, j);
			}
		}
	}

	return std::make_pair(-1, -1);
}

char*& Maze::operator[](int row) 
{
	// Return a reference to the row
	if (row < 0 || row >= n) {
		throw std::out_of_range("Row index out of bounds");
	}
	return board[row];
}

void Maze::save_game() 
{
	render.save_game(board);
}