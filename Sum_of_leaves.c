#include <stdio.h>
#include <stdlib.h>

// struct binary tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// utility function which calculates
// sum of all leaf nodes
void  SumOfLeaf(struct Node *root, int *sum)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        *sum += root->data;
    SumOfLeaf(root->left, sum);
    SumOfLeaf(root->right, sum);
}


int max(int *sum1, int *sum2)
{

    if (*sum1 < *sum2)
        return *sum2;
    else
        return *sum1;
}

// driver program
int main()
{

    /*create a tree*/
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);

    // variable to store sum of leaf nodes
    int sum1 = 0, sum2 = 0;
    SumOfLeaf(root->left, &sum1);
    SumOfLeaf(root->right, &sum2);
    printf("%d\n", max(&sum1, &sum2));
    return 0;
}
<!DOCTYPE html>
<html>
<body>
<h2>Project Done by &copy; Nushrat Jaben Aurnima. All Rights Reserved .</h2>
</body>
</html>
