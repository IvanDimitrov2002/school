#ifndef AIRPORT_H
#define AIRPORT_H

#include <vector>
#include "plane.h"

class Plane;

class Airport{
    public:
        class AirPortLandException : std::exception {};

        int planes;
        int maxSize;
        bool military;
        bool civilian;
        std::vector<Plane> arrivedPlanes;
        float positionX;

        Airport(){};

        Airport(int planes, int maxSize, bool military, bool civilian, std::vector<Plane> arrivedPlanes, float positionX);

        Airport(const Airport& airport);

        int can_fit_plane(const Plane& plane);

        void land_plane(const Plane& plane);
};

#endif