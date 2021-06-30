#ifndef RACE_H
#define RACE_H

#include <vector>
#include "racer.h"

class Racer;

class Race{
    private:
        int racerCount = 0;
        int cellCount = 0;
        int currPosition;
        std::vector<Racer*> winners;
        std::vector<std::pair<unsigned int, unsigned int>> positions;
        std::vector<std::vector<Racer*>> racers;
    public:
        
        class NotEnoughRacers : std::exception{};

        Race();

        Race(int cellCount);

        Race(int cellCount, std::vector<std::vector<Racer*>> racers);

        Race(const Race& race);

        std::vector<std::vector<Racer*>> getRacers();
        std::vector<Racer*> getWinners();
        std::vector<std::pair<unsigned int, unsigned int>> getPositions();
        int getCurrPosition();
        int getCellCount();
        int getRacerCount();

        void setRacers(std::vector<std::vector<Racer*>> racers);
        void setWinners(std::vector<Racer*> winners);
        void setPositions(std::vector<std::pair<unsigned int, unsigned int>> positions);
        void setCurrPosition(int position);

        void addRacer(Racer* racer);
        void startRace();
};

#endif