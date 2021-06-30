#ifndef SALMON_H
#define SALMON_H
#include "fish.h"
#include "can_swim.h"

class Salmon : public Fish, public CanSwim{
    public:
        bool tastesGood(); 
};

#endif