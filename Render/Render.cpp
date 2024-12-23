#include "Render.h"
#include <iostream>

Render::Render(int n, int m) {
	this->n = n;
	this->m = m;
}

Render::Render() {
	n = m = 0;
}

void Render::display(char** board) {
	std::cout << "\nLAVIRINT:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			std::cout << board[i][j];
		std::cout << std::endl;
	}
}

void Render::display(char** board, const int& n1, const int& m1, const int& n2, const int& m2) {
	
}

void Render::save() {


}