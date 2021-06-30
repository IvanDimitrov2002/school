#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "supplier.h"

enum TechType {White, Black, Consumable, None};

class Item{
    protected:
        std::string name;
        double price;
        bool available;
        Supplier supplier;
        unsigned int daysToDeliver;
        unsigned int quantity;

    public:
        Item(){};

        Item(std::string name, double price, bool available, Supplier supplier, unsigned int daysToDeliver, unsigned int quantity);

        Item(const Item* item);

        std::string getName() const;
        double getPrice() const;
        bool isAvailable() const;
        Supplier getSupplier() const;
        unsigned int getDays() const;
        unsigned int getQuantity() const;

        void setName(std::string name);
        void setPrice(double price);
        void setAvailable(bool available);
        void setSupplier(Supplier supplier);
        void setDays(unsigned int daysToDeliver);
        void setQuantity(unsigned int quantity);

        virtual TechType getType();
        virtual unsigned int getYears();
        virtual double getWeight();
        virtual std::string getColor();
        virtual unsigned int getSize();
        virtual std::string getMaterial();

        virtual void setType(TechType type){};
        virtual void setYears(unsigned int years){};
        virtual void setWeight(double weight){};
        virtual void setColor(std::string color){};
        virtual void setSize(unsigned int size){};
        virtual void setMaterial(std::string material){};

        bool operator==(Item& item);
};

#endif