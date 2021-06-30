#include "clothing.h"

Clothing::Clothing(std::string name, double price, bool available, Supplier supplier, unsigned int daysToDeliver, unsigned int quantity, std::string color, unsigned int size, std::string material){
    this->name = name;
    this->price = price;
    this->available = available;
    this->supplier = supplier;
    this->daysToDeliver = daysToDeliver;
    this->quantity = quantity;
    this->color = color;
    this->size = size;
    this->material = material;
}

Clothing::Clothing(const Clothing& clothing){
    this->name = clothing.name;
    this->price = clothing.price;
    this->available = clothing.available;
    this->supplier = clothing.supplier;
    this->daysToDeliver = clothing.daysToDeliver;
    this->quantity = clothing.quantity;
    this->color = clothing.color;
    this->size = clothing.size;
    this->material = clothing.material;
}

std::string Clothing::getColor(){
    return color;
}

unsigned int Clothing::getSize(){
    return size;
}

std::string Clothing::getMaterial(){
    return material;
}


void Clothing::setColor(std::string color){
    this->color = color;
}

void Clothing::setSize(unsigned int size){
    this->size = size;
}

void Clothing::setMaterial(std::string material){
    this->material = material;
}
