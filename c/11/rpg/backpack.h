#ifndef BACKPACK_H
#define BACKPACK_H

#include "entity.h"
#include <vector>

class Backpack : public Entity{
    public:
        std::vector<Entity> items;

        Backpack(){};

        Backpack(std::vector<Entity> items);

        
};

#endif