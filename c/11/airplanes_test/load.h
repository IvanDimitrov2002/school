#ifndef LOAD_H
#define LOAD_H

#include "plane.h"

class Load : public Plane{
    public:
        int curr_load;
        int max_load;
        Load(){};

        Load(int size, std::string flightNumber, std::string flightModel, bool isCivilian, bool isMilitary, float speed, float fuel, float expense, float positionX, int curr_load, int max_load);

        Load(const Load& load);
};

#endif