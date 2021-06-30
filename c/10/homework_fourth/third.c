#include <stdio.h>

void count_numbers(int *arr, int *even, int *odd, int arr_length){
    for(int i=0;i<arr_length;i++){
        if(arr[i]%2==0){
            *even=*even+1;
        }
        else{
            *odd=*odd+1;
        }
    }
}

int main(){
    int even=0, odd=0;
    int arr[] = {1,2,3,4,5,6};
    int arr_length = sizeof(arr)/sizeof(int);
    count_numbers(arr, &even, &odd, arr_length);
    printf("even: %d, odd: %d\n", even, odd);
    return 0;
}