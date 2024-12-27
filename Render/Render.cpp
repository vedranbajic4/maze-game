#include "Render.h"


Render::Render(int n, int m) {
	this->n = n;
	this->m = m;
}

Render::Render() {
	n = m = 0;
}

inline void set_color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Render::display(char** board) {
	std::cout << "MAZE:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'P') set_color(9);
			if (board[i][j] == 'R') set_color(10);
			if (board[i][j] == 'M') set_color(12);
			if (board[i][j] == 'I') set_color(11);

			std::cout << board[i][j];

			if (board[i][j] == 'P' || board[i][j] == 'R' || board[i][j] == 'M' || board[i][j] == 'I')
				set_color(7);
		}
		std::cout << std::endl;
	}
}

void Render::display(char** board, const int& n1, const int& m1, const int& n2, const int& m2) {

}

void Render::save() {


}