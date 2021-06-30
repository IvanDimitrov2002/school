#include <stdio.h>

int most_common_letter(char word[100]){
    int array[255] = {0}, index_of_letter=0, most_common_letter=array[0],i;
    for(i=0;word[i]!='\0';i++){
        ++array[(int)word[i]];
    }
    for(i=0;word[i]!='\0';i++){
        if(array[(int)word[i]]>most_common_letter){
            most_common_letter=array[(int)word[i]];
            index_of_letter=i;
        }
    }
    return word[index_of_letter];
}

int main(){
    printf("%c\n", most_common_letter("aaasssdddd"));
    return 0;
}
