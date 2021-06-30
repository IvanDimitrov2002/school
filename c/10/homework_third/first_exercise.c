#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct gun_t {
    char model[128];
    int accuracy;
    int ammo_capacity;
};

/*
    Проверява дали точките са от 0 до gun_accuracy.
    Инициализира брояч и точките, през които ще следва различен иинтервал.
    Увеличава точността на оръжието с 1, за да започне първият интервал.
    Изчислява разликата между максималния брой точки (10) и точките,
    които по-долу ще бъдат получени. 
    Връща получените точки.
*/
int get_score(int gun_accuracy, int shot_accuracy){
    if(shot_accuracy<=gun_accuracy) return 10; 
    int i,score_per_interval=(100-gun_accuracy)/10; 
    gun_accuracy++;
    for(i=0;gun_accuracy<=shot_accuracy;i++){
        gun_accuracy+=score_per_interval;
    }
    return 10-i;
}

/*
    Запазва точките на даден изтрел и общите точки. 
    Принтира точките според подадените на функцията точности и запазва точките.
    Принтира общите точки и средноаритметичната стойност.
*/
void test_gun(struct gun_t gun, int shot_count){
    int stored_random_score,total_score=0;                                                      
    for(int i=0;i<shot_count;i++){                            
        printf("%d\n", stored_random_score=get_score(gun.accuracy, rand()%101)); 
        total_score+=stored_random_score; 
    }                                                       
    printf("Total score: %d\n", total_score); 
    printf("Average score: %.2f\n", (float) total_score/shot_count);
}

// Променя seed-a, който бива изполван от rand(), за да не бъде едно и също числото, което rand() ще върне.
int main(){
    srand(time(NULL)); 
    struct gun_t gun; 
    gun.accuracy = 10;
    test_gun(gun,3);
    return 0;
}