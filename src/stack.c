#include "stack.h"

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
        stack->items[stack->top] = value;
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

int peek(struct Stack* stack)
{
    if(stack->top == -1) {
        printf("Stack is empty, nothing to peek at.\n");
        return -1;
    }
    return stack->items[stack->top];
}

int isEmpty(struct Stack* stack)
{
    if(stack->top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack* stack)
{
    if(stack->top == stack->capacity-1)
        return 1;
    return 0;
}

void freeStack(struct Stack* stack)
{
    free(stack->items);
    free(stack);
}

void printStack(struct Stack* stack)
{
    for(int i = 0; i <= stack->top; i++)
        printf("%d ",stack->items[i]);
    printf("\n");
}

int getSize(struct Stack* stack)
{
    return stack->top+1;
}

int getCapacity(struct Stack* stack)
{
    return stack->capacity;
}