#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>

class Supplier{
    private:
        std::string name;
    public:
        Supplier(){};

        Supplier(std::string name);

        Supplier(const Supplier& supplier);

        std::string getName() const;
        void setName(std::string name);
};

#endif