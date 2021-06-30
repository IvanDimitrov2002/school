#ifndef SCV_H
#define SCV_H

#include <thread>
#include <vector>
#include "mineralblock.h"

class SCV{
    private:
        static int initialized;
        int id;
        std::thread thread;
    
    public:
        SCV(std::vector<MineralBlock> &mineralBlocks, int &minerals, std::mutex &mineralsMutex);

        SCV(int id, std::vector<MineralBlock> &mineralBlocks, int &minerals, std::mutex &mineralsMutex);

        int getId();

        void setId(int id);

        void work(int id, std::vector<MineralBlock> &mineralBlocks, int &minerals, std::mutex &mineralsMutex);
        void join();
        bool checkMineralBlocks(std::vector<MineralBlock> &mineralBlocks);
};

#endif