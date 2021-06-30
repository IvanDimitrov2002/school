#ifndef OSTRICH_H
#define OSTRICH_H
#include "bird.h"
#include "can_walk.h"

class Ostrich : public Bird, public CanWalk{
    public:
        void bigEggs(); 
};

#endif