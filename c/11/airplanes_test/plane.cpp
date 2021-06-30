#include "plane.h"


Plane::Plane(int size, std::string flightNumber, std::string flightModel, bool isCivilian, bool isMilitary, float speed, float fuel, float expense, float positionX){
    this->size = size;
    this->flightNumber = flightNumber;
    this->flightModel = flightModel;
    this->isCivilian = isCivilian;
    this->isMilitary = isMilitary;
    this->speed = speed;
    this->fuel = fuel;
    this->expense= expense;
    this->positionX = positionX;
}

Plane::Plane(const Plane& plane){
    this->size = plane.size;
    this->flightNumber = plane.flightNumber;
    this->flightModel = plane.flightModel;
    this->isCivilian = plane.isCivilian;
    this->isMilitary = plane.isMilitary;
    this->speed = plane.speed;
    this->fuel = plane.fuel;
    this->expense= plane.expense;
    this->positionX = plane.positionX;
}

std::ostream& Plane::operator<<(std::ostream& stream){
  return stream
    << "Size: " << size << '\n'
    << "Flight number: " << flightNumber << '\n'
    << "Model: " << flightModel << '\n'
    << "Military: " << std::boolalpha << isMilitary << '\n'
    << "Civilian: " << std::boolalpha << isCivilian << '\n'
    << "Speed: " << speed << '\n'
    << "Fuel: " << fuel << '\n'
    << "Consumption per kilometer: "
    << expense << '\n'
    << "Position: " << positionX;
}

float Plane::distance_to_airport(Airport& airport){
    return abs(airport.positionX - positionX);
};

int Plane::can_reach(Airport& airport){
    if(fuel >= (expense * distance_to_airport(airport))){
        return 1;
    }
    return 0;
};

void Plane::land_in_nearest_airport(std::vector<Airport> airports){
    int i, index = -1;
    float nearest;

    for(i = 0; i < airports.size(); i++){
        if(can_reach(airports[i])){
            nearest = distance_to_airport(airports[i]);
            index = i;
            break;
        }
    }

    for(; i < airports.size(); i++){
        if((nearest > distance_to_airport(airports[i])) && can_reach(airports[i])){
            nearest = distance_to_airport(airports[i]);
            index = i;
        }
    }
    
    if(index > -1){
        airports[index].land_plane(*this);
    } else {
        throw PlaneCannotLand();
    }
}