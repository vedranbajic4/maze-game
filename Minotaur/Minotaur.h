// ==============================================
// Description:
// This module contains declaration for functions minotaur : play, set_position, etc
// 
// Author:
// Vedran Bajic SV10/2023
//
// Last Modified: 2024-28-12
// ==============================================
#pragma once
#include "Maze.h"
#include <utility>

typedef std::pair<int, int> pii;

class Minotaur {
public:
	//corindates of minotaur
	int r, c;
	
	//default constructor
	Minotaur();

	//constructor with parameters
	Minotaur(int x, int y);

	//main function play, given maze, returns wheter minotaur wins or not
	int play(Maze& m);

	//set position for minotaur given minotaurs coordinates
	void set_position(pii pos);
};