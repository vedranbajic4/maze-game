#include <iostream>
#include "Maze.h"


int main() {
	srand(512);

	Maze m(31, 40, 50);
	
	m.display_maze();

	std::cout << "Main pocinje\n";
	return 0;
}