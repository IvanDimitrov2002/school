#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>

class Instrument{
    public:
        unsigned int id;
        float price;
        std::string brand;

        Instrument(){};

        Instrument(int id, float price, std::string brand);

};

#endif