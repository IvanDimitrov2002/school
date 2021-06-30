#include <stdio.h>
#include <stdlib.h>

struct node_t {
    int value;
    struct node_t* next;
    struct node_t* prev;
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
    if(list->head != NULL)
        list->head->prev = new_node;
    list->head = new_node;
    list->size++;
}

void insert_after(struct list_t* list, int position, int val){
    struct node_t* new_node = (struct node_t*)malloc(sizeof(struct node_t));
    new_node->value = val;
    new_node->next = list->head;
    if(list->head != NULL)
        list->head->prev = new_node;
    list->head = new_node->next;
    for(int i=0;i<=position && new_node->next != NULL;i++){
        new_node->next->prev = new_node->prev;
        new_node->prev = new_node->next;
        if(new_node->next->next != NULL)
            new_node->next->next->prev = new_node;
        new_node->next = new_node->next->next;
        new_node->prev->next = new_node;
        if(new_node->prev->prev !=NULL)
            new_node->prev->prev->next = new_node->prev;
    }
    list->size++;
}

void remove_first(struct list_t* list){
    struct node_t* tmp = list->head;
    list->head = list->head->next;
    if(tmp->next != NULL)
        tmp->next->prev = NULL;
    free(tmp);
    list->size--;
}



int main(){
    struct list_t* list = init_list();
    for(int i=1;i<5;i++){
        insert(list,i);
    }
    insert_after(list, 0, 14);
    for(struct node_t* node = list->head; node!=NULL; node = node->next){
        printf("%d\n", node->value);
    }
    // while(list->head !=NULL)
    //     remove_first(list);
    // free(list);
    return 0;
}