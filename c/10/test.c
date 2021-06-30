#include <stdio.h>
#include <string.h>

void trim_start(char *str){
    int space_count = 0;
    int i = 0;
    while(str[i++]==' '){
        space_count++;

    }
    for(int j=0;j<strlen(str) - space_count;j++){
        str[j]=str[j+space_count];
    }
}

void trim_end(char *str){
    int i = strlen(str)-1;
    for(;i>0 && str[i]==' '; i--){}
    str[i+1]='\0';
}

void trim(char *str){
    trim_start(str);
    trim_end(str);
}

int main() {
    char str[] = "   test   ";
    trim(str);
    printf("%s\n", str);
    return 0;
}