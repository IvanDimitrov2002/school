#include <stdio.h>

int is_digit(char digit){
    if('0'<=digit && digit<='9'){
        return 1;
    }
    return 0;
}

int to_digit(char digit){
    if(is_digit(digit)){
        return digit-'0';
    }
    return -1;
}

int contains(unsigned long number, char digit){
    if(is_digit(digit)){
        digit-='0';
        while(number!=0){
            if(number%10==digit)
                return 1;
            number/=10;
        }
    }
    return 0;
}

int main(){
    printf("%d\n", is_digit('2')); //valid value
    printf("%d\n", is_digit('a')); //invalid value
    printf("%d\n", to_digit('2')); //valid value
    printf("%d\n", to_digit('a')); //invalid value
    printf("%d\n", contains(123, '1')); //valid value
    printf("%d\n", contains(122342343, '9')); //invalid value връща 0 и също ако не се среща цифрата в числото!
    return 0;
}