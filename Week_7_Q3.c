
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top;

/* Create an empty stack */
void Create()
{
    top = NULL;
}

/* Check if stack is empty */
int IsEmpty()
{
    return top == NULL;
}

/* Check if memory is available */
int IsFull()
{
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
        return 1;

    free(temp);
    return 0;
}

/* Insert element into stack */
void Push(int value)
{
    struct node *newnode;

    if (IsFull())
    {
        printf("Stack is full\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

/* Remove top element */
void Pop()
{
    struct node *temp;

    if (IsEmpty())
    {
        printf("Stack is empty\n");
        return;
    }

    temp = top;
    printf("Deleted: %d\n", top->data);

    top = top->next;
    free(temp);
}

/* Calculate stack size */
int Size()
{
    int count = 0;
    struct node *temp = top;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

/* Display stack */
void Display()
{
    struct node *temp = top;

    printf("Stack -");

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
        printf("\n1 to push\n");
        printf("2 to pop\n");
        printf("3 to calculate size\n");
        printf("4 to exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                Push(value);
                Display();
                break;

            case 2:
                Pop();
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
