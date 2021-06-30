#include <stdio.h>

struct point_t {
    float x;
    float y;
};

int are_aligned(struct point_t point1, struct point_t point2, struct point_t point3){
    if((point1.x*(point2.y-point3.y) + point2.x*(point3.y-point1.y) + point3.x*(point1.y-point2.y)) == 0){
        return 1;
    }
    return 0;
}

struct point_t new_point(struct point_t point1, struct point_t point2){
    struct point_t point3;
    
    point3.x = point1.x + point2.x;
    point3.y = point1.y + point2.y;
    return point3;
}

int main() {
    struct point_t point1 = {1,1}, point2 = {2,2}, point3 = {3,3};
    printf("%d\n", are_aligned(point1,point2,point3));
    printf("%.2f %.2f\n" , new_point(point1,point2).x , new_point(point1,point2).y);
    return 0;
}