
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

// Create a new node
struct node* createNode(int x)
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

// Create tree from array
struct node* createTree(int a[], int i, int n)
{
    struct node *root;

    if(i >= n || a[i] == -1)
        return NULL;

    root = createNode(a[i]);

    root->left = createTree(a, 2*i+1, n);
    root->right = createTree(a, 2*i+2, n);

    return root;
}

// Find level having maximum nodes
void maxNodesLevel(struct node *root)
{
    struct node *q[1000];

    int front = 0, rear = 0;
    int level = 0;
    int maxCount = 0, maxLevel = 0;
    int firstCount = 0, allEqual = 1;

    if(root == NULL)
        return;

    q[rear++] = root;

    while(front < rear)
    {
        int count = rear - front;
        int i;

        level++;

        // Check whether all levels have equal nodes
        if(level == 1)
            firstCount = count;
        else if(count != firstCount)
            allEqual = 0;

        // Update maximum count
        if(count > maxCount)
        {
            maxCount = count;
            maxLevel = level;
        }

        // Process current level
        for(i = 0; i < count; i++)
        {
            struct node *temp = q[front++];

            if(temp->left != NULL)
                q[rear++] = temp->left;

            if(temp->right != NULL)
                q[rear++] = temp->right;
        }
    }

    if(allEqual)
        printf("Equal no. Of nodes on all levels");
    else
        printf("Level %d has %d nodes", maxLevel, maxCount);
}

// Level order traversal
void levelOrder(struct node *root)
{
    struct node *q[1000];
    int front = 0, rear = 0;

    if(root == NULL)
        return;

    q[rear++] = root;

    while(front < rear)
    {
        struct node *temp = q[front++];

        printf("%d ", temp->data);

        if(temp->left != NULL)
            q[rear++] = temp->left;

        if(temp->right != NULL)
            q[rear++] = temp->right;
    }
}

int main()
{
    struct node *root = NULL;

    int a[1000], n, i;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    root = createTree(a, 0, n);

    printf("BST: ");
    levelOrder(root);

    printf("\n");

    maxNodesLevel(root);

    return 0;
}
