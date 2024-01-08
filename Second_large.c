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

int secondLarge(struct Node* root)
{

    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        printf("Tree has less than two nodes.\n");
        return -1; // Return some value indicating error
    }
    struct Node* temp = NULL;//stores the parent of the largest node = 2nd Largest node

//if the right subtree is empty we can
//find the largest value in the right of the left sub tree
    if (root->right == NULL)
    {
        temp = root->left;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp->data;
    }
//when there is right subtree
//we can find the largest value in the rightmost node
else{
    while (root->right != NULL)
    {
        temp = root;
        root = root->right;
    }

    return temp->data;
 }
}

int main()
{
    int n, key;
    struct Node *root = NULL;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        root = insert(root, key);
    }

    if (secondLarge(root))
    {
        printf("Second largest element in BST: %d", secondLarge(root));
    }
    return 0;
}
