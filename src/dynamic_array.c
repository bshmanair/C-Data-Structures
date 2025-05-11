#include "dynamic_array.h"

// Create array
dynamic_array *create_array(size_t initialCapacity)
{
    // create new array and allocate size of dynamic array
    dynamic_array *arr = (dynamic_array *)malloc(sizeof(dynamic_array));
    // data is the array, so allocate initial capacity to it
    arr->data = (int *)malloc(initialCapacity * sizeof(int));
    if (!arr || !arr->data) 
    {
        free(arr);
        return NULL;
    }
    // initial size of array is 0
    arr->size = 0;
    // initial capacity is inputted by user
    arr->capacity = initialCapacity;
    return arr;
}

void insertElement(dynamic_array *arr, int value)
{
    if (arr->size + 1 == arr->capacity)
    {
        arr->capacity *= 2;
        arr = (dynamic_array *)realloc(arr, arr->capacity);
    }
}