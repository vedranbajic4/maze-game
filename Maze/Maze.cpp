#include "Maze.h"

using namespace std;
typedef pair<int, int> pii;

Maze::Maze(int n, int m, int items_number) {
	this->n = n;
	this->m = m;
	this->items_number = items_number;

	render = Render(n, m);

	board = new char*[n];
	for (int i = 0; i < n; i++) {
		board[i] = new char[m];
		memset(board[i], '#', m);
	}
	generate();
}

Maze::~Maze() {
	for (int i = 0; i < n; i++) {
		delete[] board[i];
	}
	delete[] board;
}

pii direction[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int visited[MXN+3][MXN+3], glob;

void Maze::dfs(int r, int c, int depth, bool& finish){
	if (finish) return;
	cout << depth << endl;
	int dir, nr, nc;
	board[r][c] = '.';

	//display_maze();

	if (depth >= n * m / 2) {
		
		finish = 1;
		return;
	}
	if (r == -1) {
		finish = 1;
		return;
	}
	//return;
	for(int i = 1; i <= 100; i++) {
		dir = rand();
		//cout << dir << " " << (dir & 3) << endl;
		dir = (dir & 3);

		nr = r + direction[dir].first;
		nc = c + direction[dir].second;

		if (!(nr >= 1 && nr < (n-1) && nc < (m-1) && nc >= 1)) continue;
		
		if (board[nr][nc] == '#') {
			dfs(nr, nc, depth+1, finish);
		}
	}
}


bool Maze::find_path(int r, int c) {
	visited[r][c] = glob;
	if (r == n - 2) {
		return 1;
	}
	int nr, nc;
	for (int i = 0; i < 4; i++) {
		nr = r + direction[i].first;
		nc = c + direction[i].second;

		if (!(nr >= 0 && nr < n && nc < m && nc >= 0)) continue;
		if (board[nr][nc] != '.') continue;

		if (visited[nr][nc] != glob) {
			if (find_path(nr, nc))
				return 1;
		}
	}

	return false;
}

void Maze::random_blocks() {
	vector<int> numbers;
	

	int entrance, limit, id, nr, nc, num_blocks;
	bool found = false;

	while (!found) {
		for (int i = 0; i < n * m; i++)
			numbers.push_back(i);
		memset(board[0], '#', m);
		memset(board[n-1], '#', m);
		for (int i = 1; i < n-1; i++) {
			memset(board[i], '.', m);
			board[i][0] = board[i][m - 1] = '#';
		}
		entrance = rand() % (m - 2) + 2;
		board[0][entrance] = 'U';
		board[1][entrance] = 'R';
		
		limit = n * m;
		num_blocks = 0;

		for (int i = 1; i <= n * m; i++) {
			id = rand() % limit;
			//cout << id << " ";
			nr = numbers[id] / m;
			nc = numbers[id] % m;
			//cout << nr << ", " << nc << endl;

			swap(numbers[id], numbers[limit - 1]);
			numbers.pop_back();
			limit--;

			if (board[nr][nc] == 'U' || board[nr][nc] == 'R') continue;
			
			if(board[nr][nc] == '.') num_blocks++;

			board[nr][nc] = '#';
			glob++;
			if (!find_path(1, entrance)) {
				//display_maze();
				board[nr][nc] = '.';
				num_blocks--;
			}

			if (num_blocks >= (n * m / 3 - items_number)) {
				found = true;
				break;
			}
		}
	}
	//cout << ":Sve gotoov\n";
	//return;
	while (1) {
		id = rand() % (n * m);
		nr = id / m;
		nc = id % m;
		//cout << nr << ", " << nc << " " << board[nr][nc] << endl;

		if (board[nr][nc] == '.' && visited[nr][nc] == glob) {
			board[nr][nc] = 'M';
			break;
		}
	}
	//cout << "Pravim iteme\n";
	numbers.clear();
	for (int i = 0; i < n * m; i++)
		numbers.push_back(i);
	limit = n * m;

	int items = items_number;
	
	while(limit > 0 && items > 0){
		id = rand() % limit;

		nr = numbers[id] / m;
		nc = numbers[id] % m;

		swap(numbers[id], numbers[limit - 1]);
		numbers.pop_back();
		limit--;

		if (board[nr][nc] != '.') continue;
		items--;
		board[nr][nc] = 'P';
	}

	cout << "left items: " << items << endl;

}

void Maze::generate() {
	bool finish = false;
	//cout << "generating maze\n";
	//dfs(n - 1, m / 2, 0, finish);
	random_blocks();
}

void Maze::display_maze() {
	render.display(board);
}
