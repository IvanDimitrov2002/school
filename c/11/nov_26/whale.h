#ifndef WHALE_H
#define WHALE_H
#include "mammal.h"
#include "can_swim.h"

class Whale : public Mammal, public CanSwim{
    public:
        void sing(); 
};

#endif