#include "Item.h"

Item::Item(int r, int c) : r(r), c(c), duration(3){
}

Shield::Shield(int r, int c) : Item(r, c) {
	duration = 4;
}

inline void set_color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

string Fog_of_war::get_type() {
	return "Fog_of_war";
}

string Shield::get_type() {
	return "Shield";
}

string Hammer::get_type() {
	return "Hammer";
}

string Sword::get_type() {
	return "Sword";
}

bool Shield::effect(Maze& maze, int r, int c) {
	duration--;
	maze[r][c] = 'M';
	return true;
}

bool Hammer::effect(Maze& maze, int r, int c) {
	duration--;
	if (r < 0 || r >= maze.n || c < 0 || c >= maze.m) {
		return true;
	}
	return (maze[r][c] == 'U' || maze[r][c] == 'M');
}

bool Fog_of_war::effect(Maze& maze, int r, int c) {
	duration--;
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

bool Sword::effect(Maze& maze, int r, int c) {
	duration--;
	return (maze[r][c] == 'U' || maze[r][c] == '#');
}