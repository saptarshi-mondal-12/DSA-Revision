#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Maximum Sum BST in Binary Tree

NOTE: Same question as Q19. But here we have to find maximum sum of BST

Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.

*/

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

struct info{
public:
    int maxi;   // Max value in subtree
    int mini;   // Min value in subtree
    bool isBST; // Is subtree a BST
    int sum;    // sum
};

info maxSumBST_helper(TreeNode *root, int &maxSum){
    /*Step 1: Base case, if root is null return {mini, maxi, isBST, sum} - The base case is executed when a node is NULL, which happens in two scenarios: When the tree itself is empty. When we reach a leaf node’s left or right child (both will be NULL). */
    if (root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }

    // Step 2: Recursively get info from left and right subtrees
    info left = maxSumBST_helper(root->left, maxSum);
    info right = maxSumBST_helper(root->right, maxSum);

    info currNode;
    currNode.sum = root->val + left.sum + right.sum;
    currNode.maxi = max(root->val, right.maxi);
    currNode.mini = min(root->val, left.mini);

    // Step 3: Check if Current Subtree is a BST
    if (left.isBST && right.isBST && left.maxi < root->val && root->val < right.mini){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    // Step 4: If Valid BST, Update maximum sum of BST
    if (currNode.isBST){
        maxSum = max(maxSum, currNode.sum);
    }

    return currNode;
}

int maxSumBST(TreeNode *root){
    // Time complexity: O(n) - Each node is visited once and processes its left and right subtree in constant time. Since it's a postorder traversal (bottom-up), each node contributes O(1) time.

    // space complexity: O(h) - where h is the tree height.

    int maxSum = 0;
    maxSumBST_helper(root, maxSum);
    return maxSum;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);

    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(6);

    int result = maxSumBST(root);
    cout << "Maximum Sum BST: " << result << endl;
}
