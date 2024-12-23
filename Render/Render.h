#pragma once

class Render {
	int n, m;

public:
	Render();

	Render(int n, int m);

	void display(char** board);

	void display(char** board, const int& n1, const int& m1, const int& n2, const int& m2);

	void save();
};