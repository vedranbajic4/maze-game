// ==============================================
// Description:
// Source file containing definitions for class Game engine
// 
// Author:
// Vedran Bajic SV10/2023
//
// Last Modified: 2024-29-12
// ==============================================
#include "GameEngine.h"

Game_engine::Game_engine(int n, int m2, int items_number)
	: maze(n, m2, items_number) {

	// starting position of Robot and Minotaur
	r.set_position(maze.get_position('R'));
	m.set_position(maze.get_position('M'));

	srand(52);
}

// Before maze board, displays important things about item.
void Game_engine::display_start() {
	std::cout << "Item: ";
	if (r.item != nullptr) {
		if (r.item->duration <= 0) {
			std::cout << "None" << std::endl;
			maze.display_maze();
			return;
		}
		std::cout << r.item->get_type() << std::endl;
		if (r.item->get_type() == "Fog_of_war" && r.item->duration > 0) {
			r.item->effect(maze, r.r, r.c);
		}
		else {
			maze.display_maze();
		}
	}
	else {
		std::cout << "None" << std::endl;
		maze.display_maze();
	}
}

void Game_engine::run() {
	int played = 0;
	pii prev_minotaur_pos;

	while (1) {
		display_start();

		// Robot's turn
		played = r.play(maze);

		// End game
		if (r.r == maze.n-1) {
			std::cout << "\n\nVICTORY\n";
			return;
		}
		if (played == 2) {
			std::cout << "\n\nEXIT\n";
			return;
		}

		prev_minotaur_pos = maze.get_position('M');
		
		// Minotaur's turn
		played = m.play(maze);
		
		// Checking for item
		if (r.item != nullptr) {
			if (r.item->get_type() == "Shield"){
				if (r.item->duration > 0 && played) {
					played = 0;
					maze[m.r][m.c] = 'R';
					m.set_position(prev_minotaur_pos);
				}
				r.item->effect(maze, m.r, m.c);
			}
		}

		// Minotaur wins
		if (played) {
			std::cout << "\n\nLOST\n";
			return;
		}
	}
}

void Game_engine::save_game() {
	maze.save_game();
}