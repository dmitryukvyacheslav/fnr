#pragma once
#include "Animal.h"
class Fox :
    public Animal
{
    int saturation;

public:
    Fox(int x, int y, int stab, int dir);
    Fox(const Fox& f);
    bool isDying();
    int getSaturation();
    int addSaturation();
    int resetSaturation();
    int getAge();
    void move();
};

