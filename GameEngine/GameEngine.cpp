#include "GameEngine.h"
#include <iostream>
using namespace std;

Game_engine::Game_engine(int n, int m2, int items_number)
	: maze(n, m2, items_number) {

	r.set_position(maze.get_position('R'));
	m.set_position(maze.get_position('M'));

	srand(512);
}

void Game_engine::run() {
	cout << "Running\n";
	int played;
	while (1) {
		maze.display_maze();
		played = r.play(maze);
		if (played == 0) {
			cout << "\n\nEXIT\n";
			return;
		}
		else if (played == 2) {
			cout << "\n\nVICTORY\n";
			return;
		}

		played = m.play(maze);

		if (played) {
			cout << "\n\nLOST\n";
			return;
		}
	}
}