#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
    public:
        Product();
        Product(std::string name, std::string producer, float price, std::string barcode, std::string description);
        std::string name;
        std::string producer;
        float price;
        std::string barcode;
        std::string description; 
    };

#endif
