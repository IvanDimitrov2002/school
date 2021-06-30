#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include "user.h"
#include "item.h"
#include "order.h"

class Shop{
    private:
        std::vector<User> users;
        std::vector<Item*> items;
        std::vector<Order> orders;

    public:
        class UserAlreadyExists : std::exception{};
        class OrderAlreadyExists : std::exception{};
        class UserNotFound : std::exception{};
        class QuantityExceeded : std::exception{};
        class OrderNotFound : std::exception{};
        class InvalidOrderStatus : std::exception{};

        Shop(){};

        Shop(std::vector<User> users, std::vector<Item*> items, std::vector<Order> orders);

        Shop(const Shop& shop);

        std::vector<User> getUsers();
        std::vector<Item*> getItems();
        std::vector<Order> getOrders();

        void setUsers(std::vector<User> users);
        void setItems(std::vector<Item*> items);
        void setOrders(std::vector<Order> orders);

        void add_user(User const& user);
        void add_item(Item const& item);
        void create_order(Order const& order);
        std::pair<double, unsigned int> accept_order(unsigned int order_id);
        void send_order(unsigned int order_id);
        std::vector<Order const*> get_orders_by_user(unsigned int user_id) const;
        std::vector<Item const*> get_items_by_supplier(Supplier const& supplier) const;
};

#endif