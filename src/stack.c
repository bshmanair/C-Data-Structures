#include "stack.h"

stack_t* stack_create(int capacity) {
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
    stack->items = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void stack_push(stack_t* stack, int value) {
    if (stack->top == stack->capacity - 1) {
        int new_capacity = stack->capacity * 2;
        int* new_items = realloc(stack->items, sizeof(int) * new_capacity);
        if (new_items == NULL) {
            printf("Memory reallocation failed.\n");
            return;
        }
        stack->items = new_items;
        stack->capacity = new_capacity;
    }

    stack->items[++(stack->top)] = value;
}


int stack_pop(stack_t* stack) {
    if (stack->top == -1) {
        printf("Stack is empty, cannot pop.\n");
        return -1;
    }
    return stack->items[(stack->top)--];
}

int stack_peek(stack_t* stack) {
    if (stack->top == -1) {
        printf("Stack is empty, nothing to peek at.\n");
        return -1;
    }
    return stack->items[stack->top];
}

int stack_is_empty(stack_t* stack) {
    return stack->top == -1;
}

int stack_is_full(stack_t* stack) {
    return stack->top == stack->capacity - 1;
}

void stack_free(stack_t* stack) {
    free(stack->items);
    free(stack);
}

void stack_print(stack_t* stack) {
    for (int i = 0; i <= stack->top; i++)
        printf("%d ", stack->items[i]);
    printf("\n");
}

int stack_size(stack_t* stack) {
    return stack->top + 1;
}

int stack_capacity(stack_t* stack) {
    return stack->capacity;
}

void stack_clear(stack_t* stack) {
    memset(stack->items,0,sizeof(int) * stack->capacity);
    free(stack->items);
}

stack_t* stack_create_from_array(int* arr, int length) {
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t)); 
    stack->capacity = length * 2;
    stack->items = (int*)malloc(sizeof(int)*stack->capacity);
    memcpy(stack->items,arr,length*sizeof(int));
    stack->top = length - 1;
    return stack;
}