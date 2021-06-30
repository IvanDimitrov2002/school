#include <stdio.h>
#include <stdlib.h>

void train_delay(int n){
    int wagons[4] = {0,0,0,0};
    int passengers, passengers_left, total_time=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            scanf("%d", &passengers);
            total_time+=passengers;
            wagons[j]-=passengers;
        }
        printf("Passengers: %d %d %d %d\n", wagons[0], wagons[1], wagons[2], wagons[3]);
        passengers_left=0;
        for(int j=0;j<4;j++){
            scanf("%d", &passengers);
            if(wagons[j]+passengers>n){
                total_time+=(n-wagons[j]);
                passengers_left+=passengers-(n-wagons[j]);
                wagons[j]=n;
            }
            else{
                wagons[j]+=passengers;
                total_time+=passengers;
            } 
        }
        if(passengers_left>0) printf("There wasn't room for %d passengers\n", passengers_left);
        printf("Passengers: %d %d %d %d\n", wagons[0], wagons[1], wagons[2], wagons[3]);
    }
    printf("Total wait time: %d", total_time);
}

int main(int argc, char* argv[]){
    train_delay(atoi(argv[1]));
    return 0;
}