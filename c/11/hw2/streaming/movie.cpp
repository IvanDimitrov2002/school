#include "movie.h"

Movie::Movie(std::string title, std::string author, double price, int minutes){
    this->title = title;
    this->author = author;
    this->price = price;
    this->minutes = minutes;
}

Movie::Movie(const Movie& song){
    this->title = song.title;
    this->author = song.author;
    this->price = song.price;
    this->minutes = song.minutes;
}

int Movie::getMinutes(){
    return minutes;
}

void Movie::setMinutes(int minutes){
    this->minutes = minutes;
}

double Movie::calcPrice(){
    return minutes * price;
}