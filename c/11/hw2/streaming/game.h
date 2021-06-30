#ifndef GAME_H
#define GAME_H

#include "media.h"

class Game : public Media{
    protected:
        int hours;
    public:
        Game(){};

        Game(std::string title, std::string author, double price, int hours);

        Game(const Game& game);

        int getHours();

        void setHours(int hours);

        double calcPrice();
};

#endif