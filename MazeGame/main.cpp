// ==============================================
// Description:
// Source file, starting position of project.
// It makes game_engine that makes whole game.
// After that, saving last change in board in file
// 
// Author:
// Vedran Bajic SV10/2023
//
// Last Modified: 2024-26-12
// ==============================================
#include "GameEngine.h"

int main(int argc, char* argv[]) {
    // Wrong number of arguments
    if (argc != 4) {
        std::cerr << "Error: Wrong number of parameters" << std::endl;
        return 1;
    }

    // converting arguments to int
    int rows = std::atoi(argv[1]);
    int cols = std::atoi(argv[2]);
    int items_number = std::atoi(argv[3]);

    // Validating parameters
    if (rows <= 15 || cols <= 15 || items_number <= 3 || rows > MXN || cols > MXN) {
        std::cerr << "Error: Rows and columns must be >= 15, and the number of items must be >= 3." << std::endl;
        return 1;
    }

	Game_engine game(rows, cols, items_number);
	

    // running game
	game.run();

    // saving game
    game.save_game();

	return 0;
}