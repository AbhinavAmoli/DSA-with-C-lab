
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* insert(Node *head, int value) {
    Node *newNode, *temp;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    temp = head;

    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    return head;
}

void display(struct Node *head) {
    struct Node *temp;

    if (head == NULL) {
        printf("Empty\n");
        return;
    }

    temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

struct Node* concatenate(struct Node *head1,
                         struct Node *head2) {
    struct Node *temp1, *temp2;

    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    temp1 = head1;
    while (temp1->next != head1)
        temp1 = temp1->next;

    temp2 = head2;
    while (temp2->next != head2)
        temp2 = temp2->next;

    temp1->next = head2;
    temp2->next = head1;

    return head1;
}

int main() {
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *result = NULL;

    int choice, value;

    while (1) {
        printf("\n1. Insert into First List");
        printf("\n2. Insert into Second List");
        printf("\n3. Display Both Lists");
        printf("\n4. Concatenate Lists");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head1 = insert(head1, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                head2 = insert(head2, value);
                break;

            case 3:
                printf("First circular linked list: ");
                display(head1);

                printf("Second circular linked list: ");
                display(head2);
                break;

            case 4:
                if (result != NULL) {
                    printf("Lists already concatenated.\n");
                    break;
                }

                result = concatenate(head1, head2);

                printf("First circular linked list: ");
                display(head1);

                printf("Second circular linked list: ");
                display(head2);

                printf("Final concatenated linked list: ");
                display(result);

                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
