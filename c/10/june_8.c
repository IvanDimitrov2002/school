#include <stdio.h>
#include <stdlib.h>

struct arr_t{
    int *val;
    unsigned int size;
    unsigned int count;
};

struct arr_t create(){
    struct arr_t arr;
    arr.val = NULL;
    arr.size = 0;
    arr.count = 0;
    return arr;
}

int is_full(struct arr_t arr){
    return arr.size <= arr.count;
}

void add(struct arr_t *arr, int val){
    if(!is_full(*arr)){
        arr->val = (int*)realloc(arr->val, sizeof(int) * ++arr->count);
        arr->size++;
        arr->val[arr->count - 1] = val;
    }
}

int main(){
    struct arr_t arr = create();
    printf("%d\n", is_full(arr));
    for(int i=0;i<10;i++){
        add(&arr, i);
    }
    for(int i=0;i<10;i++){
        printf("element %d : %d\n", i, arr.val[i]);
    }
    return 0;
}