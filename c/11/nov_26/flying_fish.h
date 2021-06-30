#ifndef FLYING_FISH_H
#define FLYING_FISH_H
#include "fish.h"
#include "can_swim.h"
#include "can_fly.h"

class FlyingFish : public Fish, public CanSwim, public CanFly{
    public:
        void runaway(); 
};

#endif