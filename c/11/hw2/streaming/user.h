#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "media.h"
#include "payment.h"

class User{
    private:
        std::string name;
        std::string email;
        std::vector<Media*> history;
        std::vector<Payment> payments;
    public:
        User(){};

        User(std::string name, std::string email, std::vector<Media*> history, std::vector<Payment> payments);

        User(const User& user);

        std::string getName();
        std::string getEmail();
        std::vector<Media*> getHistory();
        std::vector<Payment> getPayments();

        void setName(std::string name);
        void setEmail(std::string email);
        void setHistory(std::vector<Media*> history);
        void setPayments(std::vector<Payment> payments);
};

#endif