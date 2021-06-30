#ifndef STORE_H
#define STORE_H

#include "product.h"
#include <vector>

class Store {
    private:
        std::vector<Product> products;
        std::vector<Product> basket;
    public:
        bool checkProduct(Product product);
        void addToStorage(Product product);
        void printProducts();
        void addToBasket(Product product);
        void printBasket();
};


#endif
