#ifndef ELECTRONIC_H
#define ELECTRONIC_H

#include "product.h"
#include <string>

class Electronic : public Product {
    public:
        std::string type;
        std::string warrenty;
        std::string terms;
};


#endif
