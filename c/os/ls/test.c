#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int option;
    int A = 0, l = 0, R = 0;
    while((option = getopt(argc, argv, "lAR")) != -1){
        switch(option){
            case 'l':
                l = 1;
                break;

            case 'A':
                A = 1;
                break;

            case 'R':
                R = 1;
                break;
        }
    }
    printf("%d", optind);
    printf("%d", option);
}