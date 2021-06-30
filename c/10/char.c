#include "stdio.h"



int main() {
    char c;
    char str[15];
    int a;
    // c=getchar();
    // putchar(c);
    // putchar("\n");
    // printf("\n %c %d", c, c);
    fgets(str, 15, stdin);
    puts(str);
    // printf("%s\n", str);
    // scanf("%s", &str);
    // printf("\n %s", str);
    // while(scanf("%d", &a) != EOF){
    //     printf("%d\n",a);
    // }
    return 0;
}