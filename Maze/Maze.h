#pragma once
#include "Render.h"

#include <utility>
#include <cstring>
#include <vector>

const int MXN = 300;
typedef std::pair<int, int> pii;

extern const pii direction[4];
extern int visited[MXN + 3][MXN + 3], glob;

class Maze {
	int items_number;
	char** board;
	Render render;

	void dfs(int r, int c);
	void generate();
	bool find_path(int r, int c);

public:
	int n, m;
	Maze(int n, int m, int items_number);
	pii get_position(const char target);
	
	void display_maze();
	int play_minotaur();
	~Maze();
	char*& operator[](int row);
};