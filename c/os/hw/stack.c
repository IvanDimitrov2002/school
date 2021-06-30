#include <stdio.h>

typedef struct
{
    size_t size;
    size_t capacity;
    int *elements;
} stack;

void stack_init( stack *stack){
    stack->size = 0;
    stack->capacity = 0;
    stack->elements = NULL;
}

void stack_destroy( stack *stack){
    free(stack->elements);
}

int stack_empty( stack *stack){
    if(stack->size <= 0){
        return 1;
    }
    return 0;
}

void stack_push( stack *stack, int new_element){
    stack->elements = (int*)realloc(stack->elements, (sizeof(int)*(++stack->size)));
    stack->elements[stack->size-1]=new_element;
}

int stack_top( stack *stack){
    return stack->elements[stack->size-1];
}

void stack_pop( stack *stack){
  stack->elements = (int*)realloc(stack->elements, (sizeof(int)*(--stack->size)));
}