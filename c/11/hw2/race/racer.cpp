#include "racer.h"

Racer::Racer(std::string name, int speed){
    this->name = name;
    this->speed = speed;
}

Racer::Racer(const Racer& racer){
    this->name = racer.name;
    this->position = racer.position;
    this->speed = racer.speed;
}

std::string Racer::getName(){
    return name;
}

std::pair<unsigned int, unsigned int> Racer::getPosition(){
    return position;
}

int Racer::getSpeed(){
    return speed;
}

void Racer::setName(std::string name){
    this->name = name;
}

void Racer::moveForward(Race& race){};