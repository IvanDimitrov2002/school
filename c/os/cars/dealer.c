#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#define DRIVERS 20
#define CARS 5

pthread_mutex_t cars[CARS];

void* drive_car(void* driver){
    while(1){
        for(int i = 0; i < CARS; i++){
            if(pthread_mutex_trylock(&cars[i]) == 0){
                printf("Buyer %ld takes car %d.\n", (long)driver, i);
                pthread_mutex_unlock(&cars[i]);
                printf("Buyer %ld returns car %d.\n", (long)driver, i);
                return NULL;
            }
        }
    }
    return NULL;
}

int main(){
    pthread_t drivers[DRIVERS];
    for(int i = 0; i < CARS; i++){
        pthread_mutex_init(&cars[i], NULL);
    }

    for(long i = 0; i < DRIVERS; i++){
        pthread_create(&drivers[i], NULL, drive_car, (void*)i);
    }

    for(long i = 0; i < DRIVERS; i++){
        pthread_join(drivers[i], NULL);
    }

    for(int i = 0; i < CARS; i++){
        pthread_mutex_destroy(&cars[i]);
    }
    return 0;
}