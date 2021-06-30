#include "electric_guitar.h"

ElectricGuitar::ElectricGuitar(int id, float price, std::string brand, int strings, int frets, int weight, int pickups, float pickupsOutput){
    this->id = id;
    this->price = price;
    this->brand = brand;
    this->strings = strings;
    this->frets = frets;
    this->weight = weight;
    this->pickups = pickups;
    this->pickupsOutput = pickupsOutput;
};