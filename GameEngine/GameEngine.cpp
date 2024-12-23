#include "GameEngine.h"
#include <iostream>
using namespace std;

Game_engine::Game_engine(int n, int m2, int items_number)
	: m(n, m2, items_number) {

	p.set_position(m.get_position_robot());
	srand(512);
}

void Game_engine::run() {
	cout << "Running\n";
	int played;
	while (1) {
		m.display_maze();
		played = p.play(m);
		if (played == 0) {
			cout << "\n\nEXIT\n";
			return;
		}
		else if (played == 2) {
			cout << "\n\nVICTORY\n";
			return;
		}
		else if (played == 3) {
			cout << "\n\nLOST\n";
			return;
		}

		m.play_minotaur();
	}
}