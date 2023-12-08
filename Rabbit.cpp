#include "Rabbit.h"

Rabbit::Rabbit(int x, int y, int stab, int dir) :
	Animal(x, y, stab, dir)
{
	printf("\tRabbit (%d;%d), stab: %d, dir: %d\n",
		this->pos.x, this->pos.y, this->stability, this->dir);
}

Rabbit::Rabbit(const Rabbit& r) :
	Animal(r.pos.x, r.pos.y, r.stability, r.dir)
{
	printf("\t[Reproduced] Rabbit (%d;%d), stab: %d, dir: %d\n",
		this->pos.x, this->pos.y, this->stability, this->dir);
}

bool Rabbit::isDying() {
	return age == 10;
}

bool Rabbit::canReproduce() {
	return (age % 5 == 0);
}

void Rabbit::move() {
	tick(2);
}