#include <stdio.h>
#include <string.h>

void init_arr(char arr[][11]){
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            arr[i][j]='.';
        }
        arr[i][j]='\0';
    }
}


void print_arr(char arr[][11]){
    for(int i=0;i<10;i++){
        puts(arr[i]);
    }
}

void draw_arr(char arr[][11], int x, int y, int s){
    init_arr(arr);
    for(int j=0;j<s;j++){
        for(int i=0;i<s;i++){
            arr[x-1+j][y-1+i]='O';
        }
    }
    print_arr(arr);
}


int main(int argc, char *argv[]){
    char arr[10][11];
    draw_arr(arr, 3, 3, 6);
    return 0;
}