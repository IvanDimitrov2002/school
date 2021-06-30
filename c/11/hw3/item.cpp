#include "item.h"

Item::Item(std::string name, double price, bool available, Supplier supplier, unsigned int daysToDeliver, unsigned int quantity){
    this->name = name;
    this->price = price;
    this->available = available;
    this->supplier = supplier;
    this->daysToDeliver = daysToDeliver;
    this->quantity = quantity;
}

Item::Item(const Item* item){
    this->name = item->name;
    this->price = item->price;
    this->available = item->available;
    this->supplier = item->supplier;
    this->daysToDeliver = item->daysToDeliver;
    this->quantity = item->quantity;
}

std::string Item::getName() const{
    return name;
}

double Item::getPrice() const{
    return price;
}

bool Item::isAvailable() const{
    return available;
}

Supplier Item::getSupplier() const{
    return supplier;
}

unsigned int Item::getDays() const{
    return daysToDeliver;
}

unsigned int Item::getQuantity() const{
    return quantity;
}


void Item::setName(std::string name){
    this->name = name;
}

void Item::setPrice(double price){
    this->price = price;
}

void Item::setAvailable(bool available){
    this->available = available;
}

void Item::setSupplier(Supplier supplier){
    this->supplier = supplier;
}

void Item::setDays(unsigned int daysToDeliver){
    this->daysToDeliver = daysToDeliver;
}

void Item::setQuantity(unsigned int quantity){
    this->quantity = quantity;
}


bool Item::operator==(Item& item){
    if(name != item.name || price != item.price || available != item.available ||  daysToDeliver != item.daysToDeliver || supplier.getName() != item.supplier.getName()){
        return false;
    }
    return true;
}

TechType Item::getType(){
    return None;
}

unsigned int Item::getYears(){
    return 0;
}

double Item::getWeight(){
    return 0;
}

std::string Item::getColor(){
    return "None";
}

unsigned int Item::getSize(){
    return 0;
}

std::string Item::getMaterial(){
    return "None";
}
