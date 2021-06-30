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

int pop(struct vector_t *vector, int *popped_item){
    if(vector->count <= 0){
        return 0;
    }
    *popped_item = vector->items[--vector->count];
    vector->items = (int*)realloc(vector->items, sizeof(int)*(vector->count));
    return 1;
}

void destroy_vector(struct vector_t *vector){
    free(vector->items);
}

int main(){
    struct vector_t vector;
    init(&vector);
    push(&vector, 15);
    push(&vector, 645);
    push(&vector, -1);
    int vector_length = vector.count;
    int popped_item;
    for(int i=0;i<vector_length && pop(&vector, &popped_item);i++){
        printf("Popped: %d\n", popped_item);
    }
    destroy_vector(&vector);
    return 0;
}