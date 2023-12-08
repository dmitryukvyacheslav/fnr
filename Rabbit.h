#pragma once
#include "Animal.h"

class Rabbit :
    public Animal
{
public:
    Rabbit(int x, int y, int stab, int dir);
    Rabbit(const Rabbit& r);
    bool isDying();
    bool canReproduce();
    void move();
};

