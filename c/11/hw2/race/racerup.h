#ifndef RACERUP_H
#define RACERUP_H

#include "racer.h"

class RacerUp : public Racer{
    public:
        using Racer::Racer;

        void moveForward(Race& race);
};

#endif