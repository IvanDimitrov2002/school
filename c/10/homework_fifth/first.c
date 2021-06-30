#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int number, temp_number, digit_sum, is_prime;
    for(number=2;number<atoi(argv[1]);number++){
        is_prime=1;
        digit_sum=0;
        temp_number=number;
        while(temp_number!=0){
            digit_sum+=temp_number%10;
            temp_number/=10;
        }
        if(digit_sum==1){
            is_prime=0;
        }
        for(int i=2;i<=digit_sum/2;i++){
            if(digit_sum%i==0){
                is_prime=0;
                break;
            }
        }
        if(is_prime){
            printf("%d\n", number);
        }
    }
    return 0;
}