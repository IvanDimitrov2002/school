#ifndef MILITARY_H
#define MILITARY_H

#include "plane.h"

class Military : public Plane{
    public:
        int power;
        Military(){};

        Military(int size, std::string flightNumber, std::string flightModel, bool isCivilian, bool isMilitary, float speed, float fuel, float expense, float positionX, int power);

        Military(const Military& military);
};

#endif