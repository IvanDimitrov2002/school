#ifndef WEAPON_H
#define WEAPON_H

#include "entity.h"

class Weapon : public Entity{
    public:
        int attack;

        Weapon(){};

        Weapon(int attack);

};

#endif