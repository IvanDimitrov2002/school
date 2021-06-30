#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character{
    public:
        std::string name;
        int attack;
        int defence;

        Character(){};

        Character(std::string name, int attack, int defence);

};

#endif