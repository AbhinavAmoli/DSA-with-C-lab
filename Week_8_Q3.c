#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} node;

node *head = NULL;

void insert(int value) {
    node *newnode = (node*)malloc(sizeof(node));

    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    node *current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newnode;
    newnode->prev = current;
}
//Given a sorted linked list 
void removeduplicates(){
    if (head == NULL) {
        return;
    }

    node *current = head;

    while (current->next != NULL) {
        if (current->data == current->next->data) {
            node *temp = current->next;
            current->next = current->next->next;
            if (current->next != NULL) {
                current->next->prev = current;
            }
            free(temp);
        } else {
            current = current->next;
        }
    }
}

int main() {
    insert(1);
    insert(2);
    insert(2);
    insert(3);
    insert(4);
    insert(4);
    insert(5);

    printf("Original list: ");
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    removeduplicates();

    printf("List after removing duplicates: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}