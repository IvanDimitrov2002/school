#include <stdlib.h>
#include <string.h>

char *strdup( const char *string){
    char *str = malloc(sizeof(char)*strlen(string));
    strcpy(str,string);
    return str;
}