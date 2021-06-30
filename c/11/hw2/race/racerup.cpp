#include "racerup.h"

void RacerUp::moveForward(Race& race){
    std::vector<std::pair<unsigned int, unsigned int>> positions = race.getPositions();
    std::vector<std::vector<Racer*>> racers = race.getRacers();
    int currPosition = race.getCurrPosition();
    int speed = this->getSpeed(); //if using directly 'speed' sometimes it is random????
    if(positions[currPosition].first != 0 && racers[positions[currPosition].first - 1][positions[currPosition].second] == NULL){
        racers[positions[currPosition].first - 1][positions[currPosition].second] = racers[positions[currPosition].first][positions[currPosition].second];
        racers[positions[currPosition].first][positions[currPosition].second] = NULL;
        positions[currPosition].first--;
        position.first = positions[currPosition].first;
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