#include <stdio.h>

struct firework_t {
    float price;
    int powder;
    int is_colored;
};

float get_value(struct firework_t f){
    return f.price / f.powder;
}

struct firework_t best_value_and_color(struct firework_t fw[10]){
    struct firework_t best = fw[0];
    for(int i=1;i<10;i++){
        if(fw[i].is_colored && get_value(best) > get_value(fw[i])){
            best=fw[i];
        }
    }
    return best;
}

int main(){
    struct firework_t fw[] = {
        {10,100,1},
        {10,50,1},
        {100,50,1},
        {10,100,1},
        {10,50,1},
        {100,50,1},
        {10,100,1},
        {10,50,1},
        {100,50,1},
        {10,100,1}
    };
    struct firework_t best = best_value_and_color(fw);
    printf("%.2f %d %d\n", best.price, best.powder, best.is_colored);
    return 0;
}