#ifndef MOVIE_H
#define MOVIE_H

#include "media.h"

class Movie : public Media{
    protected:
        int minutes;
    public:
        Movie(){};

        Movie(std::string title, std::string author, double price, int minutes);

        Movie(const Movie& movie);

        int getMinutes();

        void setMinutes(int minutes);

        double calcPrice();
};

#endif