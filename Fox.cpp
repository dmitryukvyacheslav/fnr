#include "Fox.h"
Fox::Fox(int x, int y, int stab, int dir) :
	Animal(x, y, stab, dir),
	saturation(0)
{
	
	printf("\tFox (%d;%d), stab: %d, dir: %d\n",
		this->pos.x, this->pos.y, this->stability, this->dir);
}

Fox::Fox(const Fox& f) :
	Animal(f.pos.x, f.pos.y, f.stability, f.dir)
{
	saturation = 0;
	printf("\t[Reproduced] Fox (%d;%d), stab: %d, dir: %d\n",
		this->pos.x, this->pos.y, this->stability, this->dir);
}
bool Fox::isDying() {
	return age == 15;
}

int Fox::getAge() {
	return age;
}

int Fox::addSaturation() {
	this->saturation++;
	return this->saturation;
}

int Fox::resetSaturation() {
	this->saturation = 0;
	return this->saturation;
}

int Fox::getSaturation() {
	return this->saturation;
}

void Fox::move() {
	tick(1);
}