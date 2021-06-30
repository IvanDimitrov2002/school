#include <stdio.h>
#include <string.h>

int str_in_str(char *str1, char *str2){
    if(strstr(str1,str2)!=NULL){
        return 1;
    }
    return 0;
}

int main(){
    char str1[] = "heeello";
    char str2[] = "heeel";
    printf("%d\n", str_in_str(str1, str2));
    return 0;
}