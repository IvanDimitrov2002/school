#include <stdio.h>

int string_compare(char *str1, char *str2){
    for(int i=0;str1[i]!='\0';i++){
        if(str1[i]>str2[i]){
            return 1;
        }
        else if(str1[i]<str2[i]){
            return -1;
        }
    }
    return 0;
}

int main(){
    char str1[] = "asc";
    char str2[] = "asd";
    printf("%d\n", string_compare(str1,str2));
    return 0;
}
