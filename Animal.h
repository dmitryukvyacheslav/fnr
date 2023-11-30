#pragma once

class Animal
{
	enum Direction {
		LEFT,
		UP,
		RIGHT,
		DOWN
	};

	struct Position {
		int x;
		int y;
	};

	// Общие поля для всех зверей
	enum Direction dir;
	int stability;
	int age;

	void move(int n) {

	}
};

