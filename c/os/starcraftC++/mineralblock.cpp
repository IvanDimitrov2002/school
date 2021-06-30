#include "mineralblock.h"

MineralBlock::MineralBlock(int minerals){
    this->minerals = minerals;
}

MineralBlock::MineralBlock(const MineralBlock& mineralBlock){
    this->minerals = mineralBlock.minerals;
}

int MineralBlock::getMinerals(){
    return minerals;
}

void MineralBlock::setMinerals(int minerals){
    this->minerals = minerals;
}

void MineralBlock::lock(){
    mutex.lock();
}

void MineralBlock::unlock(){
    mutex.unlock();
}

bool MineralBlock::try_lock(){
    return mutex.try_lock();
}