#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Deepest Leaves Sum

Given the root of a binary tree, return the sum of values of its deepest leaves.

Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

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

int findMaxDepth(TreeNode *root){
    if (root == NULL)
        return 0;

    int left = findMaxDepth(root->left);
    int right = findMaxDepth(root->right);

    return 1 + max(left, right);
}

void findTotalSum(TreeNode *root, int currDepth, int depth, int &totalSum){
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL && currDepth == depth){
        totalSum += root->val;
        return;
    }

    findTotalSum(root->left, currDepth + 1, depth, totalSum);
    findTotalSum(root->right, currDepth + 1, depth, totalSum);
}

int deepestLeavesSum(TreeNode *root){
    // Time Complexity: O(n), where n is the number of nodes in the tree. You traverse each node once to find depth and once to compute the sum.

    // Space Complexity: O(h), where h is the height of the tree (due to recursion stack).



    // 1. Find the maximum depth
    int depth = findMaxDepth(root);

    // 2. Find sum of sum of deepest leaves
    int totalSum = 0;
    findTotalSum(root, 1, depth, totalSum);

    // return the totalSum as answer
    return totalSum;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    root->right->right = new TreeNode(6);

    root->left->left->left = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    cout << deepestLeavesSum(root);
}