#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int size;
    int capacity;
} DynamicArray;

void initArray(DynamicArray *arr, int initialCapacity)
{
    arr->data = (int *)malloc(initialCapacity * sizeof(int));
    if (arr->data == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    arr->size = 0;
    arr->capacity = initialCapacity;
}

void append(DynamicArray *arr, int value)
{
    // If the array is full, reallocate memory
    if (arr->size == arr->capacity)
    {
        arr->data = (int *)realloc(arr->data, 2 * arr->capacity * sizeof(int));
        if (arr->data == NULL)
        {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
        arr->capacity *= 2;
    }

    arr->data[arr->size] = value; //stores value at current index
    arr->size++;                  //increments size
}

void removeAt(DynamicArray *arr, int index)
{
    if(index < 0 || index >= arr->size)
    {
        printf("Index out of bounds.\n");
        return;
    }

    for(int i = index; i < arr->size - 1; i++)
    {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

void destroyArray(DynamicArray *arr)
{
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

int main()
{
    DynamicArray arr;
    initArray(&arr, 5);

    for(int i = 1; i <= 8; i++)
    {
        append(&arr,i);
    }
    for(int i = 0; i < arr.size; i++)
    {
        printf("%d ", arr.data[i]);
    }

    destroyArray(&arr);
    return 0;
}
