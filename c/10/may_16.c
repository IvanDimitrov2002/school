#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct human_t{
    int worms;
    int mas;
    int hlqb;
    int gummy;
    int caught_fishes;
};

struct fish_t{
    float worms_chance;
    float mas_chance;
    float hlqb_chance;
    float gummy_chance;
};

struct cell_t{
    struct fish_t *cod;
    int cod_count;
    struct fish_t *pufferfish;
    int pufferfish_count;
    struct fish_t *clownfish;
    int clownfish_count;
    struct fish_t *salmon;
    int salmon_count;
};

int main(){
    srand(time(0));
    struct human_t human;
    struct cell_t cell;
    int chance=rand();
    cell.cod_count=0;
    cell.clownfish_count=0;
    cell.pufferfish_count=0;
    cell.salmon_count=0;
    int bait;
    human.worms=10;
    human.mas=10;
    human.hlqb=10;
    human.gummy=10;
    int holes[15];
    int chosen_hole;
    for(int i=0;i<15;i++)
        holes[i]=rand();
    printf("Choose your hole: \n");
    scanf("%d", chosen_hole);
    printf("1 for worms\n2 for mas\n3 for hlqb\n4 for gummy\n");
    printf("Choose your bait: \n");
    scanf("%d", &bait);
    if(chance<=holes[chosen_hole]){
        for(int i=0;i<4;i++){
            if(chance<cell.)
        }
    }
    return 0;
}