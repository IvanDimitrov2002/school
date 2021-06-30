#ifndef PLANE_H
#define PLANE_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "airport.h"

class Airport;

class Plane{
    public:
        class PlaneCannotLand : std::exception{};
    
        int size;
        std::string flightNumber;
        std::string flightModel;
        bool isCivilian;
        bool isMilitary;
        float speed;
        float fuel;
        float expense;
        float positionX;

        Plane(){};

        Plane(int size, std::string flightNumber, std::string flightModel, bool isCivilian, bool isMilitary, float speed, float fuel, float expense, float positionX);

        Plane(const Plane& plane);

        std::ostream& operator<<(std::ostream& os);

        float distance_to_airport(Airport& airport);

        int can_reach(Airport& airport);

        void land_in_nearest_airport(std::vector<Airport> airports);
};

#endif