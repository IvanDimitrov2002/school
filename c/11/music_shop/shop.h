#ifndef SHOP_H
#define SHOP_H

#include "guitar.h"
#include "acoustic_guitar.h"
#include "electric_guitar.h"
#include <vector>
#include <iostream>

class Shop{
    public:

        class AcousticGuitarNotAvaliable : std::exception{};
        class ElectricGuitarNotAvaliable : std::exception{};
        class GuitarAlreadyExists : std::exception{};
        class GuitarDoesntExist : std::exception{};

        std::vector<AcousticGuitar> acousticGuitars;
        std::vector<ElectricGuitar> electricGuitars;

        Shop(){};

        Shop(std::vector<AcousticGuitar> acousticGuitars, std::vector<ElectricGuitar> electricGuitars);

        std::vector<Guitar> get_all_in_price_range(double from_price, double to_price) const;
        std::vector<Guitar> get_all_twelve_strings() const;
        AcousticGuitar const& get_most_powerful_acoustic() const;
        ElectricGuitar const& get_most_powerful_electric() const;
        void add_accoustic(AcousticGuitar const& acoustic);
        void add_electric(ElectricGuitar const& electric);
        void buy(Guitar const& guitar);
};

#endif