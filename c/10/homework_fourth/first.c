#include <stdio.h>

void arr_sort(int *arr, int arr_length){
    int temporary;
    for(int j=0;j<arr_length-1;j++){
        for(int i=0;i<arr_length-j-1;i++){
            if(*(arr + i)>*(arr + i+1)){
                temporary = *(arr + i);
                *(arr + i)=*(arr + i + 1);
                *(arr + i + 1)=temporary;
            }
        }
    }
}

int main(){
    int arr[] = {111,12,2,5,1,3,4,6};
    int arr_length = sizeof(arr)/sizeof(int);
    arr_sort(arr, arr_length);
    for(int i=0;i<arr_length;i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}