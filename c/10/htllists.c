#include <stdlib.h>
#include <stdio.h>

typedef struct node_t
{
    int value;
    struct node_t *next;
    struct node_t *prev;
} node_t;

typedef struct 
{
    unsigned int size;
    node_t *head;
    node_t *tail;

} list_t;

void init_list(list_t *list){
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void insert(list_t *list, int val){
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->value = val;
    new_node->next = list->head;
    if (list->head != NULL)
        list->head->prev = new_node;

    if (list->tail == NULL)
        list->tail = new_node;
    list->tail->next = list->head;
    new_node->prev = list->tail;
    list->head = new_node;

    list->size++;
}
//  H
// {'' '' ''}
int rem(list_t *list){
    if(list->size){
        node_t *temp = list->head;
        list->head = list->head->next;
        list->head->prev = list->tail;
        list->size--;
        free(temp);
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    list_t list;
    init_list(&list);
    insert(&list, 10); 
    insert(&list, 20);
    insert(&list, 30);
    insert(&list, 40);
    rem(&list);
    node_t *node = list.head;
    for (int i = 0; i < list.size; node = node->next,i++){
        printf("%d\n",node->value);
    }
    while (!rem(&list));
    free(list.tail->prev);
    free(list.tail);
    return 0;
}