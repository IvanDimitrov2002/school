//--------------------------------------------
// NAME: Ivan Dimitrov
// CLASS: Xib
// NUMBER: 13
// PROBLEM: #3
// FILE NAME: main.c
// FILE PURPOSE:
// Starcraft functionality
//---------------------------------------------
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int marines = 0;
int workersCount = 5;
int minerals = 0;
int mineralBlocksCount = 2;
int *mineralBlocks = NULL;
pthread_mutex_t *mutex = NULL;
pthread_t workers[200];
pthread_mutex_t mineralsMutex;

/*
 * This function checks if all mineral blocks on the map are empty
 * @return Returns 1 if all blocks are empty and 0 otherwise
 */
int checkBlocks(){
    for(int i = 0 ; i < mineralBlocksCount; i++){
        if(pthread_mutex_lock(&mutex[i]) != 0){
            perror("pthread_mutex_lock");
        }
        if(mineralBlocks[i] > 0){
            if(pthread_mutex_unlock(&mutex[i]) != 0){
                perror("pthread_mutex_unlock");
            }
            return 0;
        }
        if(pthread_mutex_unlock(&mutex[i]) != 0){
            perror("pthread_mutex_unlock");
        }
    }
    return 1;
}

/*
 * This function is being executed when new SCV thread is created
 * Each SCV checks for non-empty and available block from which it can mine
 * @param arg The index of the SCV e.g. 0, 1, 2, ...
 * @return Returns NULL if checkBlocks() returns 1
 */
void* work(void* arg){
    while(1){
        for(int i = 0; i < mineralBlocksCount; i++){
            sleep(3);
            if(pthread_mutex_lock(&mutex[i]) != 0){
                perror("pthread_mutex_lock");
            }
            if(mineralBlocks[i] > 0){
                if(pthread_mutex_unlock(&mutex[i]) != 0){
                    perror("pthread_mutex_unlock");
                }
                if(pthread_mutex_trylock(&mutex[i]) == 0){
                    int toBeMined = 8;
                    if(mineralBlocks[i] < 8){
                        toBeMined = mineralBlocks[i];
                    }
                    printf("SCV %ld is mining from mineral block %d\n", (long)arg+1, i+1);
                    mineralBlocks[i] -= toBeMined;
                    if(pthread_mutex_unlock(&mutex[i]) != 0){
                        perror("pthread_mutex_unlock");
                    }
                    printf("SCV %ld is transporting minerals\n", (long)arg+1);
                    sleep(2);
                    if(pthread_mutex_lock(&mineralsMutex) != 0){
                        perror("pthread_mutex_lock");
                    }
                    printf("SCV %ld delivered minerals to the Command center\n", (long)arg+1);
                    minerals += toBeMined;
                    if(pthread_mutex_unlock(&mineralsMutex) != 0){
                        perror("pthread_mutex_unlock");
                    }
                    break;
                }
            } else {
                if(pthread_mutex_unlock(&mutex[i]) != 0){
                    perror("pthread_mutex_unlock");
                }
            }
        }
        
        if(checkBlocks()) return NULL;
    }
}

/*
 * Gets input from the stdin.
 * It has 'm' option which creates a new marine 
 * and 's' option which creates a new SCV
 * @return Returns NULL if 20 marines are created
 */
void* input(){
    while(1) {
        char ch = getchar();
        getchar();
        if(ch == 'm'){
            if(marines + workersCount < 200){
                if(pthread_mutex_lock(&mineralsMutex) != 0){
                    perror("pthread_mutex_lock");
                }
                if(minerals >= 50){
                    minerals -= 50;
                    if(pthread_mutex_unlock(&mineralsMutex) != 0){
                        perror("pthread_mutex_unlock");
                    }
                    sleep(1);
                    printf("You wanna piece of me, boy?\n");
                    marines++;
                    if(marines >= 20){
                        break;
                    }
                } else {
                    if(pthread_mutex_unlock(&mineralsMutex) != 0){
                        perror("pthread_mutex_unlock");
                    }
                    printf("Not enough minerals.\n");
                }
            }
        } else if(ch == 's'){
            if(marines + workersCount < 200){
                if(pthread_mutex_lock(&mineralsMutex) != 0){
                    perror("pthread_mutex_lock");
                }
                if(minerals >= 50){
                    minerals -= 50;
                    if(pthread_mutex_unlock(&mineralsMutex) != 0){
                        perror("pthread_mutex_unlock");
                    }
                    sleep(4);
                    if(pthread_create(&workers[workersCount], NULL, work, (void*)(long)workersCount) != 0){
                        perror("pthread_create");
                        pthread_exit(NULL);
                        exit(-1);
                    }
                    printf("SCV good to go, sir.\n");
                    workersCount++;
                } else {
                    if(pthread_mutex_unlock(&mineralsMutex) != 0){
                        perror("pthread_mutex_unlock");
                    }
                    printf("Not enough minerals.\n");
                }
            }
        }
    }
    return NULL;
}

/*
 * Defines the count of the mineral blocks
 * Creates all necessary mutexes
 * Creates and joins all necessary threads
 * Waits for all threads to end their jobs
 * then prints all the information about the game
 * then destroys all mutexes and frees the allocated memory
 * @param argc Number of console arguments
 * @param argv Array of strings with console arguments
 * @return Returns 0
 */
int main(int argc, char* argv[]){
    if(argc > 1){
        mineralBlocksCount = atoi(argv[1]);
    }
    mutex = malloc(sizeof(pthread_mutex_t) * mineralBlocksCount);
    mineralBlocks = malloc(sizeof(int) * mineralBlocksCount);
    if(pthread_mutex_init(&mineralsMutex, NULL) != 0){
        perror("pthread_mutex_init");
    }
    for(int i = 0; i < mineralBlocksCount; i++){
        if(pthread_mutex_init(&mutex[i], NULL) != 0){
            perror("pthread_mutex_init");
        }
        mineralBlocks[i] = 500;
    }
    pthread_t inputThread;
    if(pthread_create(&inputThread, NULL, input, NULL) != 0){
        perror("pthread_create");
        pthread_exit(NULL);
        exit(-1);
    }
    for(long i = 0; i < workersCount; i++){
        if(pthread_create(&workers[i], NULL, work, (void *)i) != 0){
            perror("pthread_create");
            pthread_exit(NULL);
            exit(-1);
        }
    }
    if(pthread_join(inputThread, NULL) != 0){
        perror("pthread_join");
        pthread_exit(NULL);
        exit(-1);
    }
    for(int i = 0; i < workersCount; i++){
        if(pthread_join(workers[i], NULL) != 0){
            perror("pthread_join");
            pthread_exit(NULL);
            exit(-1);
        }
    }
    printf("Map minerals %d, player minerals %d, SCVs %d, Marines %d\n", mineralBlocksCount*500, minerals, workersCount, marines);
    if(pthread_mutex_destroy(&mineralsMutex) != 0){
        perror("pthread_mutex_destroy");
    }
    for(int i = 0; i < mineralBlocksCount; i++){
        if(pthread_mutex_destroy(&mutex[i]) != 0){
            perror("pthread_mutex_destroy");
        }
    }
    free(mutex);
    free(mineralBlocks);
    pthread_exit(NULL);
    return 0;
}