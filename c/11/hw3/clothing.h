#ifndef CLOTHING_H
#define CLOTHING_H

#include "item.h"

class Clothing : public Item{
    private:
        std::string color;
        unsigned int size;
        std::string material;

    public:
        Clothing(){};

        Clothing(std::string name, double price, bool available, Supplier supplier, unsigned int daysToDeliver, unsigned int quantity, std::string color, unsigned int size, std::string material);

        Clothing(const Clothing& clothing);

        std::string getColor();
        unsigned int getSize();
        std::string getMaterial();

        void setColor(std::string color);
        void setSize(unsigned int size);
        void setMaterial(std::string material);
};

#endif