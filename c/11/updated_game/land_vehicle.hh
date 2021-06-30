#ifndef LAND_VEHICLE_HH
#define LAND_VEHICLE_HH

#include "./vehicle.hh"

class LandVehicle : public Vehicle {
    public:
        void accelerate(){
            speed += acceleration - (weight * 9.8);
        }
};

#endif
