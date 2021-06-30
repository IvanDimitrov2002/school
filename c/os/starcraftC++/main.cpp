#include "commandcenter.h"
#include <iostream>

int main(int argc, char *argv[]){
    int mineralBlocks = 2;
    if(argc > 1){
        mineralBlocks = std::stoi(argv[1]);
    }
    CommandCenter commandCenter = CommandCenter(0, 0, 5, mineralBlocks);
    commandCenter.joinInput();
    commandCenter.joinSCVs();
    std::cout << "Map minerals " << 500*mineralBlocks << ", player minerals " << commandCenter.getMinerals() 
    << ", SCVs " << commandCenter.getSCVs().size() << ", Marines " << commandCenter.getMarines() << std::endl;
    return 0;
}