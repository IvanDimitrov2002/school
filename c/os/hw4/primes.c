#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** parse_string(char* string){
    int i = 0;
    char *t = strtok(string, " ");
    char **parsedString = NULL;

    while (t != NULL)
    {
        parsedString = realloc(parsedString, sizeof(char *) * (i+1));
        parsedString[i++] = t;
        t = strtok (NULL, " ");
    }
    
    return parsedString;
}

int check_number(char *string){
    if(string != NULL){
        for(int i = 0; i < strlen(string); i++){
            if(!(string[i] >= '0' && string[i] <= '9')){
                return 0;
            }
        }
    } else {
        return 0;
    }
    return 1;
}

void* get_primes(void *arg){
    long range = (long)arg;
    printf("Prime calculation started for N=%d\n", range);
    int primes = 0;
    for(int i = 2; i < range; i++){
        int is_prime = 1;
        for(int j = 2; j <= i/2 ; j++){
            if(i % j == 0)
            {
                is_prime = 0;
                break;
            }
        }
        if(is_prime == 1) primes++;
    }

    printf("Number of primes for N=%d is %d\n", range, primes);
    pthread_exit(NULL);
}

int main(){
    char buffer[100];
    char **commands;
    while(1){
        fgets(buffer, 100, stdin);
        buffer[strlen(buffer)-1] = '\0';
        commands = parse_string(buffer);
        if(strcmp(commands[0], "p") == 0 && check_number(commands[1])){
            pthread_t thread;
            long range = atoi(commands[1]);
            if(pthread_create(&thread, NULL, get_primes, (void*)range) == -1){
                perror("pthread_create");
                exit(-1);
            }
        } else if(strcmp(commands[0], "e") == 0){
            break;
        } else {
            printf("Supported commands:\np N - Starts a new calculation for the number of primes from 1 to N\ne - Waits for all calculations to finish and exits\n");
        }
        free(commands);
    }
    free(commands);
    pthread_exit(NULL);
    return 0;
}