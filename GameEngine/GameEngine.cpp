#include "GameEngine.h"

Game_engine::Game_engine(int n, int m2, int items_number)
	: maze(n, m2, items_number) {

	r.set_position(maze.get_position('R'));
	m.set_position(maze.get_position('M'));

	srand(512);
}

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

		r.play(maze);

		if (r.r == maze.n-1) {
			std::cout << "\n\nVICTORY\n";
			return;
		}

		prev_minotaur_pos = maze.get_position('M');
		played = m.play(maze);
		
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

		if (played) {
			std::cout << "\n\nLOST\n";
			return;
		}
	}
}