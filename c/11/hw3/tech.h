#ifndef TECH_H
#define TECH_H

#include "item.h"

class Tech : public Item{
    private:
        TechType type;
        unsigned int years;
        double weight;

    public:
        Tech(){};

        Tech(std::string name, double price, bool available, Supplier supplier, unsigned int daysToDeliver, unsigned int quantity, TechType type, unsigned int years, double weight);

        Tech(const Tech& tech);
        
        TechType getType();
        unsigned int getYears();
        double getWeight();

        void setType(TechType type);
        void setYears(unsigned int years);
        void setWeight(double weight);
};

#endif