#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tree_t {
    float height;
    int age;
};

struct forest_t {
    int tree_count;
    struct tree_t trees[10];
};

/*
    Добавя 1 към годините на дървото.
    Добавя височина взета произволно от 0.1 до 2.0.
    Връща модифицираната структура.
*/
struct forest_t age_trees(struct forest_t forest){
    for(int i=0;i<forest.tree_count;i++){
        forest.trees[i].age++;
        forest.trees[i].height+=((((float)rand()/(float)(RAND_MAX)) * 2.0) + 0.1);
    }
    return forest;
}

void print_tree(struct tree_t tree){
    printf("%.1f\n", tree.height);
    printf("%d\n", tree.age);
}

void print_forest(struct forest_t forest){
    for(int i=0;i<forest.tree_count;i++){
        print_tree(forest.trees[i]);
    }
}

// Връща модифицираната структура.
struct forest_t cut_old_trees(struct forest_t forest, int age_treshold){
    for(int i=0;i<forest.tree_count;i++){
        if(forest.trees[i].age>age_treshold){
            forest.trees[i].age=1;
            forest.trees[i].height=0.5;
            printf("A tree has been cut!\n");
        }
    }
    return forest; 
}

// Връща модифицираната структура.
struct forest_t cut_tall_trees(struct forest_t forest, float height_treshold){
    for(int i=0;i<forest.tree_count;i++){
        if(forest.trees[i].height>height_treshold){
            forest.trees[i].age=1;
            forest.trees[i].height=0.5;
            printf("A tree has been cut!\n");
        }
    }
    return forest;
}

/*
    Присвоява новата модифицирана структура на оригиналната.
    Принтира структурата "гора".
    Връща модифицираната структура.
*/
struct forest_t afforestation(struct forest_t forest, int age_treshold, float height_treshold){
    print_forest(forest);
    printf("-------------\nAfter:\n");
    forest=age_trees(forest);
    forest=cut_old_trees(forest, age_treshold);
    forest=cut_tall_trees(forest, height_treshold);
    print_forest(forest);
    printf("-------------\nBefore:\n");
    return forest;
}

/*
    Променя seed-a, който бива изполван от rand(),
    за да не бъде едно и също числото, което rand() ще върне.
    "Засажда" новите дървета с години и височина равни на 0, прави се само веднъж.
*/
int main(int argc, char* argv[]){
    srand(time(NULL));
    struct forest_t forest;
    forest.tree_count = 2;     // Брой дървета
    for(int i=0;i<forest.tree_count;i++){   // 
        forest.trees[i].age=0;
        forest.trees[i].height=0;
    }
    int number_of_loops = atoi(argv[1]);    // Превръща char в integer.
    int age_treshold = atoi(argv[2]);       // Превръща char в integer.
    float height_treshold = atof(argv[3]);  // Превръща char във float. 
    for(int i=0;i<number_of_loops;i++){
        forest=afforestation(forest, age_treshold, height_treshold);
    }
    return 0;
}