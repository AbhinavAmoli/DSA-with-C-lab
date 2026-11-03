
#include <stdio.h>

int heap[1000];
int order[1000];
int n = 0;
int counter = 0;

// Compare two elements
int higher(int i, int j)
{
    if(heap[i] > heap[j])
        return 1;

    if(heap[i] == heap[j] && order[i] < order[j])
        return 1;

    return 0;
}

// Swap elements
void swap(int i, int j)
{
    int temp;

    temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;

    temp = order[i];
    order[i] = order[j];
    order[j] = temp;
}

// Heapify upwards
void heapifyUp(int i)
{
    int parent;

    while(i > 0)
    {
        parent = (i-1)/2;

        if(higher(i, parent))
        {
            swap(i, parent);
            i = parent;
        }
        else
            break;
    }
}

// Heapify downwards
void heapifyDown(int i)
{
    int left, right, largest;

    while(1)
    {
        left = 2*i + 1;
        right = 2*i + 2;
        largest = i;

        if(left < n && higher(left, largest))
            largest = left;

        if(right < n && higher(right, largest))
            largest = right;

        if(largest != i)
        {
            swap(i, largest);
            i = largest;
        }
        else
            break;
    }
}

// Create heap
void create()
{
    int i;

    for(i = n/2 - 1; i >= 0; i--)
        heapifyDown(i);
}

// Insert element
void insert(int x)
{
    if(n == 1000)
    {
        printf("Heap is full\n");
        return;
    }

    heap[n] = x;
    order[n] = counter++;

    heapifyUp(n);

    n++;
}

// Get highest priority
int getHighestPriority()
{
    if(n == 0)
        return -1;

    return heap[0];
}

// Delete highest priority
int deleteHighestPriority()
{
    int x;

    if(n == 0)
        return -1;

    x = heap[0];

    heap[0] = heap[n-1];
    order[0] = order[n-1];

    n--;

    if(n > 0)
        heapifyDown(0);

    return x;
}

// Display heap
void display()
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main()
{
    int i, ch, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &heap[i]);
        order[i] = counter++;
    }

    create();

    printf("Initial Priority Queue: ");
    display();

    printf("Max Priority: %d\n", getHighestPriority());

    printf("Press:\n");
    printf("1 to insert node\n");
    printf("2 to delete node\n");
    printf("3 to exit\n");

    while(1)
    {
        scanf("%d", &ch);

        if(ch == 1)
        {
            scanf("%d", &x);

            insert(x);

            printf("Updated Priority Queue: ");
            display();
        }

        else if(ch == 2)
        {
            if(n == 0)
                printf("Priority Queue is empty\n");
            else
                printf("Deleted Priority: %d\n",
                       deleteHighestPriority());
        }

        else if(ch == 3)
            break;

        else
            printf("Invalid choice\n");
    }

    return 0;
}
