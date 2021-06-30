#ifndef MINERALBLOCK_H
#define MINERALBLOCK_H

#include <mutex>

class MineralBlock{
    private:
        std::mutex mutex;
        int minerals = 500;

    public:
        MineralBlock(){};

        MineralBlock(int minerals);

        MineralBlock(const MineralBlock& mineralBlock);

        int getMinerals();

        void setMinerals(int minerals);

        void lock();
        bool try_lock();
        void unlock();
};

#endif