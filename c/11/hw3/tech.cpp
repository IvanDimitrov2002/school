#include "tech.h"

Tech::Tech(std::string name, double price, bool available, Supplier supplier, unsigned int daysToDeliver, unsigned int quantity, TechType type, unsigned int years, double weight){
    this->name = name;
    this->price = price;
    this->available = available;
    this->supplier = supplier;
    this->daysToDeliver = daysToDeliver;
    this->quantity = quantity;
    this->type = type;
    this->years = years;
    this->weight = weight;
}

Tech::Tech(const Tech& tech){
    this->name = tech.name;
    this->price = tech.price;
    this->available = tech.available;
    this->supplier = tech.supplier;
    this->daysToDeliver = tech.daysToDeliver;
    this->quantity = tech.quantity;
    this->type = tech.type;
    this->years = tech.years;
    this->weight = tech.weight;
}

TechType Tech::getType(){
    return type;
}

unsigned int Tech::getYears(){
    return years;
}

double Tech::getWeight(){
    return weight;
}

void Tech::setType(TechType type){
    this->type = type;
}

void Tech::setYears(unsigned int years){
    this->years = years;
}

void Tech::setWeight(double weight){
    this->weight = weight;
}