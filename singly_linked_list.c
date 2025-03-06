#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node **head, int data)
{
    // Make node
    Node *newNode = createNode(data);
    if (newNode == NULL)
    {
        printf("Memory allocation failed, cannot insert node");
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, int data)
{
    // Make node
    Node *newNode = createNode(data);
    if (newNode == NULL)
    {
        printf("Memory allocation failed, cannot insert node");
        return;
    }
    // Check if list is empty
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        // Traverse to last node
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL) // Traverse until temp node is NULL
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteNode(Node **head, int key)
{
    // Check if list is empty
    if (*head == NULL)
    {
        printf("List is empty, cannot delete %d.\n", key);
        return;
    }

    // If the node itself holds the key, move the head to the next node and free the old head node
    Node *temp = *head;
    Node *prev = NULL;
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for node to delete
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // Key not found
    if (temp == NULL)
    {
        printf("Node with value %d not found.\n", key);
        return;
    }

    // Unlink node and free memory
    prev->next = temp->next; // Remove node from list
    free(temp);              // Free memory
}

void reverseList(Node **head)
{
    Node *prev = NULL;
    Node *current = *head;
    Node *next = current->next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main()
{
    return 0;
}