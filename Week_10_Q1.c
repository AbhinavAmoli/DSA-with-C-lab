
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

// Add an existing node to the end of a list
void appendNode(Node **head, Node **tail, Node *newNode) {
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    }
    else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

// Split nodes into odd and even positions
void splitList(Node *head, Node **odd, Node **even) {
    Node *oddTail = NULL;
    Node *evenTail = NULL;
    Node *temp, *nextNode;

    int position = 1;

    *odd = NULL;
    *even = NULL;

    temp = head;

    while (temp != NULL) {

        nextNode = temp->next;
        temp->next = NULL;

        if (position % 2 != 0) {
            appendNode(odd, &oddTail, temp);
        }
        else {
            appendNode(even, &evenTail, temp);
        }

        temp = nextNode;
        position++;
    }
}

int main() {
    Node *head = NULL;
    Node *odd = NULL;
    Node *even = NULL;

    int choice, value;

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

    printf("\nOriginal Linked List: ");
    display(head);

    splitList(head, &odd, &even);

    printf("Odd numbered nodes list: ");
    display(odd);

    printf("Even numbered nodes list: ");
    display(even);

    return 0;
}
