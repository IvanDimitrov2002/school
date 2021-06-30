#include "load.h"

Load::Load(int size, std::string flightNumber, std::string flightModel, bool isCivilian, bool isMilitary, float speed, float fuel, float expense, float positionX, int curr_load, int max_load){
    this->size = size;
    this->flightNumber = flightNumber;
    this->flightModel = flightModel;
    this->isCivilian = isCivilian;
    this->isMilitary = isMilitary;
    this->speed = speed;
    this->fuel = fuel;
    this->expense= expense;
    this->positionX = positionX;
    this->curr_load = curr_load;
    this->max_load = max_load;
}

Load::Load(const Load& load_plane){
    this->size = load_plane.size;
    this->flightNumber = load_plane.flightNumber;
    this->flightModel = load_plane.flightModel;
    this->isCivilian = load_plane.isCivilian;
    this->isMilitary = load_plane.isMilitary;
    this->speed = load_plane.speed;
    this->fuel = load_plane.fuel;
    this->expense= load_plane.expense;
    this->positionX = load_plane.positionX;
    this->curr_load = curr_load;
    this->max_load = max_load;
}