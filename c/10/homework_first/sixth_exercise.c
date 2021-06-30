#include <stdio.h>
#include <string.h>

int sum=0;

int to_integer(char *str){
    int temporary_sum=0;
    for(int i=0;i<strlen(str);i++)
    {
        temporary_sum=temporary_sum*10 + (str[i]-'0');
    }
    sum+=temporary_sum;
    return 0;
}

int main(int argc, char* argv[]){
    for(int i=1;i<argc;i++){
       to_integer(argv[i]);
    }
    printf("%d\n", sum);
    return 0;
}
