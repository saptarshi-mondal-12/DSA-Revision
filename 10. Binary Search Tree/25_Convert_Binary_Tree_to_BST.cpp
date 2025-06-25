#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Q. Convert Binary Tree to BST

Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.

Input:
      1
    /   \
   2     3
Output: 1 2 3
Explanation: The converted BST will be
      2
    /   \
   1     3

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


void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void getValues(TreeNode *root, vector<int> &inorder){
    // Time complexity: O(n) — each node is visited exactly once.
    // Space complexity: O(n) — to store the values in the vector.
    if (root == NULL)
        return;

    getValues(root->left, inorder);
    inorder.push_back(root->val);
    getValues(root->right, inorder);
}

TreeNode *buildTree(vector<int> inorder, int start, int end){
    // Time complexity: O(n)

    if (start > end)
    {
        return NULL;
    }

    // Find mid to create our new node
    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(inorder[mid]);

    root->left = buildTree(inorder, start, mid - 1);
    root->right = buildTree(inorder, mid + 1, end);

    return root;
}
TreeNode *binaryTreeToBST(TreeNode *root){
    // Time complexity: O(n) + O(n log n) + O(n)
    // Space compelxity: O(n)

    // 1. Get the values
    vector<int> inorder;
    getValues(root, inorder);

    // 2. Sort the inorder
    sort(inorder.begin(), inorder.end());

    // 3. build tree
    TreeNode *newTree = buildTree(inorder, 0, inorder.size() - 1);

    return newTree;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    TreeNode* newTree = binaryTreeToBST(root);
    inorder(newTree);
}
