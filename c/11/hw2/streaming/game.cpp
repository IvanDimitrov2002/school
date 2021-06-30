#include "game.h"

Game::Game(std::string title, std::string author, double price, int hours){
    this->title = title;
    this->author = author;
    this->price = price;
    this->hours = hours;
}

Game::Game(const Game& song){
    this->title = song.title;
    this->author = song.author;
    this->price = song.price;
    this->hours = song.hours;
}

int Game::getHours(){
    return hours;
}

void Game::setHours(int hours){
    this->hours = hours;
}

double Game::calcPrice(){
    return hours * price;
}