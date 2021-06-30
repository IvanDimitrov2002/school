#include <iostream>
#include "shop.h"
#include "tech.h"
#include "clothing.h"

int main(){
    std::vector<User> users;
    std::vector<Item*> items;
    std::vector<Item*> items2;
    std::vector<Order> orders;
    User user1 = User(0, "Mario", "syndow");
    User user2 = User(1, "Patrick", "Eclipsa");
    User user3 = User(2, "Lili", "paupau");
    User user4 = User(3, "Ivan", "Minerusher");
    users.push_back(user1); users.push_back(user2);
    users.push_back(user3);
    Supplier supplier1 = Supplier("Electrolux");
    Supplier supplier2 = Supplier("H&M");
    Item *item1 = new Tech("Dishwasher", 199.99, true, supplier1, 10, 1, White, 5, 10);
    Item *item2 = new Clothing("T-shirt", 15.99, true, supplier2, 3, 2, "Red", 15, "Polyester");
    Item *item3 = new Clothing("Jeans", 25.99, true, supplier2, 3, 1, "Blue", 33, "Cotton");
    Item *item4 = new Tech("Dishwasher2", 299.99, true, supplier1, 15, 2, White, 7, 12);
    items.push_back(item1); items.push_back(item2);
    items2.push_back(item3);
    Order order1 = Order(0, user1, items2, New);
    Order order2 = Order(1, user2, items2, New);
    orders.push_back(order1);
    Shop shop = Shop(users, items, orders);
    shop.add_item(item3);
    shop.add_user(user4);
    shop.create_order(order2);
    shop.accept_order(0);
    shop.accept_order(1);
    shop.send_order(0);
    std::vector<Order const*> orders_by_user = shop.get_orders_by_user(1);
    std::vector<Item const*> items_by_supplier = shop.get_items_by_supplier(supplier2);
    delete item3;
    delete item4;
    for(int i = 0; i < shop.getItems().size(); i++){
        delete shop.getItems()[i];
    }
    for(int i = 0; i < items_by_supplier.size(); i++){
        delete items_by_supplier[i];
    }
    for(int i = 0; i < orders_by_user.size(); i++){
        delete orders_by_user[i];
    }
    return 0;
}