#include <pthread.h>
#include <stdio.h>

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
}

int main(){
    char c;
    unsigned long range;
    while(1){
        c = getchar();
        getchar();
        if(c == 'p'){
            scanf("%lu", &range);
            getchar();
            pthread_t thread;
            long* return_value;
            if(pthread_create(&thread, NULL, get_primes, (void*)range) == -1){
                perror("pthread_create");
                return -1;
            }
        } else if(c == 'e'){
            break;
        } else {
            printf("Supported commands:\np N - Starts a new calculation for the number of primes from 1 to N\ne - Waits for all calculations to finish and exits\n");
        }
    }
    return 0;
}