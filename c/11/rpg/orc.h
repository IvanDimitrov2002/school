#ifndef ORC_H
#define ORC_H

#include "character.h"

class Orc : public Character{
    public:
        int attack = 10;
        int defence = 0;
        using Character::Character;
};

#endif