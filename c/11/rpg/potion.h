#ifndef POTION_H
#define POTION_H

#include "entity.h"

class Potion : public Entity{
    public:
        int attack = 0;
        int defence = 0;

        Potion(){};

        Potion(int attack, int defence);
};

#endif