#ifndef COMMANDCENTER_H
#define COMMANDCENTER_H

#include <vector>
#include "scv.h"
#include "mineralblock.h"
#include <thread>
#include <mutex>

class CommandCenter{
    private:
        int marines = 0;
        int minerals = 0;
        std::vector<SCV*> scvs;
        std::vector<MineralBlock> mineralBlocks;
        std::thread thread;
        std::mutex mineralsMutex;

    public:
        CommandCenter();

        CommandCenter(int marines, int minerals, int scvs, int mineralBlocks);

        CommandCenter(const CommandCenter& commandCenter);

        ~CommandCenter();

        int getMarines();
        int getMinerals();
        std::vector<SCV*> getSCVs();
        std::vector<MineralBlock> getMineralBlocks();

        void setMarines(int marines);
        void setMinerals(int minerals);
        void setSCVs(std::vector<SCV*> scvs);
        void setMineralBlocks(std::vector<MineralBlock> mineralBlocks);

        void input();
        void joinInput();
        void joinSCVs();
};

#endif