#ifndef DYNAMIC_ARRAY_H // Include guard to prevent multiple inclusions
#define DYNAMIC_ARRAY_H // Defines the header file once if not already defined
#include <stdio.h>
#include <stdlib.h>
// Dynamic array's structure
typedef struct
{
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

// Function prototypes
DynamicArray *createArray(size_t initialCapacity);
void insertElement(DynamicArray *arr, int value);
void deleteArray(DynamicArray *arr);
void printArray(DynamicArray *arr);

#endif