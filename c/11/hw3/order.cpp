#include "order.h"

Order::Order(unsigned int id, User user, std::vector<Item*> items, Status status){
    this->id = id;
    this->user = user;
    this->items = items;
    this->status = status;
}

Order::Order(const Order& order){
    this->id = order.id;
    this->user = order.user;
    this->items = order.items;
    this->status = order.status;
}

unsigned int Order::getId() const{
    return id;
}

User Order::getUser() const{
    return user;
}

std::vector<Item*> Order::getItems() const{
    return items;
}

Status Order::getStatus() const{
    return status;
}


void Order::setId(unsigned int id){
    this->id = id;
}

void Order::setUser(User user){
    this->user = user;
}

void Order::setItems(std::vector<Item*> items){
    this->items = items;
}

void Order::setStatus(Status status){
    this->status = status;
}

void Order::addItem(Item* item){
    for(int i = 0; i < items.size(); i++){
        if(items[i] == item){
            items[i]->setQuantity(items[i]->getQuantity() + item->getQuantity());
            return;
        }
    }
    items.push_back(item);
}

double Order::getTotalPrice() const{
    double totalPrice = 0;
    for(int i =0; i < items.size(); i++){
        totalPrice += items[i]->getPrice();
    }
    return totalPrice;
}

int Order::getTotalDays() const{
    int totalDays = 0;
    for(int i =0; i < items.size(); i++){
        totalDays += items[i]->getDays();
    }
    return totalDays;
}