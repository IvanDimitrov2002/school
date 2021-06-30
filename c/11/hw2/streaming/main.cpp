#include "app.h"
#include "game.h"
#include "movie.h"
#include <iostream>

int main(){
    Media *game1 = new Game("RDR2", "Rockstar", 9.99, 300);
    Media *game2 = new Game("CS:GO", "Valve", 0, 1000);
    Media *movie1 = new Movie("Star Wars Episode IX", "Lucasfilm", 3.4, 180);
    Media *movie2 = new Movie("Baby Driver", "TriStar Pictures", 1.5, 60);
    std::vector<Payment> payments;
    std::vector<Media*> media1;
    std::vector<Media*> media2;
    std::vector<Media*> media3;
    media1.push_back(game1); media1.push_back(game2);
    media2.push_back(movie1); media2.push_back(movie2);
    media3.push_back(game1); media3.push_back(game2);
    media3.push_back(movie1); media3.push_back(movie2);
    Payment payment1 = Payment("20.05.2019", "19.06.2019", media1, (game1->calcPrice() + game2->calcPrice()), false);
    Payment payment2 = Payment("14.02.2019", "13.03.2019", media2, (movie1->calcPrice() + movie2->calcPrice()), true);
    payments.push_back(payment1); payments.push_back(payment2);
    User user1 = User("Jack", "jack@gmail.com", media1, payments);
    User user2 = User("Kate", "kate@gmail.com", media2, payments);
    App app = App(media1);
    app.addMedia(movie1); app.addMedia(movie2);
    app.addUser(user1); app.addUser(user2);
    std::vector<User> users = app.getUsers();
    for(int i = 0; i < users.size(); i++){
        std::cout << users[i].getName() << std::endl;
    }
    Media *media4 = app.searchMedia("Baby Driver");
    std::cout << media4->getAuthor() << std::endl;
    Payment& payment3 = app.getUserPayment("Jack", "20.05.2019", "19.06.2019");
    std::cout << "Is paid: " << (payment3.getIsPaid() ? "Yes" : "No") << " Price: " << payment3.getBill() << std::endl;
    app.pay(payment3);
    std::cout << "Is paid: " << (payment3.getIsPaid() ? "Yes" : "No") << " Price: " << payment3.getBill() << std::endl;
    delete game1;
    delete game2;
    delete movie1;
    delete movie2;
    return 0;
}