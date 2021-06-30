#include <iostream>
#include "race.h"
#include "racerright.h"
#include "racerup.h"
#include "racerdiagonal.h"

int main(){
    Racer* racer1 = new RacerDiagonal("Steven", 2);
    Racer* racer2 = new RacerRight("John", 3);
    Racer* racer3 = new RacerRight("Amber", 5);
    Racer* racer4 = new RacerUp("Ivan", 10);
    std::vector<std::vector<Racer*>> racers;
    Race race = Race(10);
    race.addRacer(racer1);
    race.addRacer(racer2);
    race.addRacer(racer3);
    race.addRacer(racer4);
    race.startRace();
    delete racer1;
    delete racer2;
    delete racer3;
    delete racer4;
    return 0;
}