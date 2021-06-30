#include <stdio.h>
#include <stdlib.h>

void largest_combination(int size, int matrix[size][size]){
    int i, j, x, y, direction, max_direction;
    unsigned int sum, max=0;
    for(j=0;j<size;j++){
        for(i=0;i<size;i++){
            sum=0;
            if(i<size-3){
                sum = matrix[i][j] * matrix[i+1][j] * matrix[i+2][j] * matrix[i+3][j]; // to right
                direction = 0;
            }
            if(j<size-3){
                if(sum < matrix[i][j] * matrix[i][j+1] * matrix[i][j+2] * matrix[i][j+3]){ // to down
                    sum = matrix[i][j] * matrix[i][j+1] * matrix[i][j+2] * matrix[i][j+3];
                    direction = 1;
                }
            }
            if(i<size-3 && j<size-3){
                if(sum < matrix[i][j] * matrix[i+1][j+1] * matrix[i+2][j+2] * matrix[i+3][j+3]){ // to right_down_diagonal
                    sum = matrix[i][j] * matrix[i+1][j+1] * matrix[i+2][j+2] * matrix[i+3][j+3];
                    direction = 2;
                }
            }
            if(i>size-12 && j<size-3){
                if(sum < matrix[i][j] * matrix[i-1][j+1] * matrix[i-2][j+2] * matrix[i-3][j+3]){ // to left_down_diagonal
                    sum = matrix[i][j] * matrix[i-1][j+1] * matrix[i-2][j+2] * matrix[i-3][j+3];
                    direction = 2;
                }
            }
            if(max<sum){
                max=sum;
                x=i;
                y=j;
                max_direction=direction;
            }             
        }
    }
    printf("%d ", max);
    printf("%d ", x);
    printf("%d ", y);
    switch (max_direction) {
        case 0: printf("%s", "horizontal"); break; //0 for horizontal
        case 1: printf("%s", "vertical"); break; //1 for vertical
        case 2: printf("%s", "diagonal"); break; //2 for diagonal
    }
}

int main(int argc, char *argv[]){
    int size = atoi(argv[1]);
    int matrix[size][size];
    for(int j=0;j<size;j++){
        for(int i=0;i<size;i++){
            scanf("%d", &matrix[i][j]);
        }
    }
    largest_combination(size, matrix);
    return 0;
}