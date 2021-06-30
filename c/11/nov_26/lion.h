#ifndef LION_H
#define LION_H

#include "mammal.h"
#include "can_walk.h"

class Lion : public Mammal, public CanWalk{
    public:
        void roar();
};

#endif