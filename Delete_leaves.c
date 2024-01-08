#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void preorderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}


//return type must to update delete
struct Node* deleteleaves(struct Node* root)
{
    if (root == NULL)
        return NULL;

    //if the right child don't have a sibling
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

   //since the function has a return type that's why
   //calling the recursive function this way
   root->left = deleteleaves(root->left);
   root->right = deleteleaves(root->right);
}


int main()
{
    int n,key;
    struct Node *root = NULL;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(root, key);
        root = insert(root, key);
    }

    root = deleteleaves(root);
    printf("Pre-order traversal after deleting leaves: ");
    preorderTraversal(root);
    printf("\n");


    return 0;
}
