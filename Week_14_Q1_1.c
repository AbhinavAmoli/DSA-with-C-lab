
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};

struct node *head[100];

void addEdge(int u, int v)
{
    struct node *newnode;

    // Add v to u's list
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = head[u];
    head[u] = newnode;

    // Add u to v's list
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->vertex = u;
    newnode->next = head[v];
    head[v] = newnode;
}

void display(int n)
{
    int i;
    struct node *temp;

    for(i = 1; i <= n; i++)
    {
        printf("%d -> ", i);

        temp = head[i];

        while(temp != NULL)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int n = 4;
    int a[4][4] = {
        {0, 1, 0, 1},
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    int i, j;

    for(i = 1; i <= n; i++)
        head[i] = NULL;

    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(a[i][j] == 1)
                addEdge(i+1, j+1);
        }
    }

    printf("Adjacency List:\n");
    display(n);

    return 0;
}
