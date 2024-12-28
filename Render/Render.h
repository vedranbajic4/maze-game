#pragma once
#include <iostream>
#include <windows.h>

class Render {
	int n, m;

public:
	Render();
	
	Render(int n, int m);
	
	void display(char** board);

	void save();
};