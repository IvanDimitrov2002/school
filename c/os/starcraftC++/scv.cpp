#include "scv.h"
#include <unistd.h>
#include <iostream>

int SCV::initialized = 0;

SCV::SCV(std::vector<MineralBlock> &mineralBlocks, int &minerals, std::mutex &mineralsMutex)
{
    initialized++;
    this->id = initialized;
    thread = std::thread(&SCV::work, this, id, std::ref(mineralBlocks), std::ref(minerals), std::ref(mineralsMutex));
}

SCV::SCV(int id, std::vector<MineralBlock> &mineralBlocks, int &minerals, std::mutex &mineralsMutex)
{
    initialized++;
    this->id = id;
    thread = std::thread(&SCV::work, this, id, std::ref(mineralBlocks), std::ref(minerals), std::ref(mineralsMutex));
}

int SCV::getId()
{
    return id;
}

void SCV::setId(int id)
{
    this->id = id;
}

bool SCV::checkMineralBlocks(std::vector<MineralBlock> &mineralBlocks)
{
    for (unsigned long i = 0; i < mineralBlocks.size(); i++)
    {
        mineralBlocks[i].lock();
        if (mineralBlocks[i].getMinerals() > 0)
        {
            mineralBlocks[i].unlock();
            return false;
        }
        mineralBlocks[i].unlock();
    }
    return true;
}

void SCV::work(int id, std::vector<MineralBlock> &mineralBlocks, int &minerals, std::mutex &mineralsMutex)
{
    while (true)
    {
        for (unsigned long i = 0; i < mineralBlocks.size(); i++)
        {
            sleep(3);
            mineralBlocks[i].lock();
            if (mineralBlocks[i].getMinerals() > 0)
            {
                mineralBlocks[i].unlock();
                if (mineralBlocks[i].try_lock())
                {
                    int toBeMined = 8;
                    if (mineralBlocks[i].getMinerals() < 8)
                    {
                        toBeMined = mineralBlocks[i].getMinerals();
                    }
                    std::cout << "SCV " << id << " is mining from mineral block " << i + 1 << std::endl;
                    mineralBlocks[i].setMinerals(mineralBlocks[i].getMinerals() - toBeMined);
                    mineralBlocks[i].unlock();
                    std::cout << "SCV " << id << " is transporting minerals" << std::endl;
                    sleep(2);
                    mineralsMutex.lock();
                    std::cout << "SCV " << id << " delivered minerals to the Command center" << std::endl;
                    minerals += toBeMined;
                    mineralsMutex.unlock();
                    break;
                }
            }
            else
            {
                mineralBlocks[i].unlock();
            }
        }
        if (checkMineralBlocks(mineralBlocks))
            break;
    }
}

void SCV::join()
{
    thread.join();
}