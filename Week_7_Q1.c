#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node *head=NULL;

void create(int k){
    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL){
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data=k;
    newnode->next=NULL;
    head=newnode;
}

void display(){
    struct Node *temp;
    if(head==NULL){
        printf("List is empty!\n");
        return;
    }
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void insert_front(int k){
    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL){
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data=k;
    newnode->next=head;
    head=newnode;
}

void insert_end(int k){
    struct Node *newnode,*temp;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL){
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data=k;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return;
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void insert_anywhere(int k,int p){
    struct Node *newnode,*temp;
    int i;
    if(p<1){
        printf("Invalid position!\n");
        return;
    }
    if(p==1){
        insert_front(k);
        return;
    }
    temp=head;
    for(i=1;i<p-1&&temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Invalid position!\n");
        return;
    }
    newnode=(struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL){
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data=k;
    newnode->next=temp->next;
    temp->next=newnode;
}

void delete_front(){
    struct Node *temp;
    if(head==NULL){
        printf("List is empty!\n");
        return;
    }
    temp=head;
    head=head->next;
    free(temp);
}

void delete_end(){
    struct Node *temp,*previous;
    if(head==NULL){
        printf("List is empty!\n");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    temp=head;
    while(temp->next!=NULL){
        previous=temp;
        temp=temp->next;
    }
    previous->next=NULL;
    free(temp);
}

void delete_anywhere(int p){
    struct Node *temp,*previous;
    int i;
    if(p<1){
        printf("Invalid position!\n");
        return;
    }
    if(p==1){
        delete_front();
        return;
    }
    temp=head;
    for(i=1;i<p&&temp!=NULL;i++){
        previous=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Invalid position!\n");
        return;
    }
    previous->next=temp->next;
    free(temp);
}

void size(){
    struct Node *temp;
    int count=0;
    temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    printf("Size of linked list is : %d\n",count);
}

void isempty(){
    if(head==NULL)
        printf("Linked List is empty\n");
    else
        printf("Linked List is not empty\n");
}

void findmiddle(){
    struct Node *slow,*fast;
    if(head==NULL){
        printf("List is empty!\n");
        return;
    }
    slow=head;
    fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("Middle element is : %d\n",slow->data);
}

int main(){
    int choice;
    int k,p;

    printf("Enter data : ");
    scanf("%d",&k);
    create(k);

    do{
        printf("\n");
        printf("1. Insert node at front\n");
        printf("2. Insert node at end\n");
        printf("3. Insert node at specific position\n");
        printf("4. Delete node from front\n");
        printf("5. Delete node from end\n");
        printf("6. Delete node from specific position\n");
        printf("7. Find size of linked list\n");
        printf("8. Find middle element of linked list\n");
        printf("9. Exit\n");
        printf("10. Check if linked list is empty\n");
        printf("Enter choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value to be inserted at front : ");
                scanf("%d",&k);
                insert_front(k);
                printf("Linked List : ");
                display();
                break;

            case 2:
                printf("Enter value to be inserted at end : ");
                scanf("%d",&k);
                insert_end(k);
                printf("Linked List : ");
                display();
                break;

            case 3:
                printf("Enter value to be inserted : ");
                scanf("%d",&k);
                printf("Enter position where value to be inserted : ");
                scanf("%d",&p);
                insert_anywhere(k,p);
                printf("Linked List : ");
                display();
                break;

            case 4:
                delete_front();
                printf("Linked List after deletion : ");
                display();
                break;

            case 5:
                delete_end();
                printf("Linked List after deletion : ");
                display();
                break;

            case 6:
                printf("Enter position from where node is to be deleted : ");
                scanf("%d",&p);
                delete_anywhere(p);
                printf("Linked List after deletion : ");
                display();
                break;

            case 7:
                size();
                printf("Linked List : ");
                display();
                break;

            case 8:
                findmiddle();
                printf("Linked List : ");
                display();
                break;

            case 9:
                printf("Exiting program...\n");
                break;

            case 10:
                isempty();
                printf("Linked List : ");
                display();
                break;

            default:
                printf("Invalid choice!\n");
        }
    }while(choice!=9);

    return 0;
}
