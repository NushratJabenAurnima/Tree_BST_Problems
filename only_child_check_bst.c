#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};


struct Node* insert(struct Node*, int);

// Function to create a new node
struct Node* createNode(int key)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key
struct Node* insert(struct Node* root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

int onechild(struct Node* root, int *c)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL)
    {
        *c++;
        onechild(root->right, &c);

    }
    if(root->right == NULL)
    {
        *c++;
        onechild(root->left, &c);

    }
    return *c;
}


int main()
{
    int n,c=0,key;
    struct Node *root = NULL;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        root = insert(root, key);
    }
    if(onechild(root,&c) == n)
        printf("Yes");
    else
        printf("No");
    return 0;

}
