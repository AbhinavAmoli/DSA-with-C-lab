#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int queue[MAX];
int size;
int front = -1;
int rear = -1;

void Create(){
    printf("Enter size of circular queue : ");
    scanf("%d", &size);

    if(size <= 0 || size > MAX){
        printf("Invalid size\n");
        exit(1);
    }

    front = -1;
    rear = -1;
}

int isEmpty(){
    return front == -1;
}

int isFull(){
    return (rear + 1) % size == front;
}

void display(){
    if(isEmpty())
        return;

    printf("Circular Queue : ");

    int i = front;

    while(1){
        printf("%d", queue[i]);

        if(i == rear)
            break;

        printf(" ");
        i = (i + 1) % size;
    }

    printf("\n");
}

void Enqueue(int x){
    if(isFull()){
        printf("Queue is full, cannot insert\n");
        return;
    }

    if(isEmpty()){
        front = rear = 0;
    }
    else{
        rear = (rear + 1) % size;
    }

    queue[rear] = x;

    printf("Enqueued element: %d\n", x);
    display();
}

void Dequeue(){
    int item;

    if(isEmpty()){
        printf("Queue is empty, cannot delete\n");
        return;
    }

    item = queue[front];

    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1) % size;
    }

    printf("Dequeued element: %d\n", item);
    display();
}

void Front(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }

    printf("Front : %d\n", queue[front]);
}

void Rear(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }

    printf("Rear : %d\n", queue[rear]);
}

int main(){

    int choice, value;

    Create();

    while(1){

        printf("Press:\n");
        printf("1 to enqueue\n");
        printf("2 to dequeue\n");
        printf("3 to find front\n");
        printf("4 to find rear\n");
        printf("5 to exit\n");

        scanf("%d", &choice);

        switch(choice){

            case 1:
                scanf("%d", &value);
                Enqueue(value);
                break;

            case 2:
                Dequeue();
                break;

            case 3:
                Front();
                break;

            case 4:
                Rear();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
