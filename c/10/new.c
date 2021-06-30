#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    if(n==0 || n==1 || n==2){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

int main(int argc, char* argv[]) {
    int a;
    printf("%d\n", fib(atoi(argv[1])));
    // int n;
    // scanf("%d", &n);
    // printf("%d\n",fib(n));
    // printf ("%d\n", scanf ("%d", &a));
    // printf ("%d\n", a);
    printf ("%d\n", (scanf ("%d", &a)) != EOF);
    // while (scanf ("%d", &a) != EOF) {
    //     printf ("%d\n", a);
    // }
    return 0;
}