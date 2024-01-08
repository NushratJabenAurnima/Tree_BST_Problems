## Problem 1
**Write a program that will display child of each node of a BST (Write only the 
Function).**

 **INPUT: 50 20 70 10 45**

**OUTPUT:**

**Child of 50: 20 and 70**

**Child of 20: 10 and 45**

**Child of 10: NULL**

**Child of 45: NULL**

**Child of 70: NULL**

## Problem 2
**Given a Binary Search Tree (BST), write a function FindSecondLargest (root) to find the second largest element.**

## Problem 3
**Write a program that will delete all leaves of a BST**

**Example 1:**

**Input: 10 5**

**Output: 5**

**Example 2:**

**Input: 10 5 20 30**

**Output: 20**

## Problem 4
**Write a program that will construct a BST, print the nodes who are sibling (child of same parent) in the BST and delete those nodes that are leaf and doesn't have any sibling.
First, your program will take inputs from the user and construct the BST, Second, it will print the tree elements using preorder traversal. Next, it will print the nodes who are sibling (child of same parent) in the BST. Finally, it will delete those nodes that are leaf and doesn't have any sibling and print the tree using preorder traversal.**

**Sample Input: 50 20 70 10 45 80 48**

**Sample Output**

**Pre order traversal: 50 20 10 45 48 70 80**

**The following pairs are siblings:**

**20 and 70**

**20 and 45**

**Pre order traversal after deletion: 10 20 45 50 70 80**

## Problem 5

**Write a function that will compute the sum of leaf nodes in each level of a binary tree and 
will find the maximum among those. 
Considering the following example also show the steps executed by your proposed 
function.**

**Input: 1 2 3 4 5 8 6 7**

**Output: 13**
  
## Problem 6

**Given Preorder traversal of a BST, write a function to check if each non-leaf node has 
only one child. Assume that the BST contains unique entries.
Example:**

**Input: pre = {20, 10, 11, 13, 12}**

**Output: Yes**
