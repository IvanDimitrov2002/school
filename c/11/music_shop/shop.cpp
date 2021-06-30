#include "shop.h"

Shop::Shop(std::vector<AcousticGuitar> acousticGuitars, std::vector<ElectricGuitar> electricGuitars){
    this->acousticGuitars = acousticGuitars;
    this->electricGuitars = electricGuitars;
};

std::vector<Guitar> Shop::get_all_in_price_range(double from_price, double to_price) const {
    std::vector<Guitar> filteredGuitars;
    for(int i = 0; i < acousticGuitars.size(); i++){
        if(acousticGuitars[i].price >= from_price && acousticGuitars[i].price <= to_price){
            filteredGuitars.push_back(acousticGuitars[i]);
        }
    }
    for(int i = 0; i < electricGuitars.size(); i++){
        if(electricGuitars[i].price >= from_price && electricGuitars[i].price <= to_price){
            filteredGuitars.push_back(electricGuitars[i]);
        }
    }
    return filteredGuitars;
};

std::vector<Guitar> Shop::get_all_twelve_strings() const {
    std::vector<Guitar> filteredGuitars;
    for(int i = 0; i < acousticGuitars.size(); i++){
        if(acousticGuitars[i].strings == 12){
            filteredGuitars.push_back(acousticGuitars[i]);
        }
    }
    for(int i = 0; i < electricGuitars.size(); i++){
        if(electricGuitars[i].strings == 12){
            filteredGuitars.push_back(electricGuitars[i]);
        }
    }
    return filteredGuitars;
};

AcousticGuitar const& Shop::get_most_powerful_acoustic() const {
    if(acousticGuitars.size() == 0){
        throw AcousticGuitarNotAvaliable();
    }
    int index;
    float maxOutput = 0;
    for(int i = 0; i < acousticGuitars.size(); i++){
        if(maxOutput < acousticGuitars[i].output){
            maxOutput = acousticGuitars[i].output;
            index = i;
        }
    }
    return acousticGuitars[index];
};

ElectricGuitar const& Shop::get_most_powerful_electric() const {
    if(electricGuitars.size() == 0){
        throw ElectricGuitarNotAvaliable();
    }
    int index;
    float maxOutput = 0;
    for(int i = 0; i < electricGuitars.size(); i++){
        if(maxOutput < electricGuitars[i].pickupsOutput){
            maxOutput = electricGuitars[i].pickupsOutput;
        }
    }
    return electricGuitars[index];
};

void Shop::add_accoustic(AcousticGuitar const& acoustic){
    for(int i = 0; i < acousticGuitars.size(); i++){
        if(acoustic.id == acousticGuitars[i].id){
            throw GuitarAlreadyExists();
        }
    }
    acousticGuitars.push_back(acoustic);
};

void Shop::add_electric(ElectricGuitar const& electric){
    for(int i = 0; i < electricGuitars.size(); i++){
        if(electric.id == electricGuitars[i].id){
            throw GuitarAlreadyExists();
        }
    }
    electricGuitars.push_back(electric);
};

void Shop::buy(Guitar const& guitar){
    bool exists = false;
    for(int i = 0; i < acousticGuitars.size(); i++){
        if(acousticGuitars[i].strings == guitar.strings 
            && acousticGuitars[i].frets == guitar.frets 
            && acousticGuitars[i].weight == guitar.weight
            && acousticGuitars[i].brand == guitar.brand){
                exists = true;
                std::cout << "This acoustic guitar was bought" << std::endl;
            }
    }

    for(int i = 0; i < electricGuitars.size(); i++){
        if(electricGuitars[i].strings == guitar.strings 
            && electricGuitars[i].frets == guitar.frets 
            && electricGuitars[i].weight == guitar.weight
            && electricGuitars[i].brand == guitar.brand){
                exists = true;
                std::cout << "This electric guitar was bought" << std::endl;
            }
    }

    if(!exists) throw GuitarDoesntExist();
};
