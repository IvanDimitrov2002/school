#include <stdio.h>
#include <string.h>

float ascii_sum(char stop_word[50]){
    char words[256], temp_word[128];
    while(1){
        scanf("%s", temp_word);
        if(strcmp(temp_word, stop_word)!=0) strcat(words, temp_word);
        else break;
    }
    int ascii_sum=words[0],i;
    for(i=1;words[i]!='\0';i++){
        ascii_sum+=words[i];
    }
   return (float) ascii_sum/i;
}

int main(){
    printf("%.2f\n", ascii_sum("stop"));
    return 0;
}
