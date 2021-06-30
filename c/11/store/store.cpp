#include "store.h"
#include "product.h"
#include <iostream>

bool Store::checkProduct(Product product){
    
};

void Store::printProducts(){
    for(int i = 0; i < products.size(); i++){
        std::cout << "Product name: " << products[i].name << std::endl;
        std::cout << "Product description: " << products[i].description << std::endl;
        std::cout << "Product price: " << products[i].price << std::endl;
        std::cout << "Product producer: " << products[i].producer << std::endl;
        std::cout << "Product barcode: " << products[i].barcode << std::endl;
        std::cout << std::endl;
    }
};

void Store::addToStorage(Product product){
    products.push_back(product);
};

void Store::addToBasket(Product product){

};

void Store::printBasket(){

};