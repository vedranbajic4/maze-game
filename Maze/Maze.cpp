#include "Maze.h"

using namespace std;

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

const pii direction[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int glob = 0;
int visited[303][303];

void Maze::dfs(int r, int c){
	int nr = 0, nc = 0;
	visited[r][c] = glob;
	//return;
	for(int i = 0; i < 4; i++) {
		nr = r + direction[i].first;
		nc = c + direction[i].second;

		if (!(nr >= 0 && nr < n && nc < m && nc >= 0)) continue;
		
		if (visited[nr][nc] != glob && board[nr][nc] != '#') 
			dfs(nr, nc);
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
	glob ++;
	for (int i = 0; i < m; i++) {
		if (board[1][i] == 'R') {
			dfs(1, i);
			break;
		}
	}
	
	vector<int> possible;
	for (int i = 0; i < m; i++) {
		if (visited[n - 2][i] == glob) {
			cout << i << " ";
			possible.push_back(i);
		}
	}
	cout << endl;
	int i;
	i = rand() % (int)possible.size();
	board[n-1][possible[i]] = 'I';
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

pii Maze::get_position(const char target) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == target)
				return make_pair(i, j);
		}
	}

	return make_pair(-1, -1);
}

int Maze::play_minotaur() {
	int rm = -1, cm = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'M') {
				rm = i;
				cm = j;
				break;
			}
		}
	}
	int n_rm, n_cm, ret = 0;
	vector<pii> possible;
	for (int i = 0; i < 4; i++) {
		n_rm = direction[i].first + rm;
		n_cm = direction[i].second + cm;

		if (!(n_rm >= 0 && n_rm < n && n_cm < m && n_cm >= 0)) {
			continue;
		}
		else if (board[n_rm][n_cm] == '#') {
			continue;
		}
		else if (board[n_rm][n_cm] == 'R') {
			possible.clear();
			possible.push_back(make_pair(n_rm, n_cm));
			ret = 1;
			break;
		}
		else {
			possible.push_back(make_pair(n_rm, n_cm));
		}
	}
	int i;
	
	i = rand() % (int)possible.size();
	board[rm][cm] = '.';
	board[possible[i].first][possible[i].second] = 'M';

	return ret;
}

char*& Maze::operator[](int row) {
	// Return a reference to the row
	if (row < 0 || row >= m) {
		throw std::out_of_range("Row index out of bounds");
	}
	return board[row];
}