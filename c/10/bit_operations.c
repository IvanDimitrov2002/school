#include <stdio.h>

void print_bits(int n){
    if(n>0){;
        print_bits(n>>1);
        printf("%d", n%2);
    } else{
        printf("\n");
    }
}

int count_ones(int n){
    int res = 0;
    while(n>0){
        res+=n&1;
        n=n>>1;
    }
    return res;
}

int main() {
    int n=2;
    print_bits(n);
    printf("\n%d\n", count_ones(n));
    return 0;
}