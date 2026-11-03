
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

int arr[1000];
int count = 0;

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

// Create initial tree from array
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

// Store inorder elements in sorted array
void inorder(struct node *root)
{
    if(root == NULL)
        return;

    inorder(root->left);

    arr[count++] = root->data;

    inorder(root->right);
}

// Build balanced BST
struct node* buildBalanced(int start, int end)
{
    int mid;
    struct node *root;

    if(start > end)
        return NULL;

    mid = (start + end) / 2;

    root = createNode(arr[mid]);

    root->left = buildBalanced(start, mid-1);
    root->right = buildBalanced(mid+1, end);

    return root;
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

// Find minimum
int findMin(struct node *root)
{
    while(root->left != NULL)
        root = root->left;

    return root->data;
}

// Find maximum
int findMax(struct node *root)
{
    while(root->right != NULL)
        root = root->right;

    return root->data;
}

int main()
{
    struct node *root = NULL;
    struct node *balanced = NULL;

    int a[1000], n, i;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Create original BST
    root = createTree(a, 0, n);

    printf("Initial BST: ");
    levelOrder(root);

    // Store sorted elements
    inorder(root);

    // Build balanced BST
    balanced = buildBalanced(0, count-1);

    printf("\nBalanced BST: ");
    levelOrder(balanced);

    printf("\nMaximum element: %d", findMax(balanced));

    printf("\nMinimum element: %d\n", findMin(balanced));

    return 0;
}
