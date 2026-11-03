
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

void reverse(void) {
    node *current = head;
    node *temp;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node in the original list
        current = current->prev;
    }

    // Update the global head to the new first node
    if (temp != NULL) {
        head = temp->prev;
    }
}

void display(void) {
    node *current = head;

    if (current == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("List elements: ");

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    int choice, data;

    printf("1. Insert\n2. Reverse\n3. Display\n4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                if (scanf("%d", &data) != 1) {
                    printf("Invalid input!\n");
                    return 1;
                }
                insert(data);
                break;

            case 2:
                reverse();
                printf("List reversed!\n");
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
