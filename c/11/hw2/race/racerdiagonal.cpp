#include "racerdiagonal.h"
#include <iostream>

void RacerDiagonal::moveForward(Race& race){
    std::vector<std::pair<unsigned int, unsigned int>> positions = race.getPositions();
    std::vector<std::vector<Racer*>> racers = race.getRacers();
    int currPosition = race.getCurrPosition();
    int speed = this->getSpeed(); //if using directly 'speed' sometimes it is random????
    if(positions[currPosition].first != (race.getRacerCount() - 1) && racers[positions[currPosition].first + 1][positions[currPosition].second + 1] == NULL){
        racers[positions[currPosition].first + 1][positions[currPosition].second + 1] = racers[positions[currPosition].first][positions[currPosition].second];
        racers[positions[currPosition].first][positions[currPosition].second] = NULL;
        positions[currPosition].first++;
        positions[currPosition].second++;
        position.first = positions[currPosition].first;
        position.second = positions[currPosition].second;
        if(positions[currPosition].second == (race.getCellCount() - 1)){
            std::vector<Racer*> winners = race.getWinners();
            for(int i = 0; i < 3; i++){
                if(winners[i] == NULL){
                    winners[i] = racers[positions[currPosition].first][positions[currPosition].second];
                    race.setWinners(winners);
                    racers[positions[currPosition].first][positions[currPosition].second] = NULL;
                    race.setPositions(positions);
                    race.setRacers(racers);
                    return;
                }
            }
        }
        race.setPositions(positions);
        race.setRacers(racers);
    }
    if(positions[currPosition].second > 0 && racers[positions[currPosition].first][positions[currPosition].second - 1] == NULL){
        racers[positions[currPosition].first][positions[currPosition].second - 1] = racers[positions[currPosition].first][positions[currPosition].second];
        racers[positions[currPosition].first][positions[currPosition].second] = NULL;
        positions[currPosition].second--;
        position.second = positions[currPosition].second;
        race.setPositions(positions);
        race.setRacers(racers);
    }
    if(positions[currPosition].first != 0 && racers[positions[currPosition].first - 1][positions[currPosition].second + 1] == NULL){
        racers[positions[currPosition].first - 1][positions[currPosition].second + 1] = racers[positions[currPosition].first][positions[currPosition].second];
        racers[positions[currPosition].first][positions[currPosition].second] = NULL;
        positions[currPosition].first--;
        positions[currPosition].second++;
        position.first = positions[currPosition].first;
        position.second = positions[currPosition].second;
        if(positions[currPosition].second == (race.getCellCount() - 1)){
            std::vector<Racer*> winners = race.getWinners();
            for(int i = 0; i < 3; i++){
                if(winners[i] == NULL){
                    winners[i] = racers[positions[currPosition].first][positions[currPosition].second];
                    race.setWinners(winners);
                    racers[positions[currPosition].first][positions[currPosition].second] = NULL;
                    race.setPositions(positions);
                    race.setRacers(racers);
                    return;
                }
            }
        }
        race.setPositions(positions);
        race.setRacers(racers);
    }
    for(int i = 0; i < speed; i++){
        if(positions[currPosition].second != (race.getCellCount() - 1) && racers[positions[currPosition].first][positions[currPosition].second + 1] == NULL){
            racers[positions[currPosition].first][positions[currPosition].second + 1] = racers[positions[currPosition].first][positions[currPosition].second];
            racers[positions[currPosition].first][positions[currPosition].second] = NULL;
            positions[currPosition].second++;
            position.second = positions[currPosition].second;
            if(positions[currPosition].second == (race.getCellCount() - 1)){
                std::vector<Racer*> winners = race.getWinners();
                for(int i = 0; i < 3; i++){
                    if(winners[i] == NULL){
                        winners[i] = racers[positions[currPosition].first][positions[currPosition].second];
                        race.setWinners(winners);
                        racers[positions[currPosition].first][positions[currPosition].second] = NULL;
                        break;
                    }
                }
            }
            race.setPositions(positions);
            race.setRacers(racers);
        } else {
            break;
        }
    }
}