#include <stdio.h>

int is_letter(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return 1;
    return 0;
}

int main () {
    char str[250];
    fgets(str, 250, stdin);
    int i, j, count, longest=0;
    for(i=0;str[i]!='\0';i++){
        count=0;
        if(str[i]>='A' && str[i]<='Z' && (i==0 || str[i-1]==' ')){
            for(j=i;is_letter(str[j]);j++)
                count++;
            i=j;
        }
        if(count>longest)
            longest=count;
    }
    printf("Longest: %d\n", longest);
    return 0;
}