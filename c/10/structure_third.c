#include <stdio.h>

struct point_t{
    int x;
    int y;
};

struct circle_t {
    float r;    
};


float find_perimeter(struct circle_t circle){
    return 2*3.14*circle.r;
}

float find_surface(struct circle_t circle){
    return 3.14*(circle.r)*(circle.r);
}

// int find_quadrant(struct circle_t circle){
//     struct point_t center;
//     if(center.x - circle.r > 0 && center.y>0){
//         return 
//     }
// }


int main(){
    struct circle_t circle;
    circle.r = 5;
    printf("%.2f\n", find_perimeter(circle)); 
    printf("%.2f\n", find_surface(circle)); 
    return 0;
}