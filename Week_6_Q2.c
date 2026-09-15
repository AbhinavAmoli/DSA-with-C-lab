#include <stdio.h>
#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;


void push1(int x){
    if (top1 == MAX - 1){
        printf("Queue Overflow\n");
        return;
    }
    s1[++top1] = x;
}

void push2(int x){
    s2[++top2] = x;
}

int pop1(){
    return s1[top1--];
}

int pop2(){
    return s2[top2--];
}


void display(){
    int i;

    printf("Queue - ");

    /* Elements in s2 are already in queue order */
    for (i = top2; i >= 0; i--)
        printf("%d ", s2[i]);

    /* Elements in s1 are in reverse stack order */
    for (i = 0; i <= top1; i++)
        printf("%d ", s1[i]);

    printf("\n");
}

void enqueue(int x){
    push1(x);
    display();
}

void dequeue(){
    int deleted;

    if (top1 == -1 && top2 == -1){
        printf("Queue Underflow\n");
        return;
    }

    /* Transfer elements only when s2 is empty */
    if (top2 == -1){
        while (top1 != -1)
            push2(pop1());
    }

    deleted = pop2();

    printf("Element deleted from queue - %d\n", deleted);

    printf("Queue after deletion- ");

    int i;

    for (i = top2; i >= 0; i--)
        printf("%d ", s2[i]);

    for (i = 0; i <= top1; i++)
        printf("%d ", s1[i]);

    printf("\n");
}

int main(){
    int choice, value;

    while (1){
        printf("\nPress:\n");
        printf("1 to enqueue\n");
        printf("2 to dequeue\n");
        printf("3 to exit\n");

        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter element: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
