<!DOCTYPE html>
<html>
<body>
<h2>Project Done by &copy; Nushrat Jaben Aurnima. All Rights Reserved .</h2>
</body>
</html>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void printSiblingPairs(struct Node* root) {
    if (root == NULL)
        return;

    if (root->left != NULL && root->right != NULL) {
        printf("\nChild of %d: %d and %d  ",root->data, root->left->data, root->right->data);
    }
    else if(root->left == NULL && root->right == NULL) {
        printf("\nChild of %d: NULL",root->data);
    }

    printSiblingPairs(root->left);
    printSiblingPairs(root->right);
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

    printSiblingPairs(root);
    printf("\n");

    return 0;
}
