
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
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

// Display linked list
void display(Node *head) {
    Node *temp = head;

    if (head == NULL) {
        printf("Empty List\n");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Reverse linked list
Node *reverse(Node *head) {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL) {

        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    return prev;
}

int main() {
    Node *head = NULL;

    int choice, value;

    do {
        printf("\n1 to insert node\n");
        printf("2 to exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        if (choice == 1) {
            printf("Enter value: ");

            if (scanf("%d", &value) != 1) {
                printf("Invalid input!\n");
                return 1;
            }

            head = insert(head, value);
        }
        else if (choice != 2) {
            printf("Invalid choice!\n");
        }

    } while (choice != 2);

    printf("\nOriginal Linked List: ");
    display(head);

    head = reverse(head);

    printf("Reversed Linked List: ");
    display(head);

    return 0;
}
