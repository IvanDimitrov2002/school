#include <stdio.h>
#include <stdlib.h>

// POINT_COUNT = 10;

// struct point_t {
//     float x;
//     float y;
//     char c;
// };

struct vector_t {
    int count;
    int *items;    
};

void init(struct vector_t *vec){
    printf("Init vector\n");
    vec->count=0;
    vec->items = (int*)malloc(sizeof(int));
}

void resize(struct vector_t *vec, int new_size){
    printf("Resize vector\n");
    vec->items = (int*)realloc(vec->items, new_size * sizeof(int));
}

void push(struct vector_t *vec, int item){
    printf("Push item %d\n", item);
    resize(vec, vec->count + 1);
    vec->items[vec->count++] = item;
}

int pop(struct vector_t *vec, int *item){
    if(vec->count <= 0) {
        return 0;
    }
    *item = vec->items[--vec->count];
    resize(vec , vec->count);
    return 1;
}

int main(){
    // struct point_t *my_point = (struct point_t*) malloc(sizeof(struct point_t) * POINT_COUNT);
    // printf("%d\n", sizeof(struct point_t));
    // printf("(%f,%f)\n", my_point->x, my_point->y);
    // for(int i = 0; i<POINT_COUNT;i++){
    //     printf("(%f,%f)\n", my_point[i].x, my_point[i].y);
    //     printf("(%f,%f)\n", (my_point+i)->x, (my_point+i)->y);
    // }
    struct vector_t my_vec;
    init(&my_vec);
    push(&my_vec,17);
    push(&my_vec,18);
    push(&my_vec,19);

    int res;

    for(int i=0;i<3;i++){
        if(pop(&my_vec, &res)){
            printf("Popped %d\n", res);
        }
        else{
            printf("Out of items\n\n");
        }   
    }
    

    // printf("Popped %d", pop(&my_vec));
    // printf("Popped %d", pop(&my_vec));
    // printf("Popped %d", pop(&my_vec));
    // printf("Popped %d", pop(&my_vec));
    
    return 0;
}