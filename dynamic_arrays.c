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
    if(arr->size == arr->capacity)
    {
        arr->data = (int *)realloc(arr->data, 2 * arr->capacity * sizeof(int));
        if (arr->data == NULL)
        {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
        arr->capacity *= 2;
    }
}

int main()
{
    DynamicArray arr;
    initArray(&arr, 5);

    arr.size = 5;

    for (int i = 0; i < arr.size; i++)
    {
        arr.data[i] = i + 1;
    }
    for (int i = 0; i < arr.size; i++)
    {
        printf("%d ", arr.data[i]);
    }
    free(arr.data);
    return 0;
}
