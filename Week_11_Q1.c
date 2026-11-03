
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}node;

// Create a new node
node *create_node(int value){
    node *new_node = (node*)malloc(sizeof(node));

    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// Create tree using array
node *CreateTree(int arr[], int i, int n){

    if(i >= n || arr[i] == -1)
        return NULL;

    node *root = create_node(arr[i]);

    root->left = CreateTree(arr, 2*i+1, n);
    root->right = CreateTree(arr, 2*i+2, n);

    return root;
}

// Insert node using level order
node *InsertNode(node *root, int key){

    if(root == NULL)
        return create_node(key);

    node *queue[10000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear){

        node *temp = queue[front++];

        if(temp->left == NULL){
            temp->left = create_node(key);
            return root;
        }
        else{
            queue[rear++] = temp->left;
        }

        if(temp->right == NULL){
            temp->right = create_node(key);
            return root;
        }
        else{
            queue[rear++] = temp->right;
        }
    }

    return root;
}

// Delete node
node *DeleteNode(node *root, int key){

    if(root == NULL)
        return NULL;

    node *queue[10000];
    int front = 0, rear = 0;

    node *key_node = NULL;
    node *temp = NULL;
    node *deepest_parent = NULL;

    queue[rear++] = root;

    while(front < rear){

        temp = queue[front++];

        if(temp->data == key)
            key_node = temp;

        if(temp->left != NULL){
            deepest_parent = temp;
            queue[rear++] = temp->left;
        }

        if(temp->right != NULL){
            deepest_parent = temp;
            queue[rear++] = temp->right;
        }
    }

    // Element not found
    if(key_node == NULL)
        return root;

    // Only root exists
    if(front == 1){
        free(root);
        return NULL;
    }

    // Replace with deepest node
    key_node->data = temp->data;

    // Delete deepest node
    if(deepest_parent->right == temp){
        free(deepest_parent->right);
        deepest_parent->right = NULL;
    }
    else{
        free(deepest_parent->left);
        deepest_parent->left = NULL;
    }

    return root;
}

// Find height (height measured in edges)
int FindHeight(node *root){

    if(root == NULL)
        return -1;

    int lh = FindHeight(root->left);
    int rh = FindHeight(root->right);

    if(lh > rh)
        return lh + 1;
    else
        return rh + 1;
}

// Find total number of nodes
int FindSize(node *root){

    if(root == NULL)
        return 0;

    return 1 + FindSize(root->left)
             + FindSize(root->right);
}

// Search an element
int Search(node *root, int key){

    if(root == NULL)
        return 0;

    if(root->data == key)
        return 1;

    return Search(root->left, key) ||
           Search(root->right, key);
}

// Display tree using level order
void Display(node *root){

    if(root == NULL){
        printf("Empty Tree");
        return;
    }

    node *queue[10000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear){

        node *temp = queue[front++];

        printf("%d ", temp->data);

        if(temp->left != NULL)
            queue[rear++] = temp->left;

        if(temp->right != NULL)
            queue[rear++] = temp->right;
    }
}

int main(){

    int n, i, choice, key;

    node *root = NULL;

    // Input array size
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // Create tree
    root = CreateTree(arr, 0, n);

    // Menu
    do{

        printf("\n1 to insert a node");
        printf("\n2 to delete a node");
        printf("\n3 to exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter value: ");
                scanf("%d", &key);

                root = InsertNode(root, key);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &key);

                if(Search(root, key)){
                    root = DeleteNode(root, key);
                }
                else{
                    printf("Node not found\n");
                }
                break;

            case 3:
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice != 3);

    // Final output
    printf("\nTree: ");
    Display(root);

    printf("\nHeight = %d", FindHeight(root));

    printf("\nSize = %d\n", FindSize(root));

    return 0;
}
