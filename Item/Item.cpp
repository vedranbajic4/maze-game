// ==============================================
// Description:
// Source file containing definitions for class Item, and all derived classes
// 
// Author:
// Vedran Bajic SV10/2023
//
// Last Modified: 2024-28-12
// ==============================================

#include "Item.h"

Item::Item(int r, int c) : r(r), c(c), duration(3)
{
}

// shield constructor sets duration to 4 instead of 3, for practical causes
Shield::Shield(int r, int c) : Item(r, c)
{
	duration = 4;
}

inline void set_color(int color) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// these functions are override
std::string Fog_of_war::get_type() 
{
	return "Fog_of_war";
}

std::string Shield::get_type() 
{
	return "Shield";
}

std::string Hammer::get_type() 
{
	return "Hammer";
}

std::string Sword::get_type() 
{
	return "Sword";
}

// these functions are override for effect for item.
// every override function effect has duration--, for decreasing item duration
// 
// Shield sets Minotaur on position r, c, and prevents minotaur to eat robot
bool Shield::effect(Maze& maze, int r, int c) 
{
	duration--;
	maze[r][c] = 'M';
	return true;
}

// hammer effect returns condition if cell is block, so robot can go through wal
bool Hammer::effect(Maze& maze, int r, int c) 
{
	duration--;
	if (r < 0 || r >= maze.n || c < 0 || c >= maze.m) {
		return true;
	}
	return (maze[r][c] == 'U' || maze[r][c] == 'M');
}

// fog of war effect displays 3x3 submatrix, with center in r, c. Other cell's are ' '
bool Fog_of_war::effect(Maze& maze, int r, int c)
{
	duration--;
	std::cout << maze.n << " " << maze.m << std::endl;
	for (int i = 0; i < maze.n; i++) {
		for (int j = 0; j < maze.m; j++) {
			if (maze[i][j] == 'P') {
				set_color(9);
			}
			if (maze[i][j] == 'R') {
				set_color(10);
			}
			if (maze[i][j] == 'M') {
				set_color(12);
			}
			if (maze[i][j] == 'I') {
				set_color(11);
			}

			if (r - 1 <= i && i <= r + 1 && c - 1 <= j && j <= c + 1) {
				std::cout << maze[i][j];
			}
			else {
				std::cout << " ";
			}

			if (maze[i][j] == 'P' || maze[i][j] == 'R' || maze[i][j] == 'M' || maze[i][j] == 'I') {
				set_color(7);
			}
		}
		std::cout << std::endl;
	}
	return true;
}

// Sword effect returns condition if cell is minotaur, so that robot can kill him
bool Sword::effect(Maze& maze, int r, int c) 
{
	duration--;
	return (maze[r][c] == 'U' || maze[r][c] == '#');
}