#pragma once
#include "Maze.h"

using namespace std;

class Item {
public:
	int r, c;
	int duration;
	Item();
	Item(int r, int c);
	virtual string get_type() = 0;
	virtual bool effect(Maze& maze, int r, int c) = 0;
};

class Fog_of_war : public Item {
public:
	using Item::Item;
	string get_type() override;
	bool effect(Maze& maze, int r, int c) override;
};

class Hammer : public Item {
	using Item::Item;
	string get_type() override;
	bool effect(Maze& maze, int r, int c) override;
};

class Sword : public Item {
	using Item::Item;
	string get_type() override;
	bool effect(Maze& maze, int r, int c) override;
};

class Shield : public Item {
	string get_type() override;
	bool effect(Maze& maze, int r, int c) override;
public:
	Shield(int r, int c);
	
};