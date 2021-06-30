#include <stdio.h>
#include <string.h>

int is_fingerprint_row_valid(char fingerprint[20]){
    if(strlen(fingerprint)!=16){
        return 0;
    }
    for(int i=0;i<16;i++){
        if(fingerprint[i]!='\\' && fingerprint[i]!='/' && fingerprint[i]!='~' && fingerprint[i]!='|' && fingerprint[i]!='-' && fingerprint[i]!='_'){
            return 0;
        }
    }
    return 1;
} 

int main(int argc, char* argv[]){
    int i;
    for(i=1;i<argc;i++){
        if(!is_fingerprint_row_valid(argv[i])){
            printf("The row is invalid!\n");
        }
        else{
            printf("The row is valid!\n");
        }
    }
    return 0;
}

//когато се въвежда символът \ в терминала на мен не ми го приема като аргумент (сигурно има специално значение в linux).
//Затова когато въвждам аргументите като ./a.out '~-~-~-~' '-~-~-~\//' , т.е. с ' ' се получава
