#include <stdio.h>
#include <string.h>

void longest_words(){
    int current_size=0, max_size=0, number_of_words=0, is_valid=1;
    char text[200];
    fgets(text, 200, stdin);
    int text_size = strlen(text);
    for(int i=0;i<text_size;i++){
        if(text[i]!=' ' && text[i+1]!='\0'){
            if(is_valid){
                if(!(text[i]>='a' && text[i]<='z') && !(text[i]>='A' && text[i]<='Z') && text[i]!='-' && text[i]!=39)
                    is_valid=0;
                current_size++;
            }
        }
        else{
            if(is_valid){
                if(current_size==max_size){
                    number_of_words++;
                }
                else if(current_size>max_size){
                    max_size=current_size;
                    number_of_words=1;
                }
            }
            current_size=0;
        }
    }
    printf("Number of longest words: %d", number_of_words);
}

 int main(){
     longest_words();
     return 0;
 }
