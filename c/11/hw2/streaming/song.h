#ifndef SONG_H
#define SONG_H

#include "media.h"

class Song : public Media{
    protected:
        int listened;
    public:
        Song(){};

        Song(std::string title, std::string author, double price, int listened);

        Song(const Song& song);

        int getListened();

        void setListened(int listened);

        double calcPrice();
};

#endif