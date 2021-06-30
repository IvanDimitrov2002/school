#include "app.h"

App::App(std::vector<User> users, std::vector<Media*> media){
    this->users = users;
    this->media = media;
}

App::App(std::vector<Media*> media){
    this->media = media;
}

App::App(const App& app){
    this->users = app.users;
    this->media = app.media;
}

std::vector<User> App::getUsers(){
    return users;
}

std::vector<Media*> App::getMedia(){
    return media;
}

void App::setUsers(std::vector<User> users){
    this->users = users;
}

void App::setMedia(std::vector<Media*> media){
    this->media = media;
}

void App::addUser(User user){
    users.push_back(user);
}

void App::addMedia(Media* media){
    this->media.push_back(media);
}

Payment& App::getUserPayment(std::string name, std::string firstDate, std::string endDate){
    for(int i = 0; i < users.size(); i++){
        if(users[i].getName() == name){
            std::pair<std::string, std::string> period {firstDate, endDate};
            std::vector<Payment> payments = users[i].getPayments();
            for(int j = 0; j < payments.size(); j++){
                if(payments[j].getPeriod() == period){
                    return payments[j];
                }
            }
            throw PaymentNotFound();
        }
    }
    throw UserNotFound();
}

Media* App::searchMedia(std::string title){
    for(int i = 0; i < media.size(); i++){
        if(media[i]->getTitle() == title){
            return media[i];
        }
    }
    throw MediaNotFound();
}

void App::pay(Payment& payment){
    payment.setPaid(true);
}
