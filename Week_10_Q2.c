
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

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Find nth node from the end
int findNthFromEnd(Node *head, int n, int *answer) {
    Node *first = head;
    Node *second = head;

    if (n <= 0)
        return 0;

    // Move first pointer n positions ahead
    for (int i = 0; i < n; i++) {
        if (first == NULL)
            return 0;

        first = first->next;
    }

    // Move both pointers together
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    *answer = second->data;

    return 1;
}

int main() {
    Node *head = NULL;

    int choice, value, n, answer;

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

    printf("\nEnter value of n: ");
    scanf("%d", &n);

    printf("\nLinked List: ");
    display(head);

    if (findNthFromEnd(head, n, &answer)) {
        printf("Value at position %d from end: %d\n",
               n, answer);
    }
    else {
        printf("Invalid position!\n");
    }

    return 0;
}
