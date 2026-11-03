
#include <stdio.h>

int tree[100];
int n;

// Inorder: Left, Root, Right
void inorder(int i)
{
    if(i >= n || tree[i] == -1)
        return;

    inorder(2*i + 1);
    printf("%d ", tree[i]);
    inorder(2*i + 2);
}

// Postorder: Left, Right, Root
void postorder(int i)
{
    if(i >= n || tree[i] == -1)
        return;

    postorder(2*i + 1);
    postorder(2*i + 2);
    printf("%d ", tree[i]);
}

// Preorder: Root, Left, Right
void preorder(int i)
{
    if(i >= n || tree[i] == -1)
        return;

    printf("%d ", tree[i]);
    preorder(2*i + 1);
    preorder(2*i + 2);
}

int main()
{
    int i;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &tree[i]);
    }

    printf("Inorder : ");
    inorder(0);

    printf("\nPostorder : ");
    postorder(0);

    printf("\nPreorder : ");
    preorder(0);

    return 0;
}
