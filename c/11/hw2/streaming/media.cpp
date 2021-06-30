#include "media.h"

Media::Media(std::string title, std::string author, double price){
    this->title = title;
    this->author = author;
    this->price = price;
}

Media::Media(const Media& media){
    this->title = media.title;
    this->author = media.author;
    this->price = media.price;
}

std::string Media::getTitle(){
    return title;
}

std::string Media::getAuthor(){
    return author;
}

double Media::getPrice(){
    return price;
}

void Media::setTitle(std::string title){
    this->title = title;
}

void Media::setAuthor(std::string author){
    this->author = author;
}

void Media::setPrice(double price){
    this->price = price;
}

double Media::calcPrice(){
    return price;
};