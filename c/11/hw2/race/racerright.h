#ifndef RACERRIGHT_H
#define RACERRIGHT_H

#include "racer.h"

class RacerRight : public Racer{
    public:
        using Racer::Racer;

        void moveForward(Race& race);
};

#endif