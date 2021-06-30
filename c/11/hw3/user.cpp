#include "user.h"

User::User(unsigned int id, std::string name, std::string password){
    this->id = id;
    this->name = name;
    this->password = password;
}

User::User(const User& user){
    this->id = user.id;
    this->name = user.name;
    this->password = user.password;
}

unsigned int User::getId() const{
    return id;
}

std::string User::getName() const{
    return name;
}

std::string User::getPassword() const{
    return password;
}

void User::setId(unsigned int id){
    this->id = id;
}

void User::setName(std::string name){
    this->name = name;
}

void User::setPassword(std::string password){
    this->password = password;
}