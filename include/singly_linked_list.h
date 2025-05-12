#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct singly_linked_list {
    Node* head;
    Node* tail;
    int size;
} singly_linked_list;

singly_linked_list* create_list();
void destroy_list(singly_linked_list* list);

bool is_empty(singly_linked_list* list);
int length(singly_linked_list* list);

void insert_front(singly_linked_list* list, int data);
void insert_back(singly_linked_list* list, int data);
bool insert_at(singly_linked_list* list, int index, int data);

bool delete_front(singly_linked_list* list);
bool delete_back(singly_linked_list* list);
bool delete_at(singly_linked_list* list, int index);

int get_at(singly_linked_list* list, int index, bool* success);
bool update_at(singly_linked_list* list, int index, int new_data);
int search(singly_linked_list* list, int target);

void display_list(singly_linked_list* list);
void reverse_list(singly_linked_list* list);

#endif