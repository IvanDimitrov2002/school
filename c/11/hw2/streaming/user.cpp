#include "user.h"

User::User(std::string name, std::string email, std::vector<Media*> history, std::vector<Payment> payments){
    this->name = name;
    this->email = email;
    this->history = history;
    this->payments = payments;
}

User::User(const User& user){
    this->name = user.name;
    this->email = user.email;
    this->history = user.history;
    this->payments = user.payments;
}

std::string User::getName(){
    return name;
}

std::string User::getEmail(){
    return email;
}

std::vector<Media*> User::getHistory(){
    return history;
}

std::vector<Payment> User::getPayments(){
    return payments;
}

void User::setName(std::string name){
    this->name = name;
}

void User::setEmail(std::string email){
    this->email = email;
}

void User::setHistory(std::vector<Media*> history){
    this->history = history;
}

void User::setPayments(std::vector<Payment> payments){
    this->payments = payments;
}

