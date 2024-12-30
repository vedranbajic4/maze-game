// ==============================================
// Description:
// Source file containing definitions for class Maze_generator
//
// Author:
// Vedran Bajic SV10/2023
//
// Last Modified: 2024-26-12
// ==============================================
#include "MazeGenerator.h"

// definiton of global variables
const pii direction[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int glob = 0;
int visited[303][303];

Maze_generator::Maze_generator(int n, int m, int items_number) : n(n), m(m), items_number(items_number){
}

Maze_generator::Maze_generator() : n(16), m(16), items_number(4) {

}

bool Maze_generator::find_path(int r, int c, char** board) {
	// marking current cell
	visited[r][c] = glob;
	
	//we are on the n-2 th row (n-1th row is #)
	if (r == n - 2) {
		return 1;
	}
	int nr = 0;
	int nc = 0;

	// searching all 4 directions, and if we can go, and weren't there, visit that cell
	for (int i = 0; i < 4; i++) {
		nr = r + direction[i].first;
		nc = c + direction[i].second;

		//not in board boundaries
		if (!(nr >= 0 && nr < n && nc < m && nc >= 0)) {
			continue;
		}
		if (board[nr][nc] != '.') {
			continue;
		}

		if (visited[nr][nc] != glob) {
			if (find_path(nr, nc, board)) {
				return 1;
			}
		}
	}

	return false;
}

void Maze_generator::generate(char** board) {
	std::vector<int> numbers;

	int entrance = 0;
	int limit = 0;
	int id = 0;
	int nr = 0;
	int nc = 0;
	int num_blocks = 0;

	while (num_blocks < 3 * (n + m)) {
		// mapping cells in board to integers
		numbers.clear();
		for (int i = 0; i < n * m; i++) {
			numbers.push_back(i);
		}
		// filling outside layer of board with walls (#)
		memset(board[0], '#', m);
		memset(board[n - 1], '#', m);
		for (int i = 1; i < n - 1; i++) {
			memset(board[i], '.', m);
			board[i][0] = board[i][m - 1] = '#';
		}
		// chosing entrance
		entrance = rand() % (m - 2) + 2;
		board[0][entrance] = 'U';
		board[1][entrance] = 'R';

		limit = n * m;
		num_blocks = 0;

		for (int i = 1; i <= n * m; i++) {
			// chose random cell (nr, nc)
			id = rand() % limit;
			nr = numbers[id] / m;
			nc = numbers[id] % m;

			std::swap(numbers[id], numbers[limit - 1]);
			numbers.pop_back();
			limit--;
			
			if (board[nr][nc] == 'U' || board[nr][nc] == 'R') {
				continue;
			}

			if (board[nr][nc] == '.') {
				num_blocks++;
			}

			board[nr][nc] = '#';
			// if robot cant find path to exit, we remove the block and decrease number of put blocks
			glob++;
			if (!find_path(1, entrance, board)) {
				board[nr][nc] = '.';
				num_blocks--;
			}
			if (num_blocks == 3 * (n + m)) break;
		}
	}
	
	// putting minotaur on random cell in the board, but ensuring he and robot can meet
	while (1) {
		id = rand() % (n * m);

		nr = id / m;
		nc = id % m;

		if (board[nr][nc] == '.' && visited[nr][nc] == glob) {
			board[nr][nc] = 'M';
			break;
		}
	}

	// putting items on random cells
	numbers.clear();
	for (int i = 0; i < n * m; i++) {
		numbers.push_back(i);
	}
	limit = n * m;

	int items = items_number;

	while (limit > 0 && items > 0) {
		// same algorithm, chosing random empty cell
		id = rand() % limit;
		nr = numbers[id] / m;
		nc = numbers[id] % m;

		std::swap(numbers[id], numbers[limit - 1]);
		numbers.pop_back();
		limit--;

		if (board[nr][nc] != '.') {
			continue;
		}
		items--;
		board[nr][nc] = 'P';
	}

	//finding all possible cells where we can put exit
	std::vector<int> possible;
	for (int i = 0; i < m; i++) {
		if (visited[n - 2][i] == glob) {
			possible.push_back(i);
		}
	}
	//exit is on last row, random (valid) collumn 
	int i;
	i = rand() % (int)possible.size();
	board[n - 1][possible[i]] = 'I';
}