#include <stdio.h>

struct drone_t{
    char model[100];
    int capacity;
    int curr_load;
};

void load_drones(struct drone_t *main, struct drone_t *backup, int load){
    if(main->capacity < main->curr_load + load){
        if(backup->capacity < backup->curr_load + main->curr_load + load - main->capacity){
            backup->curr_load = backup->capacity;
            printf("Cannot load\n");
        }
        else{
            backup->curr_load += main->curr_load + load - main->capacity;
        }
    }
    else{
        main->curr_load += load;
    }
}

int main(){
    
    // int i,curr_length=0,max_length=0;
    // char str[250];
    // fgets(str, 250, stdin);
    // for(i=0;str[i]!='\0';i++){
    //     if(str[i]>='A' && str[i]<='Z'){
    //         while((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')){
    //             curr_length++;
    //             i++; 
    //         }
    //         if(max_length<curr_length){
    //             max_length=curr_length;
    //         }
    //         curr_length=0;
    //     }
    // }
    // printf("%d\n", max_length);

    struct drone_t drones[6];

    for(int i=0;i<6;i++){
        drones[i].capacity = i*10;
        drones[i].curr_load = 0;
    }

    for(int i=0;i<5;i++){
        load_drones(&drones[i], &drones[i+1], (i+1)*12);
    }

    for(int i=0;i<6;i++){
        printf("Drone %d is loaded with %d(%d)\n", i, drones[i].curr_load, drones[i].capacity);
    }

    return 0;
}