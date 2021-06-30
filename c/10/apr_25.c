#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t {
    int value;
    char key[255];
};

struct array_map_t {
    struct node_t *nodes;
    int size;
};

void give_list(struct array_map_t *map){
    map->size=0;
    map->nodes = (struct node_t*)malloc(0);
}

int node_exists(struct array_map_t *map, char *key){
    for(int i=0; i<map->size;i++){
        if(strcmp(map->nodes[i].key, key)==0){
            return 1;
        }
    }
    return -1;
}

void put(struct array_map_t *map, char *key, int value){
    int index = node_exists(map, key);
    if(index == -1){
        map->nodes = (struct node_t*)realloc(map->nodes, sizeof(struct node_t) * (map->size+1));
        index = map->size++;
    }
    map->nodes[index].value = value;
    strcpy(map->nodes[index].key, key);
}

int main(){
    struct array_map_t map;
    give_list(&map);
    put(&map, "asdasd", 1234);
    printf("%d %s\n", map.size, map.nodes[0].key);
    return 0;
}