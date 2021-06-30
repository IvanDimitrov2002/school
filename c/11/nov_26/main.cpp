#include <iostream>
#include "flying_fish.h"
#include "whale.h"
#include "salmon.h"
#include "lion.h"
#include "seagull.h"
#include "ostrich.h"

int main(){
    FlyingFish my_fish = FlyingFish();
    my_fish.runaway();
    my_fish.fly();
    return 0;
}