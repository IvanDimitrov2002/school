#include <stdio.h>
#include <string.h>

void morse_converter(char *str){
    for(int i=0;i<strlen(str);i++){
        switch(str[i]){
            case 'a':
            case 'A':
                printf(".- ");
                break;
            case 'b':
            case 'B':
                printf("-... ");
                break;
            case 'c':
            case 'C':
                printf("-.-. ");
                break;
            case 'd':
            case 'D':
                printf("-.. ");
                break;
            case 'e':
            case 'E':
                printf(". ");
                break;
            case 'f':
            case 'F':
                printf("..-. ");
                break;
            case 'g':
            case 'G':
                printf("--. ");
                break;
            case 'h':
            case 'H':
                printf(".... ");
                break;
            case 'i':
            case 'I':
                printf(".. ");
                break;
            case 'j':
            case 'J':
                printf(".--- ");
                break;
            case 'k':
            case 'K':
                printf("-.- ");
                break;
            case 'l':
            case 'L':
                printf(".-.. ");
                break;
            case 'm':
            case 'M':
                printf("-- ");
                break;
            case 'n':
            case 'N':
                printf("-. ");
                break;
            case 'o':
            case 'O':
                printf("--- ");
                break;
            case 'p':
            case 'P':
                printf(".--. ");
                break;
            case 'q':
            case 'Q':
                printf("--.- ");
                break;
            case 'r':
            case 'R':
                printf(".-. ");
                break;
            case 's':
            case 'S':
                printf("... ");
                break;
            case 't':
            case 'T':
                printf("- ");
                break;
            case 'u':
            case 'U':
                printf("..- ");
                break;
            case 'v':
            case 'V':
                printf("...- ");
                break;
            case 'w':
            case 'W':
                printf(".-- ");
                break;
            case 'x':
            case 'X':
                printf("-..- ");
                break;
            case 'y':
            case 'Y':
                printf("-.-- ");
                break;
            case 'z':
            case 'Z':
                printf("--.. ");
                break;
        }
    }
}

int main(int argc, char* argv[]){
    for(int i=1;i<argc;i++){
        morse_converter(argv[i]);
        if(i!=argc-1){
            printf("/ ");
        }
    }
    return 0;
}
