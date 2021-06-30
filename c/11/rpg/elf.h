#ifndef ELF_H
#define ELF_H

#include "character.h"

class Elf : public Character{
    public:
        int attack = 5;
        int defence = 5;
        using Character::Character;
};

#endif