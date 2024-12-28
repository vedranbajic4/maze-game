#include "Minotaur.h"

Minotaur::Minotaur() : r(0), c(0){
}

Minotaur::Minotaur(int x, int y) : r(x), c(y){
}

void Minotaur::set_position(pii pos) {
	r = pos.first;
	c = pos.second;
}

int Minotaur::play(Maze& maze) {
	int n_rm = 0;
	int n_cm = 0;
	int ret = 0;
	
	if (maze[r][c] != 'M') {
		return 0;
	}

	std::vector<pii> possible;

	for (int i = 0; i < 4; i++) {
		n_rm = direction[i].first + r;
		n_cm = direction[i].second + c;

		if (maze[n_rm][n_cm] == 'R') {
			possible.clear();
			possible.push_back(std::make_pair(n_rm, n_cm));
			ret = 1;
			break;
		}
		else if (maze[n_rm][n_cm] == 'P' || maze[n_rm][n_cm] == '.') {
			possible.push_back(std::make_pair(n_rm, n_cm));
		}
	}
	int i = 0;

	i = rand() % (int)possible.size();
	maze[r][c] = '.';
	maze[possible[i].first][possible[i].second] = 'M';

	r = possible[i].first;
	c = possible[i].second;

	return ret;
}