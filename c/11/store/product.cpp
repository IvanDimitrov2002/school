#include "product.h"
#include <iostream>

Product::Product(){};
Product::Product(std::string name, std::string producer, float price, std::string barcode, std::string description){
    this->name = name;
    this->producer = producer;
    this->price = price;
    this->barcode = barcode;
    this->description = description;
};
