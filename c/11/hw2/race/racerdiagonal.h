#ifndef RACERDIAGONAL_H
#define RACERDIAGONAL_H

#include "racer.h"

class RacerDiagonal : public Racer{
    public:
        using Racer::Racer;

        void moveForward(Race& race);
};

#endif