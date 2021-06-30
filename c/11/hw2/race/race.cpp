#include <iostream>
#include "race.h"

Race::Race(){
    std::vector<Racer*> winners(3);
    this->winners = winners;
}

Race::Race(int cellCount){
    std::vector<Racer*> winners(3);
    this->winners = winners;
    this->cellCount = cellCount;
}

Race::Race(int cellCount, std::vector<std::vector<Racer*>> racers){
    this->racers = racers;
    this->racerCount = racers.size();
    this->cellCount = cellCount;
    std::vector<Racer*> winners(3);
    this->winners = winners;
    for(int i = 0; i < racerCount; i++){
        std::pair<unsigned int, unsigned int> position;
        position.first = i;
        position.second = 0;
        positions.push_back(position);
    }
}

Race::Race(const Race& race){
    this->winners = race.winners;
    this->racerCount = race.racerCount;
    this->cellCount = race.cellCount;
    this->positions = race.positions;
    this->racers = race.racers;
}

std::vector<std::vector<Racer*>> Race::getRacers(){
    return racers;
}

std::vector<Racer*> Race::getWinners(){
    return winners;
}

std::vector<std::pair<unsigned int, unsigned int>> Race::getPositions(){
    return positions;
}

int Race::getCurrPosition(){
    return currPosition;
}

int Race::getCellCount(){
    return cellCount;
}

int Race::getRacerCount(){
    return racerCount; 
}

void Race::setRacers(std::vector<std::vector<Racer*>> racers){
    this->racers = racers;
}

void Race::setWinners(std::vector<Racer*> winners){
    this->winners = winners;
}

void Race::setPositions(std::vector<std::pair<unsigned int, unsigned int>> positions){
    this->positions = positions;
}

void Race::setCurrPosition(int position){
    this->currPosition = position;
}

void Race::startRace(){
    if(racerCount < 3){
        throw NotEnoughRacers();
    }
    while(true){
        if(winners[0] != NULL && winners[1] != NULL && winners[2] != NULL) break;
        for(int i = 0; i < racerCount; i++){
            currPosition = i;
            if(racers[positions[i].first][positions[i].second] != NULL){
                racers[positions[i].first][positions[i].second]->moveForward(*this);
            }
        }
    }
    std::cout << "Name: " << winners[0]->getName() << " Place: 1st" << std::endl;
    std::cout << "Name: " << winners[1]->getName() << " Place: 2nd" << std::endl;
    std::cout << "Name: " << winners[2]->getName() << " Place: 3rd" << std::endl;
}


void Race::addRacer(Racer* racer){
    std::vector<Racer*> cell(cellCount);
    cell.at(0) = racer;
    racers.push_back(cell);
    std::pair<unsigned int, unsigned int> position;
    position.first = racerCount;
    position.second = 0;
    positions.push_back(position);
    racerCount++;
}