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
} dynamic_array;

// Function prototypes
dynamic_array *createArray(size_t initialCapacity);
void insertElement(dynamic_array *arr, int value);
void deleteArray(dynamic_array *arr);
void printArray(dynamic_array *arr);

#endif