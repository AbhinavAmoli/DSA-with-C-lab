
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* createNode(int x)
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

// Create tree from array representation
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

// Insert a node
struct node* insert(struct node *root, int x)
{
    if(root == NULL)
        return createNode(x);

    if(x < root->data)
        root->left = insert(root->left, x);

    else if(x > root->data)
        root->right = insert(root->right, x);

    return root;
}

// Find minimum node
struct node* findMin(struct node *root)
{
    while(root->left != NULL)
        root = root->left;

    return root;
}

// Delete a node
struct node* deleteNode(struct node *root, int x)
{
    struct node *temp;

    if(root == NULL)
        return NULL;

    if(x < root->data)
        root->left = deleteNode(root->left, x);

    else if(x > root->data)
        root->right = deleteNode(root->right, x);

    else
    {
        // No left child
        if(root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }

        // No right child
        else if(root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        // Two children
        temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Search a key
int search(struct node *root, int key)
{
    if(root == NULL)
        return 0;

    if(root->data == key)
        return 1;

    if(key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Find height
int findHeight(struct node *root)
{
    int lh, rh;

    if(root == NULL)
        return -1;

    lh = findHeight(root->left);
    rh = findHeight(root->right);

    if(lh > rh)
        return lh + 1;

    return rh + 1;
}

// Find depth of tree
int findDepth(struct node *root)
{
    return findHeight(root);
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
    int a[100], n, i, ch, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    root = createTree(a, 0, n);

    printf("Press:\n");
    printf("1 to insert a node\n");
    printf("2 to delete a node\n");
    printf("3 to search a key\n");
    printf("4 to exit\n");

    while(1)
    {
        scanf("%d", &ch);

        if(ch == 1)
        {
            scanf("%d", &x);
            root = insert(root, x);
        }

        else if(ch == 2)
        {
            scanf("%d", &x);
            root = deleteNode(root, x);
        }

        else if(ch == 3)
        {
            scanf("%d", &x);

            if(search(root, x))
                printf("%d - present\n", x);
            else
                printf("Not present\n");
        }

        else if(ch == 4)
            break;

        else
            printf("Invalid choice\n");
    }

    printf("BST: ");
    levelOrder(root);

    printf("\nHeight = %d", findHeight(root));
    printf("\nDepth = %d\n", findDepth(root));

    return 0;
}
