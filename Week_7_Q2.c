
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front, *rear;

/* Create an empty queue */
void Create()
{
    front = NULL;
    rear = NULL;
}

/* Check whether queue is empty */
int IsEmpty()
{
    return front == NULL;
}

/* Insert element into queue */
void EnQueue(int value)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = value;
    newnode->next = NULL;

    if (IsEmpty())
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

/* Delete element from queue */
void DeQueue()
{
    struct node *temp;

    if (IsEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front;
    printf("Deleted: %d\n", front->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

/* Calculate queue size */
int Size()
{
    int count = 0;
    struct node *temp = front;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

/* Display queue contents */
void Display()
{
    struct node *temp = front;

    printf("Queue -");

    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    Create();

    while (1)
    {
        printf("\n1 to enqueue\n");
        printf("2 to dequeue\n");
        printf("3 to calculate size\n");
        printf("4 to exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                EnQueue(value);
                Display();
                break;

            case 2:
                DeQueue();
                Display();
                break;

            case 3:
                printf("Size = %d\n", Size());
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
