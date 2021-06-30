#include <stdio.h>

int check_vovels(char *str, int str_length){
    int number_of_vovels=0;
    for(int i=0;i<str_length;i++){
        switch (*(str + i))
        {
            case 'a': number_of_vovels++; break;
            case 'o': number_of_vovels++; break;
            case 'u': number_of_vovels++; break;
            case 'e': number_of_vovels++; break;
            case 'i': number_of_vovels++; break;
            case 'A': number_of_vovels++; break;
            case 'O': number_of_vovels++; break;
            case 'U': number_of_vovels++; break;
            case 'E': number_of_vovels++; break;
            case 'I': number_of_vovels++; break;
        }
    }
    return number_of_vovels;
}

int main(){
    char str[] = "heeello";
    int str_length = sizeof(str)/sizeof(char) - 1;
    printf("%d\n", check_vovels(str, str_length));
    return 0;
}