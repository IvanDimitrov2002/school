#ifndef USER_H
#define USER_H

#include <string>

class User{
    private:
        unsigned int id;
        std::string name;
        std::string password;

    public:
        User(){};

        User(unsigned int id, std::string name, std::string password);

        User(const User& user);

        unsigned int getId() const;
        std::string getName() const;
        std::string getPassword() const;

        void setId(unsigned int id);
        void setName(std::string name);
        void setPassword(std::string password);
};

#endif