#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int* items;
    int top;
    int capacity;
}