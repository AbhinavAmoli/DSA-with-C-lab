
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Insert node at the end
Node *insert(Node *head, int value) {
    Node *newNode, *temp;

    newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }

    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Display circular linked list
void display(Node *head) {
    Node *temp;

    if (head == NULL) {
        printf("Empty List\n");
        return;
    }

    temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

// Split circular linked list
void splitList(Node *head, int k,
               Node **first, Node **second) {

    Node *temp, *last;
    int count = 1;

    *first = head;
    *second = NULL;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    // Count nodes and find last node
    while (temp->next != head) {
        count++;
        temp = temp->next;
    }

    last = temp;

    // Check valid position
    if (k < 1 || k > count) {
        printf("Invalid position!\n");
        return;
    }

    // If k is the last node
    if (k == count) {
        return;
    }

    temp = head;

    // Reach kth node
    for (int i = 1; i < k; i++) {
        temp = temp->next;
    }

    // Starting point of second list
    *second = temp->next;

    // Make first list circular
    temp->next = *first;

    // Make second list circular
    last->next = *second;
}

int main() {
    Node *head = NULL;
    Node *first = NULL;
    Node *second = NULL;

    int choice, value, k;

    while (1) {
        printf("\n1 to insert node\n");
        printf("2 to exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);

            head = insert(head, value);
        }
        else if (choice == 2) {
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    printf("\nEnter position k: ");
    scanf("%d", &k);

    printf("\nOriginal List: ");
    display(head);

    splitList(head, k, &first, &second);

    printf("First part of list: ");
    display(first);

    printf("Second part of list: ");
    display(second);

    return 0;
}
