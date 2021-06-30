#include "acoustic_guitar.h"

AcousticGuitar::AcousticGuitar(int id, float price, std::string brand, int strings, int frets, int weight, float output){
    this->id = id;
    this->price = price;
    this->brand = brand;
    this->strings = strings;
    this->frets = frets;
    this->weight = weight;
    this->output = output;
};