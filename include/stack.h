#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int* items;
    int top;
    int capacity;
} stack_t;

// Constructor / Destructor
stack_t* stack_create(int capacity);
void stack_free(stack_t* stack);

// Core stack operations
void stack_push(stack_t* stack, int value);
int stack_pop(stack_t* stack);
int stack_peek(stack_t* stack);
void stack_shrink(stack_t* stack);

int stack_is_empty(stack_t* stack);
int stack_is_full(stack_t* stack);
int stack_size(stack_t* stack);
int stack_capacity(stack_t* stack);
void stack_print(stack_t* stack);

// Some optional operations I made
stack_t* stack_create_from_array(int* arr, int length);

#endif