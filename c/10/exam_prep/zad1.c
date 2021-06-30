#include <stdio.h>

float even_sum(int number){
    int sum=0,k=0;
    while(number!=0){
        if((number%10)%2==0){
            sum+=number%10;
            k++;
        } 
        number/=10;
    }
    return sum/k;
}

int main(){
    printf("%.2f\n", even_sum(123456));
    return 0;
}