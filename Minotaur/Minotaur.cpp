#include "Minotaur.h"

Minotaur::Minotaur() {
	r = c = 0;
}

Minotaur::Minotaur(int x, int y) {
	r = x;
	c = y;
}

void Minotaur::set_position(pii pos) {
	r = pos.first;
	c = pos.second;
}

//pii direction[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int Minotaur::play(Maze& maze) {
	int n_rm, n_cm, ret = 0;
	vector<pii> possible;

	for (int i = 0; i < 4; i++) {
		n_rm = direction[i].first + r;
		n_cm = direction[i].second + c;

		if (maze[n_rm][n_cm] == 'R') {
			possible.clear();
			possible.push_back(make_pair(n_rm, n_cm));
			ret = 1;
			break;
		}
		else if (maze[n_rm][n_cm] == 'P' || maze[n_rm][n_cm] == '.') {
			possible.push_back(make_pair(n_rm, n_cm));
		}
	}
	int i;

	i = rand() % (int)possible.size();
	maze[r][c] = '.';
	maze[possible[i].first][possible[i].second] = 'M';

	r = possible[i].first;
	c = possible[i].second;

	return ret;
}