#include "military.h"

Military::Military(int size, std::string flightNumber, std::string flightModel, bool isCivilian, bool isMilitary, float speed, float fuel, float expense, float positionX, int power){
    this->size = size;
    this->flightNumber = flightNumber;
    this->flightModel = flightModel;
    this->isCivilian = isCivilian;
    this->isMilitary = isMilitary;
    this->speed = speed;
    this->fuel = fuel;
    this->expense= expense;
    this->positionX = positionX;
    this->power = power;
}

Military::Military(const Military& military_plane){
    this->size = military_plane.size;
    this->flightNumber = military_plane.flightNumber;
    this->flightModel = military_plane.flightModel;
    this->isCivilian = military_plane.isCivilian;
    this->isMilitary = military_plane.isMilitary;
    this->speed = military_plane.speed;
    this->fuel = military_plane.fuel;
    this->expense= military_plane.expense;
    this->positionX = military_plane.positionX;
    this->power = power;
}