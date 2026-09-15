#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;
int size = 0;

void display(){
    int i;

    if (size == 0){
        printf("Stack is empty\n");
        return;
    }

    printf("Stack - ");

    for (i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }

    printf("\n");
}

void push(int x){
    int i, temp;

    if (size == MAX){
        printf("Stack Overflow\n");
        return;
    }
  
    rear++;
    queue[rear] = x;
    size++;
  
    for (i = 0; i < size - 1; i++){
        temp = queue[front];

        for (int j = front; j < rear; j++){
            queue[j] = queue[j + 1];
        }

        queue[rear] = temp;
    }

    display();
}

void pop(){
    int deleted;
    int i;

    if (size == 0){
        printf("Stack Underflow\n");
        return;
    }

    deleted = queue[front];

    /* Shift elements to the left */
    for (i = front; i < rear; i++){
        queue[i] = queue[i + 1];
    }

    rear--;
    size--;

    printf("Element popped from stack - %d\n", deleted);

    if (size > 0)
        display();
    else
        printf("Stack after pop operation - empty\n");
}

void findSize(){
    printf("Size of stack - %d\n", size);
}

int main(){
    int choice, value;

    while (1){
        printf("\nPress:\n");
        printf("1 to push\n");
        printf("2 to pop\n");
        printf("3 to find size\n");
        printf("4 to exit\n");

        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter element: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                findSize();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
