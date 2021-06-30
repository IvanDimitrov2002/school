#include "supplier.h"

Supplier::Supplier(std::string name){
    this->name = name;
}

Supplier::Supplier(const Supplier& supplier){
    this->name = supplier.name;
}

std::string Supplier::getName() const{
    return name;
}

void Supplier::setName(std::string name){
    this->name = name;
}