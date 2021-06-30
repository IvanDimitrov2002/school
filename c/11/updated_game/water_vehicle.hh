#ifndef WATER_VEHICLE_HH
#define WATER_VEHICLE_HH

#include "./vehicle.hh"

class WaterVehicle : public Vehicle {
    public:
        float displacement;
        void accelerate(){
            speed += acceleration * displacement / weight;
        }
};

#endif
