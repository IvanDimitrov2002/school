#include "airport.h"

Airport::Airport(int planes, int maxSize, bool military, bool civilian, std::vector<Plane> arrivedPlanes, float positionX){
    this->planes = planes;
    this->maxSize = maxSize;
    this->military = military;
    this->civilian = civilian;
    this->arrivedPlanes = arrivedPlanes;
    this->positionX = positionX;
};

Airport::Airport(const Airport& airport){
    this->planes = airport.planes;
    this->maxSize = airport.maxSize;
    this->military = airport.military;
    this->civilian = airport.civilian;
    this->arrivedPlanes = airport.arrivedPlanes;
    this->positionX = airport.positionX;
};

int Airport::can_fit_plane(const Plane& plane){
    if((arrivedPlanes.size() + plane.size) > planes){
        return 0;
    }
    if(plane.size > maxSize){
        return 0;
    }
    if(military){
        if(!plane.isMilitary) return 0;
    }
    if(civilian){
        if(!plane.isCivilian) return 0;
    }
    return 1;
};

void Airport::land_plane(const Plane& plane){
    if(can_fit_plane(plane)){
        arrivedPlanes.push_back(plane);
    } else {
        throw AirPortLandException();
    }
};