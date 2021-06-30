#include "shop.h"

Shop::Shop(std::vector<User> users, std::vector<Item*> items, std::vector<Order> orders){
    this->users = users;
    this->items = items;
    this->orders = orders;
}


Shop::Shop(const Shop& shop){
    this->users = shop.users;
    this->items = shop.items;
    this->orders = shop.orders;
}


std::vector<User> Shop::getUsers(){
    return users;
}

std::vector<Item*> Shop::getItems(){
    return items;
}

std::vector<Order> Shop::getOrders(){
    return orders;
}


void Shop::setUsers(std::vector<User> users){
    this->users = users;
}

void Shop::setItems(std::vector<Item*> items){
    this->items = items;
}

void Shop::setOrders(std::vector<Order> orders){
    this->orders = orders;
}


void Shop::add_user(User const& user){
    for(int i = 0; i < users.size(); i++){
        if(users[i].getId() == user.getId()){
            throw UserAlreadyExists();
        }
    }
    users.push_back(user);
}

void Shop::add_item(Item const& item){
    Item *copyItem = new Item(item);
    for(int i = 0; i < items.size(); i++){
        if(*items[i] == *copyItem){
            items[i]->setQuantity(items[i]->getQuantity() + copyItem->getQuantity());
            return;
        }
    }
    items.push_back(copyItem);
}

void Shop::create_order(Order const& order){
    for(int i = 0; i < orders.size(); i++){
        if(orders[i].getId() == order.getId()){
            throw OrderAlreadyExists();
        }
    }
    bool userExists = false;
    for(int i = 0; i < users.size(); i++){
        if(users[i].getId() == order.getUser().getId()){
            userExists = true;
            break;
        }
    }
    if(!userExists){
        throw UserNotFound();
    }
    for(int i = 0; i < items.size(); i++){
        for(int j = 0; j < order.getItems().size(); j++){
            if(items[i] == order.getItems()[j]){
                if(items[i]->getQuantity() < order.getItems()[j]->getQuantity()){
                    throw QuantityExceeded();
                }
                items[i]->setQuantity(items[i]->getQuantity() - order.getItems()[j]->getQuantity());
                break;
            }
        }
    }
    orders.push_back(order);
}

std::pair<double, unsigned int> Shop::accept_order(unsigned int order_id){
    for(int i = 0; i < orders.size(); i++){
        if(orders[i].getId() == order_id){
            if(orders[i].getStatus() != New){
                throw InvalidOrderStatus();
            }
            std::pair<double, unsigned int> info;
            orders[i].setStatus(Accepted);
            info.first = orders[i].getTotalPrice();
            info.second = orders[i].getTotalDays();
            return info;
        }
    }
    throw OrderNotFound();
}

void Shop::send_order(unsigned int order_id){
    for(int i = 0; i < orders.size(); i++){
        if(orders[i].getId() == order_id){
            if(orders[i].getStatus() != Accepted){
                throw InvalidOrderStatus();
            }
            orders[i].setStatus(Sent);
            return;
        }
    }
    throw OrderNotFound();
}

std::vector<Order const*> Shop::get_orders_by_user(unsigned int user_id) const{
    bool userExists = false;
    for(int i = 0; i < users.size(); i++){
        if(users[i].getId() == user_id){
            userExists = true;
            break;
        }
    }
    if(!userExists){
        throw UserNotFound();
    }
    std::vector<Order const*> userOrders;
    for(int i = 0; i < orders.size(); i++){
        if(orders[i].getUser().getId() == user_id){
            userOrders.push_back(new Order(orders[i]));
        }
    }
    return userOrders;
}

std::vector<Item const*> Shop::get_items_by_supplier(Supplier const& supplier) const{
    std::vector<Item const*> supplierItems;
    for(int i = 0; i < orders.size(); i++){
        for(int j = 0; j < orders[i].getItems().size(); j++){
            if(orders[i].getItems()[j]->getSupplier().getName() == supplier.getName()){
                supplierItems.push_back(new Item(orders[i].getItems()[j]));
            }
        }
    }
    return supplierItems;
}