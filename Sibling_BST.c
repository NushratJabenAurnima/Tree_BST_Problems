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

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void printSiblingPairs(struct Node* root) {
    if (root == NULL)
        return;

    if (root->left != NULL && root->right != NULL) {
        printf("%d and %d  ",root->left->data, root->right->data);
    }
    printSiblingPairs(root->left);
    printSiblingPairs(root->right);
}


void deleteSiblings(struct Node* root)
{
    if (root == NULL)
        return;
    //if the right child don't have a sibling
    if (root->left == NULL)
    {
        struct Node* rightChild = root->right;
        free(rightChild);  // Free memory for the right child
        root->right = NULL;  // Disconnect the right child
    }
    //if the left child don't have a sibling
    if (root->right == NULL)
    {
        struct Node* leftChild = root->left;
        free(leftChild);  // Free memory for the left child
        root->left = NULL;  // Disconnect the left child
    }


    deleteSiblings(root->left);
    deleteSiblings(root->right);
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

    printf("Pre-order traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("The following pairs are siblings: ");
    printSiblingPairs(root);
    printf("\n");

    deleteSiblings(root);

    printf("Pre-order traversal after deleting siblings: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
