#ifndef RACER_H
#define RACER_H

#include <string>
#include <utility>
#include "race.h"

class Race;

class Racer{
    protected:
        std::string name;
        std::pair<unsigned int, unsigned int> position;
        int speed;
    public:
        Racer(){};

        Racer(std::string name, int speed);

        Racer(const Racer& racer);

        std::string getName();
        std::pair<unsigned int, unsigned int> getPosition();
        int getSpeed();

        void setName(std::string name);
        
        virtual void moveForward(Race& race);
};

#endif