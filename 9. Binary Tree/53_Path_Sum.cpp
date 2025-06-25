#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Path Sum
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

Example 1:

    //        5
    //      /   \
    //     4     8
    //    /     / \
    //   11    13  4
    //  /  \        \
    // 7    2        1


Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown. (5+4+11+2)



Example 2:

         1
        / \
       2   3

Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.



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

bool checkPathSum(TreeNode *root, int targetSum, int currSum){
    if (root == NULL)
        return false;

    currSum += root->val;

    // Check if it's a leaf node and the current sum matches the target
    if (root->left == NULL && root->right == NULL && currSum == targetSum){
        return true;
    }

    bool left = checkPathSum(root->left, targetSum, currSum);
    bool right = checkPathSum(root->right, targetSum, currSum);

    return left || right;
}
bool hasPathSum(TreeNode *root, int targetSum){
    // Time: O(n) — Traverse each node once
    // Space: O(h) — Recursion stack, where h is the height of the tree

    int currSum = 0;
    return checkPathSum(root, targetSum, currSum);
}

int main(){

    //        5
    //      /   \
    //     4     8
    //    /     / \
    //   11    13  4
    //  /  \        \
    // 7    2        1

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    cout<<hasPathSum(root, targetSum)<<endl;
}