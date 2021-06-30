#ifndef GUITAR_H
#define GUITAR_H

#include "instrument.h"

class Guitar : public Instrument{
    public:
        int strings;
        int frets;
        int weight;

        Guitar(){};

        Guitar(int id, float price, std::string brand, int strings, int frets, int weight);

};

#endif