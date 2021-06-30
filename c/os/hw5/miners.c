#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int gold = 0;

void* mine(void* arg){
    for(int i = 0; i < 20; i++){
        pthread_mutex_lock(&mutex);
        gold+=10;
        printf("Miner %ld gathered 10 gold\n", (long)arg + 1);
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
}

void* sell(void* arg){
    for(int i = 0; i < 20; i++){
        pthread_mutex_lock(&mutex);
        if(gold > 0){
            gold-=10;
            printf("Trader %ld sold 10 gold\n", (long)arg + 1);
        } else {
            printf("The warehouse is empty, cannot sell!\n");
        }
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
}

int main(int argc, char* argv[]){
    int miners = 1, traders = 1;
    if(argc > 2) {
        miners = atoi(argv[1]);
        traders = atoi(argv[2]);
    }
    pthread_t miner_threads[miners];
    pthread_t trader_threads[traders];
    for(long i = 0; i < miners; i++){
        pthread_create(&miner_threads[i], NULL, mine, (void*)i);
    }
    for(long i = 0; i < traders; i++){
        pthread_create(&trader_threads[i], NULL, sell, (void*)i);
    }
    for(long i = 0; i < miners; i++){
        pthread_join(miner_threads[i], NULL);
    }
    for(long i = 0; i < traders; i++){
        pthread_join(trader_threads[i], NULL);
    }
    printf("Gold: %d\n", gold);
    return 0;
}