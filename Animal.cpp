#include "Animal.h"

Animal::Animal(int x, int y, int stab, int dir) :
	stability(stab),
	dir((Direction)dir)
{
	pos.x = x;
	pos.y = y;
	movecount = 0;
	age = 0;
}



void Animal::tick(int n) {
	switch (dir)
	{
	case Animal::UP:
		pos.y -= n;
		break;
	case Animal::RIGHT:
		pos.x += n;
		break;
	case Animal::DOWN:
		pos.y += n;
		break;
	case Animal::LEFT:
		pos.x -= n;
		break;
	}

	movecount++;
	if (movecount == stability) {
		dir = (Direction)((dir + 1) % 4);
		movecount = 0;
	}
	age++;
}

Animal::Position Animal::getPosition() {
	return pos;
}
Animal::Position Animal::setPosition(Animal::Position psos) {
	pos = psos;
	return pos;
}