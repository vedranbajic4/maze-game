#pragma once
#include "Render.h"

#include <utility>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

const int MXN = 300;
typedef std::pair<int, int> pii;

extern const pii direction[4];
extern int visited[MXN + 3][MXN + 3], glob;

class Maze {
	int n, m, items_number;
	char** board;
	Render render;

	void dfs(int r, int c);
	void generate();
	void random_blocks();
	bool find_path(int r, int c);

public:
	Maze(int n, int m, int items_number);
	pii get_position(const char target);
	
	void display_maze();
	int play_minotaur();
	~Maze();
	char*& operator[](int row);
};