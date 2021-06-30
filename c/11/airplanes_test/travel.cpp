#include "travel.h"

Travel::Travel(int size, std::string flightNumber, std::string flightModel, bool isCivilian, bool isMilitary, float speed, float fuel, float expense, float positionX, int passengers, int seats, int exits){
    this->size = size;
    this->flightNumber = flightNumber;
    this->flightModel = flightModel;
    this->isCivilian = isCivilian;
    this->isMilitary = isMilitary;
    this->speed = speed;
    this->fuel = fuel;
    this->expense= expense;
    this->positionX = positionX;
    this->passengers = passengers;
    this->seats = seats;
    this->exits = exits;
}

Travel::Travel(const Travel& travel_plane){
    this->size = travel_plane.size;
    this->flightNumber = travel_plane.flightNumber;
    this->flightModel = travel_plane.flightModel;
    this->isCivilian = travel_plane.isCivilian;
    this->isMilitary = travel_plane.isMilitary;
    this->speed = travel_plane.speed;
    this->fuel = travel_plane.fuel;
    this->expense= travel_plane.expense;
    this->positionX = travel_plane.positionX;
    this->passengers = travel_plane.passengers;
    this->seats = travel_plane.seats;
    this->exits = travel_plane.exits;
}