#ifndef PLANE_H
#define PLANE_H

#include <string>
#include <ostream>
#include <iostream>

class Plane{
    protected:
        int size;
        std::string flight_number;
        std::string flight_model;
        bool is_civilian;
        bool is_military;
        float speed;
        float amount_fuel;
        float expense;
        float position_x;

    public:
        Plane(){};
        Plane(int size, std::string flight_number, std::string flight_model, bool is_civilian, bool is_military, float speed, float amount_fuel, float expense, float position_x);
        Plane(const Plane& plane);
        std::ostream& operator<<(std::ostream& stream);
};

#endif