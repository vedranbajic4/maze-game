// ==============================================
// Description:
// This module contains declaration for functions of Item, and 
// all derived classes
// 
// Author:
// Vedran Bajic SV10/2023
//
// Last Modified: 2024-28-12
// ==============================================

#pragma once
#include "Maze.h"

class Item {
public:
	int r, c;
	int duration;
	// constructors set position for item, and default duration 3
	Item(int r, int c);
	// string get_type return name of the class
	virtual std::string get_type() = 0;

	virtual bool effect(Maze& maze, int r, int c) = 0;
};

class Fog_of_war : public Item {
public:
	using Item::Item;
	std::string get_type() override;
	bool effect(Maze& maze, int r, int c) override;
};

class Hammer : public Item {
	using Item::Item;
	std::string get_type() override;
	bool effect(Maze& maze, int r, int c) override;
};

class Sword : public Item {
	using Item::Item;
	std::string get_type() override;
	bool effect(Maze& maze, int r, int c) override;
};

class Shield : public Item {
public:
	std::string get_type() override;
	bool effect(Maze& maze, int r, int c) override;
	Shield(int r, int c);
};