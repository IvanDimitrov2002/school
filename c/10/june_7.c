#include <stdio.h>

struct arr_t{
    int val[10];
    unsigned int size;
    unsigned int count;
};

struct arr_t create(){
    struct arr_t arr;
    arr.size = 10;
    arr.count = 0;
    return arr;
}

int is_full(struct arr_t arr){
    return arr.size <= arr.count;
}

void add(struct arr_t *arr, int val){
    if(!is_full(*arr))
        arr->val[arr->count++] = val;
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