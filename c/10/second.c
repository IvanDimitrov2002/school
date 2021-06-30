#include "stdio.h"

int return_element(int arr[10], int n){
    return arr[n];
}

void save_number(int arr[10], int n, int k){
    arr[n]=k;
}

int vowel_number(char arr[10]){
    int i,k=0;
    for(i=0;i<10;i++){
        switch(arr[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': {
                k++;
                break;
            }

        }
    }
    return k;
}

int is_divisor(int n, int k){
    return !n%k;
}

int is_divisor_all(int arr[10], int n){
     int i;
     for(i=0;i<10;i++){
         if(is_divisor(arr[i],n)){
             return 0;
         }
     }
     return 1;
}

float sum(float arr[10]){
    float k=0;
    int i;
    for(i=0;i<10;i++){
        k+=arr[i];
    }
    return k/i;
}

int is_smallest(int arr[10]){
    int min=arr[0],i;
    for(i=1;i<10;i++){
        if(min>arr[i]){
            min=arr[i];
        }
    }
    return min;
}

int arr_sort(int *arr, int n)
{
    int i,a,b;
    for (i=1;i<n;i++)
    {
        a=arr[i];
        for(b=i-1;b>=0;b--)
        {
            if (a<arr[b]){
                arr[b+1]=arr[b];
            }
            else break;
        }
        arr[b+1] = a;
    }
    return 0;
}

int are_smallest(int arr[10]){
    int i;
    arr_sort(arr,10);
    for(i=0;i<5;i++) printf("\n %d", arr[i]);
    return 0;

}

int find_number(int arr[10], int n){
    int i;
    for(i=0;i<10;i++){
        if(arr[i]==n){
            return i;
        }
    }
    return -1;
}

int char_to_int(char n){
    int i;
    return i=n-'0';
}

int mini_calc(int a, char n, int b){
    if(n=='+'){ a=a+b;}
    else if(n=='-'){ a=a-b;}
    else if(n=='*'){ a=a*b;}
    else if(n=='/'){ a=a/b;}
    return a;
}

int digit_in_number(int n, int k){
    int i;
    for(i=0;n!=0;n/=10){
        if(n%10==k){
            i++;
        } 
    }
    return i;
}

int main() {
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int arr2[] = {60,15,21,22,71,24,11,15,90,100};
    char char_arr[] = {'a','b','c','d','e','f','g'};
    float grades[] = {3.50,5.50,4.50,3.55,5.80,5.70,6.00,2.60,3.60,5.60};
    printf("\n %d", return_element(arr,1));
    printf("\n %d", vowel_number(char_arr));
    printf("\n %d", is_divisor(11,2));
    printf("\n %d", is_divisor_all(arr,2));
    printf("\n %.2f", sum(grades));
    printf("\n %d", is_smallest(arr));
    printf("\n %d", are_smallest(arr2));
    printf("\n %d", find_number(arr2,11));
    printf("\n %d", char_to_int('9'));
    printf("\n %d", mini_calc(2,'/',2));
    printf("\n %d", digit_in_number(5255,5));
	return 0;
}
