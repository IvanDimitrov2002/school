#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // int *int_arr = (int*) malloc(sizeof(int)*10);
    // for(int i=0;i<10;i++){
    //     int_arr[i]=i+1;
    // }
    // for(int i=0;i<10;i++){
    //     printf("%d\n", int_arr[i]);
    // }
    // printf("%d\n", int_arr[0]);
    // free(int_arr);

    // int *p = (int*) malloc(sizeof(int));
    // memset(p,0,4);
    // printf("%d\n", *p);
    // free(p);

    int i,number_elements;
    scanf("%d", &number_elements);
    char *arr = (char*) malloc(sizeof(char)*(number_elements+1));
    for(i=0; i<number_elements;i++){
        getchar();
        arr[i]=getchar();
    }
    for(;i>=0;i--){
        printf("%c\n", arr[i]);
    }
    free(arr);

    return 0;
}