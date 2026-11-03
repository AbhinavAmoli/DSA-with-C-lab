#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}node;

node *head = NULL;
void Create(int k){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = k;
    newnode->prev = NULL;
    newnode->next = NULL;
}

void insert_front(int k){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = k;
    newnode->prev = NULL;
    newnode->next = head;
    if(head != NULL){
        head->prev = newnode;
    }
    head = newnode;
}

void insert_anywhere(int k, int pos){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = k;
    if(pos == 1){
        newnode->prev = NULL;
        newnode->next = head;
        if(head != NULL){
            head->prev = newnode;
        }
        head = newnode;
        return;
    }
    node *temp = head;
    for(int i=1; i<pos-1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Invalid position\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if(temp->next != NULL){
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

void insert_end(int k){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = k;
    newnode->next = NULL;
    if(head == NULL){
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void delete_front(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    head = head->next;
    if(head != NULL){
        head->prev = NULL;
    }
    free(temp);
}

void delete_anywhere(int pos){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    if(pos == 1){
        delete_front();
        return;
    }
    node *temp = head;
    for(int i=1; i<pos && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Invalid position\n");
        return;
    }
    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    }
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void delete_end(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp->prev != NULL){
        temp->prev->next = NULL;
    }
    free(temp);
}

void size(){
    int count = 0;
    node *temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    printf("Size of the list: %d\n", count);    
}

void display(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void middle(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    node *slow = head;
    node *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element: %d\n", slow->data);
}

int main(){
    int choice, value, pos;
    while(1){
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from front\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Size\n");
        printf("8. Display\n");
        printf("9. Middle element\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_front(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_end(value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                insert_anywhere(value, pos);
                break;
            case 4:
                delete_front();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_anywhere(pos);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}