#include <stdio.h>
#include <stdlib.h>

struct stack_t {
    int count;
    int *items;
};

void init(struct stack_t *stack){
    stack->count=0;
    stack->items = NULL;
}

void push(struct stack_t *stack, int new_item){
    stack->items = (int*)realloc(stack->items, sizeof(int)*(++stack->count));
    stack->items[stack->count - 1] = new_item;
}

int pop(struct stack_t *stack, int *popped_item){
    if(stack->count <= 0){
        return 0;
    }
    *popped_item = stack->items[--stack->count];
    stack->items = (int*)realloc(stack->items, sizeof(int)*(stack->count));
    return 1;
}

void destroy_stack(struct stack_t *stack){
    free(stack->items);
}

int main(){
    struct stack_t stack;
    init(&stack);
    push(&stack, 15);
    push(&stack, 645);
    push(&stack, -1);
    int stack_length = stack.count;
    int popped_item;
    for(int i=0;i<stack_length && pop(&stack, &popped_item);i++){
        printf("Popped: %d\n", popped_item);
    }
    destroy_stack(&stack);
    return 0;
}