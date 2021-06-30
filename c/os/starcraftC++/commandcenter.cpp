#include "commandcenter.h"

#include <iostream>
#include <unistd.h>
#include "scv.h"

CommandCenter::CommandCenter(){
    for(int i = 0; i < 2; i++){
        this->mineralBlocks.push_back(MineralBlock());
    }
    for(int i = 0; i < 5; i++){
        this->scvs.push_back(new SCV(mineralBlocks, minerals, mineralsMutex));
    }
    thread = std::thread(&CommandCenter::input, this);
}

CommandCenter::CommandCenter(int marines, int minerals, int scvs, int mineralBlocks){
    this->marines = marines;
    this->minerals = minerals;
    for(int i = 0; i < mineralBlocks; i++){
        this->mineralBlocks.push_back(MineralBlock());
    }
    for(int i = 0; i < scvs; i++){
        this->scvs.push_back(new SCV(this->mineralBlocks, this->minerals, mineralsMutex));
    }
    thread = std::thread(&CommandCenter::input, this);
}

CommandCenter::~CommandCenter(){
    for(unsigned long i = 0; i < scvs.size(); i++){
        delete scvs[i];
    }
}

int CommandCenter::getMarines(){
    return marines;
}

int CommandCenter::getMinerals(){
    return minerals;
}

std::vector<SCV*> CommandCenter::getSCVs(){
    return scvs;
}

std::vector<MineralBlock> CommandCenter::getMineralBlocks(){
    return mineralBlocks;
}


void CommandCenter::setMarines(int marines){
    this->marines = marines;
}

void CommandCenter::setMinerals(int minerals){
    this->minerals = minerals;
}

void CommandCenter::setSCVs(std::vector<SCV*> scvs){
    this->scvs = std::vector<SCV*>(scvs);
}

void CommandCenter::setMineralBlocks(std::vector<MineralBlock> mineralBlocks){
    this->mineralBlocks = std::vector<MineralBlock>(mineralBlocks);
}

void CommandCenter::input(){
    while(true){
        char ch;
        std::cin >> ch;
        if(ch == 'm'){
            if(marines + scvs.size() < 200){
                mineralsMutex.lock();
                if(minerals >= 50){
                    minerals -= 50;
                    mineralsMutex.unlock();
                    sleep(1);
                    std::cout << "You wanna piece of me, boy?" << std::endl;
                    marines++;
                    if(marines >= 20) break;
                } else {
                    mineralsMutex.unlock();
                    std::cout << "Not enough minerals." << std::endl;
                }
            }
        } else if(ch == 's'){
            if(marines + scvs.size() < 200){
                mineralsMutex.lock();
                if(minerals >= 50){
                    minerals -= 50;
                    mineralsMutex.unlock();
                    sleep(4);
                    scvs.push_back(new SCV(mineralBlocks, minerals, mineralsMutex));
                    std::cout << "SCV good to go, sir." << std::endl;
                } else {
                    mineralsMutex.unlock();
                    std::cout << "Not enough minerals." << std::endl;
                }
            }
        }
    }
}

void CommandCenter::joinInput(){
    thread.join();
}

void CommandCenter::joinSCVs(){
    for(unsigned long i = 0; i < scvs.size(); i++){
        scvs[i]->join();
    }
}