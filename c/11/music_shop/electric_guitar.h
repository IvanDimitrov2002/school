#ifndef ELECTRIC_GUITAR_H
#define ELECTRIC_GUITAR_H

#include "guitar.h"

class ElectricGuitar : public Guitar{
    public:
        int pickups;
        float pickupsOutput;

        ElectricGuitar(){};

        ElectricGuitar(int id, float price, std::string brand, int strings, int frets, int weight, int pickups, float pickupsOutput);

        
};

#endif