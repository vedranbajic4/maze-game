#pragma once
#include "Render.h"
#include <utility>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

const int MXN = 300;

class Maze {
	int n, m, items_number;
	char** board;
	Render render;
	
	void dfs(int r, int c, int depth, bool& finish);
	void generate();
	void random_blocks();
	bool find_path(int r, int c);

public:
	Maze(int n, int m, int items_number);
	void display_maze();
	~Maze();
};