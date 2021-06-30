#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "user.h"
#include "item.h"

enum Status {New, Accepted, Sent};

class Order{
    private:
        unsigned int id;
        User user;
        std::vector<Item*> items;
        Status status = New; 

    public:
        Order(){};

        Order(unsigned int id, User user, std::vector<Item*> items, Status status);

        Order(const Order& order);

        unsigned int getId() const;
        User getUser() const;
        std::vector<Item*> getItems() const;
        Status getStatus() const;

        void setId(unsigned int id);
        void setUser(User user);
        void setItems(std::vector<Item*> items);
        void setStatus(Status status);

        void addItem(Item* item);
        double getTotalPrice() const;
        int getTotalDays() const;
};

#endif