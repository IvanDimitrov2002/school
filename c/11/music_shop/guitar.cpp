#include "guitar.h"

Guitar::Guitar(int id, float price, std::string brand, int strings, int frets, int weight){
    this->id = id;
    this->price = price;
    this->brand = brand;
    this->strings = strings;
    this->frets = frets;
    this->weight = weight;
};
