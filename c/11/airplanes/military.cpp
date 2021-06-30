#include "military.h"

MilitaryPlane::MilitaryPlane(int size, std::string flight_number, std::string flight_model, bool is_civilian, bool is_military, float speed, float amount_fuel, float expense, float position_x, int force){
    this->size = size;
    this->flight_number = flight_number;
    this->flight_model = flight_model;
    this->is_civilian = is_civilian;
    this->is_military = is_military;
    this->speed = speed;
    this->amount_fuel = amount_fuel;
    this->expense = expense;
    this->position_x = position_x;
    this->force = force;
}

MilitaryPlane::MilitaryPlane(const MilitaryPlane& military_plane){
    this->size = military_plane.size;
    this->flight_number = military_plane.flight_number;
    this->flight_model = military_plane.flight_model;
    this->is_civilian = military_plane.is_civilian;
    this->is_military = military_plane.is_military;
    this->speed = military_plane.speed;
    this->amount_fuel = military_plane.amount_fuel;
    this->expense = military_plane.expense;
    this->position_x = military_plane.position_x;
    this->force = military_plane.force;
}