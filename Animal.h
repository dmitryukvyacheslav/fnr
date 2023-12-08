#pragma once
#include <stdio.h>
class Animal
{
	enum Direction {
		UP = 0,
		RIGHT = 1,
		DOWN = 2,
		LEFT = 3
	};

	struct Position {
		int x, y;
	};
	
protected:
	struct Position pos;

	// Общие поля для всех зверей
	enum Direction dir;
	int stability;
	int age;
	int movecount;


	void tick(int distance);
	Animal(int x, int y, int stab, int dir);
public:
	
	Position getPosition();
	Position setPosition(Position psos);
};

