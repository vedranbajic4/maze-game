// ==============================================
// Description:
// Source file containing definitions for class Render
//
// Author:
// Vedran Bajic SV10/2023
//
// Last Modified: 2024-5-1
// ==============================================
#include "Render.h"


Render::Render(unsigned int n, unsigned int m) : n(n), m(m)
{
}

Render::Render() : n(0), m(0)
{
}

// used for aesthetic, sets color for coming text output
inline void set_color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Render::display takes 2D pointer board, and outputs it on console
// Color for special characters are:
// Robot(R)    : green
// Minotaur(M) : red
// Item(P)     : blue
// Exit(I)     : light blue
void Render::display(char** board) 
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'P') {
				set_color(9);
			}
			if (board[i][j] == 'R') {
				set_color(10);
			}
			if (board[i][j] == 'M') {
				set_color(12);
			}
			if (board[i][j] == 'I') {
				set_color(11);
			}

			std::cout << board[i][j];

			if (board[i][j] == 'P' || board[i][j] == 'R' || board[i][j] == 'M' || board[i][j] == 'I') {
				set_color(7);
			}
		}
		std::cout << std::endl;
	}
}

// Saves game in file maze.txt
void Render::save_game(char** board) 
{
	std::cout << "Saving game\n";
	std::ofstream file("maze.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			file << board[i][j];
		}
		file << std::endl;
	}
	file.close();
}