#ifndef FOOD_H
#define FOOD_H

#include "product.h"
#include <string>

class Food : public Product {
    public:
        std::string type;
        std::string expirationDate;
        std::string allergens;
        bool bds;
};

#endif
