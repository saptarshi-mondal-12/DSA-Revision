#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Binary Tree Maximum Path Sum

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.


Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

Intuition-------------------------------------------------------------------------------

We'll use DFS (Depth-First Search) recursion and post-order traversal (left → right → root).

At each node, we compute:
    1. Left max sum (from the left subtree)
    2. Right max sum (from the right subtree)
    3. Local max path sum that passes through the node (i.e., left + root + right)
    4. Update the global maximum if this local sum is higher.
    5. Return the max gain from the current node to its parent (i.e., root + max(left, right))

If any subtree gives a negative sum, we discard it by comparing it with 0.

*/

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


int dfs(TreeNode *node, int &maxSum){
    if (node == NULL)
        return 0;

    // Recursively calculate max gain from left and right (ignore negative paths)
    int leftGain = max(0, dfs(node->left, maxSum));
    int rightGain = max(0, dfs(node->right, maxSum));

    // Path sum including current node and both children
    int currentPathSum = node->data + leftGain + rightGain;

    // Update global max sum if current path is better
    maxSum = max(maxSum, currentPathSum);

    // Return max gain to parent (choose one side only)
    return node->data + max(leftGain, rightGain);
}

int maxPathSum(TreeNode *root){
    // Time: O(n), where n = number of nodes.
    // Space: O(h), where h = height of tree (for recursion stack).

    int maxSum = INT_MIN;
    dfs(root, maxSum);
    return maxSum;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout<<maxPathSum(root)<<endl;
}
