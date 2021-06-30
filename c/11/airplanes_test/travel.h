#ifndef TRAVEL_H
#define TRAVEL_H

#include "plane.h"

class Travel : public Plane{
    public:
        int passengers;
        int seats;
        int exits;
        Travel(){};

        Travel(int size, std::string flightNumber, std::string flightModel, bool isCivilian, bool isMilitary, float speed, float fuel, float expense, float positionX, int passengers, int seats, int exits);

        Travel(const Travel& travel);
};

#endif