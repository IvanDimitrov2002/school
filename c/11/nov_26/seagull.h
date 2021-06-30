#ifndef SEAGULL_H
#define SEAGULL_H

#include "bird.h"
#include "can_walk.h"
#include "can_fly.h"
#include "can_swim.h"

class Seagull : public Bird, public CanWalk, public CanFly, public CanSwim{
    public:
        void eatTrash();
};

#endif