#include <stdio.h>

struct Stack {
    int* items;
    int top;
    int capacity;
}

struct Stack* createStack(int capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->items = malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(struct Stack* stack, int value)
{
    if(stack-> top == stack->capacity-1) {
        printf("Stack is full. Value cannot be pushed.");
    }
    else
    {
        stack->top++;
        stack->items[stack->top] = value
    }
}

int pop(struct Stack* stack)
{
    if(stack->top == -1) {
        printf("Stack is empty, cannot pop.\n");
        return -1;
    }

    int val = stack->items[stack->top];
    stack->top--;
    return val;    
}