#include <stdio.h>
#include <stdlib.h>

struct vector_t {
    int count;
    int *items;
};

void init(struct vector_t *vector){
    vector->count=0;
    vector->items = NULL;
}

void push(struct vector_t *vector, int new_item){
    vector->items = (int*)realloc(vector->items, sizeof(int)*(++vector->count));
    vector->items[vector->count - 1] = new_item;
}

void destroy_vector(struct vector_t *vector){
    free(vector->items);
}


// void split(int n){
//     int numbers[255],i;
//     for(i=0;n>0;i++){
//         numbers[i]=n%10;
//         n/=10;
//     }
//     i-=1;
//     while(1){
//         printf("%d", numbers[i]);
//         if(i<=0) break;
//         printf(",");
//         i--;
//     }
//     printf("\n");
// }

int split(int n){
    if(n==0) return 0;
    printf("%d", n%10);
    printf(",");
    return split(n/10);
}

int main(int argc, char* argv[]){
    int numbers = atoi(argv[1]);
    int number;
    struct vector_t array_numbers;
    init(&array_numbers);
    for(int i=0;i<numbers;i++){
        printf("Number: ");
        scanf("%d", &number);
        push(&array_numbers, number);
    }
    for(int i=0;i<numbers;i++){
        split(array_numbers.items[i]);
    }
    destroy_vector(&array_numbers);
    return 0;
}