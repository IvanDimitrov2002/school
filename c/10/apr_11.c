#include <stdio.h>
#include <stdlib.h>

struct node_t {
    int value;
    struct node_t* next;
};

struct list_t {
    struct node_t* head; 
    unsigned int size;
};

struct list_t* init_list(){
    struct list_t* new_list = (struct list_t*)malloc(sizeof(struct list_t));
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

void insert(struct list_t* list, int val){
    struct node_t* new_node = (struct node_t*)malloc(sizeof(struct node_t));
    new_node->value = val;
    new_node->next = list->head;
    list->head = new_node;
}

void remove_first(struct list_t* list){
    struct node_t* tmp = list->head;
    list->head = list->head->next;
    free(tmp);
    list->size--;
}

int main(){
    struct list_t* list = init_list();
    for(int i=1;i<5;i++){
        insert(list,i);
    }
    for(struct node_t* node = list->head; node!=NULL; node = node->next){
        printf("%d\n", node->value);
    }
    remove_first(list);
    for(struct node_t* node = list->head; node!=NULL; node = node->next){
        printf("%d\n", node->value);
    }
    return 0;
}