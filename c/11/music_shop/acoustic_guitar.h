#ifndef ACOUSTIC_GUITAR_H
#define ACOUSTIC_GUITAR_H

#include "guitar.h"

class AcousticGuitar : public Guitar{
    public:
        float output;

        AcousticGuitar(){};

        AcousticGuitar(int id, float price, std::string brand, int strings, int frets, int weight, float output);


};

#endif