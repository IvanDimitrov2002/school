#include "song.h"

Song::Song(std::string title, std::string author, double price, int listened){
    this->title = title;
    this->author = author;
    this->price = price;
    this->listened = listened;
}

Song::Song(const Song& song){
    this->title = song.title;
    this->author = song.author;
    this->price = song.price;
    this->listened = song.listened;
}

int Song::getListened(){
    return listened;
}

void Song::setListened(int listened){
    this->listened = listened;
}

double Song::calcPrice(){
    return listened * price;
}