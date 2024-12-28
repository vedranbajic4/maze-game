#include "Render.h"


Render::Render(int n, int m) : n(n), m(m){
}

Render::Render() : n(0), m(0){
}

inline void set_color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Render::display(char** board) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'P') {
				set_color(9);
			}
			if (board[i][j] == 'R') {
				set_color(10);
			}
			if (board[i][j] == 'M') {
				set_color(12);
			}
			if (board[i][j] == 'I') {
				set_color(11);
			}

			std::cout << board[i][j];

			if (board[i][j] == 'P' || board[i][j] == 'R' || board[i][j] == 'M' || board[i][j] == 'I') {
				set_color(7);
			}
		}
		std::cout << std::endl;
	}
}

void Render::save() {


}