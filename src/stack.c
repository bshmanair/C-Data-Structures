#include "stack.h"

stack_t* stack_create(int capacity) {
    if (capacity <= 0) return NULL;
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
    if (!stack) {
        printf("Memory allocation for stack failed.\n");
        return NULL;
    }
    stack->items = (int*)malloc(sizeof(int) * capacity);
    if(!stack->items) {
        printf("Memory allocation for stack's items failed.\n");
        free(stack);
        return NULL;
    }
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void stack_push(stack_t* stack, int value) {
    if (!stack) {
        printf("Stack is NULL, cannot push.\n");
        return;
    }
    if (stack_is_full(stack)) {
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
    if (!stack) {
        printf("Stack is NULL, cannot pop.\n");
        return -1;
    }
    if (stack->top == -1) {
        printf("Stack is empty, cannot pop.\n");
        return -1;
    }
    return stack->items[(stack->top)--];
}

int stack_peek(stack_t* stack) {
    if(!stack) {
        printf("Stack is NULL, cannot peek.\n");
        return -1;
    }
    if (stack->top == -1) {
        printf("Stack is empty, nothing to peek at.\n");
        return -1;
    }
    return stack->items[stack->top];
}

int stack_is_empty(stack_t* stack) {
    if(!stack) {
        printf("Stack is NULL, cannot check if empty.\n");
        return -1;
    }
    return stack->top == -1;
}

int stack_is_full(stack_t* stack) {
    if(!stack) {
        printf("Stack is NULL, cannot check if full.\n");
        return -1;
    }
    return stack->top == stack->capacity - 1;
}

void stack_free(stack_t* stack) {
    if(!stack) {
        printf("Stack is NULL, cannot free.\n");
        return;
    }
    free(stack->items);
    free(stack);
}

void stack_print(stack_t* stack) {
    if(!stack) {
        printf("Stack is NULL, cannot print.\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++)
        printf("%d ", stack->items[i]);
    printf("\n");
}

int stack_size(stack_t* stack) {
    if(!stack) {
        printf("Stack is NULL, cannot check size.\n");
        return -1;
    }
    return stack->top + 1;
}

int stack_capacity(stack_t* stack) {
    if(!stack) {
        printf("Stack is NULL, cannot check capacity.\n");
        return -1;
    }
    return stack->capacity;
}

void stack_clear(stack_t* stack) {
    if(!stack) {
        printf("Stack is NULL, cannot clear.\n");
        return;
    }
    stack->top = -1;
    memset(stack->items,0,sizeof(int) * stack->capacity);
}

stack_t* stack_create_from_array(int* arr, int length) {
    if (!arr) {
        printf("Array is NULL. Cannot create stack from array.\n");
        return NULL;
    }
    
    if(length <= 0)
    {
        printf("Length is 0. Cannot create stack from array.\n");
        return NULL;
    }
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t)); 
    if(!stack) {
        printf("Memory allocation failed.\n");
        return;
    }
    stack->capacity = length * 2;
    stack->items = (int*)malloc(sizeof(int)*stack->capacity);
    if(!stack->items) {
        printf("Memory allocation for items failed.\n");
        free(stack);
        return NULL;
    }
    memcpy(stack->items,arr,length*sizeof(int));
    stack->top = length - 1;
    return stack;
}

void stack_shrink(stack_t* stack) {
    if (!stack) {
        printf("Stack is NULL, cannot shrink.\n");
        return;
    }

    if(stack_is_full(stack)) {
        printf("Cannot be shrunk, stack is at full capacity.\n");
        return;
    }
    int new_capacity = stack->top + 1;
    int* new_items = (int*)realloc(stack->items,sizeof(int) * new_capacity);
    if (!new_items) {
        printf("Memory shrink failed, memory reallocation not possible.\n");
        return;
    }
    stack->items = new_items;
    stack->capacity = new_capacity;
}