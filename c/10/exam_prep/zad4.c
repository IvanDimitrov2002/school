#include <stdio.h>
#include <stdlib.h>

int most_common_digit(int number){
    number=abs(number);
    int array[9]={0},i,most_common_digit=array[0],temp_number=number;
    for(i=0;temp_number!=0;i++){
        ++array[temp_number%10];
        temp_number/=10;
    }
    for(i=0;number!=0;i++){
        if(array[number%10]>array[most_common_digit]){
            most_common_digit=number%10;
        }
        number/=10;
    }
    return most_common_digit;
}

int main(){
    printf("%d\n", most_common_digit(111122222));
    return 0;
}
 
