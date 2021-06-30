#ifndef APP_H
#define APP_H

#include "media.h"
#include "payment.h"
#include "user.h"

class App{
    private:
        std::vector<User> users;
        std::vector<Media*> media;
    public:

        class UserNotFound : std::exception{};
        class PaymentNotFound : std::exception{};
        class MediaNotFound : std::exception{};

        App(){};

        App(std::vector<User> users, std::vector<Media*> media);

        App(std::vector<Media*> media);

        App(const App& app);

        std::vector<User> getUsers();
        std::vector<Media*> getMedia();

        void setUsers(std::vector<User> users);
        void setMedia(std::vector<Media*> media);

        void addUser(User user);
        void addMedia(Media* media);
        Payment& getUserPayment(std::string name, std::string firstDate, std::string endDate);
        Media* searchMedia(std::string title);
        void pay(Payment& payment);

};

#endif