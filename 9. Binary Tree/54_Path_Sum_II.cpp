#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Path Sum II

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

Example 1:

    //        5
    //      /   \
    //     4     8
    //    /     / \
    //   11    13  4
    //  /  \      / \
    // 7    2    5   1


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

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

void dfs(TreeNode *root, int targetSum, vector<int> &path, vector<vector<int>> &result){
    if (root == NULL)
        return;

    // Include current node in path
    path.push_back(root->val);
    targetSum -= root->val;

    // If it's a leaf and sum matches, add the path
    if (root->left == NULL && root->right == NULL && targetSum == 0){
        result.push_back(path); // make a copy of path
    }
    else{
        // Recur left and right
        dfs(root->left, targetSum, path, result);
        dfs(root->right, targetSum, path, result);
    }

    // Backtrack
    path.pop_back();
}
vector<vector<int>> pathSum(TreeNode *root, int targetSum){
    // Time: O(n), where n is the number of nodes. In the worst case, we explore every path.
    // Space: O(h) for recursion stack, and up to O(n) for storing paths in the result.

    vector<vector<int>> result;
    vector<int> path;
    dfs(root, targetSum, path, result);
    return result;
}

int main(){

    //        5
    //      /   \
    //     4     8
    //    /     / \
    //   11    13  4
    //  /  \        \
    // 7    2        1

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    vector<vector<int>> paths = pathSum(root, targetSum);

    cout << "Paths with sum " << targetSum << ":\n";
    for (auto &path : paths){
        for (int val : path){
            cout << val << " ";
        }
        cout << endl;
    }
}