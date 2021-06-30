#include <stdio.h>

void str_cat(char *str1, char *str2){
    int str1_len=0,str2_len=0;
    while(str1[str1_len]!='\0'){
        str1_len++;
    }
    while(str2[str2_len]!='\0'){
        str2_len++;
    }
    for(int k=0;k<str2_len;k++){
        str1[str1_len+k]=str2[k];
    }
} 

int main(){
    char str1[32] = "asdasd";
    char str2[32] = "qwertyuiop";
    str_cat(str1,str2);
    printf("%s\n", str1);
    return 0;
}

