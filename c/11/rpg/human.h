#ifndef HUMAN_H
#define HUMAN_H

#include "character.h"

class Human : public Character{
    public:
        int attack = 0;
        int defence = 10;
        using Character::Character;
};

#endif