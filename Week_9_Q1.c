
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

// Create a new node
node *create_node(int value) {
    node *newnode = (node *)malloc(sizeof(node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newnode->data = value;
    newnode->next = NULL;

    return newnode;
}

// Check if list is empty
int isEmpty() {
    return head == NULL;
}

// Create(k) - Create circular linked list
void create(int value) {
    node *newnode = create_node(value);

    if (newnode == NULL)
        return;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    }
    else {
        printf("List already exists\n");
        free(newnode);
    }
}

// Display list
void display() {
    if (isEmpty()) {
        printf("List is empty\n");
        return;
    }

    node *temp = head;

    printf("Circular Linked List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

// Insert at front
void insert_front(int value) {
    node *newnode = create_node(value);

    if (newnode == NULL)
        return;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        return;
    }

    node *temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    newnode->next = head;
    temp->next = newnode;
    head = newnode;
}

// Insert at end
void insert_end(int value) {
    node *newnode = create_node(value);

    if (newnode == NULL)
        return;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        return;
    }

    node *temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;
}

// Insert at specific position
void insert_anywhere(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insert_front(value);
        return;
    }

    if (head == NULL) {
        printf("Invalid position\n");
        return;
    }

    node *temp = head;
    int i;

    for (i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (i != pos - 1) {
        printf("Invalid position\n");
        return;
    }

    node *newnode = create_node(value);

    if (newnode == NULL)
        return;

    newnode->next = temp->next;
    temp->next = newnode;
}

// Delete from front
void delete_front() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = head;

    if (head->next == head) {
        head = NULL;
        free(temp);
        return;
    }

    node *last = head;

    while (last->next != head) {
        last = last->next;
    }

    head = head->next;
    last->next = head;

    free(temp);
}

// Delete from end
void delete_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = head;

    if (head->next == head) {
        head = NULL;
        free(temp);
        return;
    }

    node *prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

// Delete from specific position
void delete_anywhere(int pos) {
    if (head == NULL || pos < 1) {
        printf("Invalid position or empty list\n");
        return;
    }

    if (pos == 1) {
        delete_front();
        return;
    }

    node *temp = head;
    node *prev = NULL;
    int i;

    for (i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (i != pos) {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Find size
int size() {
    if (head == NULL)
        return 0;

    int count = 0;
    node *temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

// Find middle element
void find_middle() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *slow = head;
    node *fast = head;

    while (fast->next != head &&
           fast->next->next != head) {

        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle element: %d\n", slow->data);
}

// Main function
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n1. Create list\n");
        printf("2. Insert at front\n");
        printf("3. Insert at end\n");
        printf("4. Insert at specific position\n");
        printf("5. Delete from front\n");
        printf("6. Delete from end\n");
        printf("7. Delete from specific position\n");
        printf("8. Find size\n");
        printf("9. Check if empty\n");
        printf("10. Find middle element\n");
        printf("11. Display list\n");
        printf("12. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                create(value);
                display();
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_front(value);
                display();
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_end(value);
                display();
                break;

            case 4:
                printf("Enter value and position: ");
                scanf("%d%d", &value, &pos);
                insert_anywhere(value, pos);
                display();
                break;

            case 5:
                delete_front();
                display();
                break;

            case 6:
                delete_end();
                display();
                break;

            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_anywhere(pos);
                display();
                break;

            case 8:
                printf("Size of list: %d\n", size());
                break;

            case 9:
                if (isEmpty())
                    printf("List is empty\n");
                else
                    printf("List is not empty\n");
                break;

            case 10:
                find_middle();
                break;

            case 11:
                display();
                break;

            case 12:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
