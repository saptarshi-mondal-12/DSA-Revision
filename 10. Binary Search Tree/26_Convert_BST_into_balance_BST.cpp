#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Q. Conver a Binary Search Tree into Balance a Binary Search Tree

Given a root of a Binary Search Tree, modify and return the given BST such that it is balanced and has minimum possible height. If there is more than one answer, return any of them.

Note: The height of balanced BST returned by you will be compared with the expected height of the balanced tree.

Input: root = [1,null,2,null,3,null,4,null,null]
    1
     \  
      2 
       \ 
        3 
         \ 
          4 

Output: [2,1,3,null,null,null,4]
 
      2 
    /  \ 
   1    3 
         \ 
          4 


    OR 

      3 
     / \ 
    1   4 
     \ 
      2
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
     
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


void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}






// In-order traversal to collect values into a vector (sorted for BST)
void getInorder(TreeNode* root, vector<int>& inorder) {
    if (!root) return;
    getInorder(root->left, inorder);
    inorder.push_back(root->val);
    getInorder(root->right, inorder);
}

// Build balanced BST from sorted values
TreeNode* buildTree(const vector<int>& inorder, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(inorder[mid]);

    root->left = buildTree(inorder, start, mid - 1);
    root->right = buildTree(inorder, mid + 1, end);

    return root;
}

TreeNode *binaryTreeToBST(TreeNode *root){
    // Time: O(n) — each node visited once for traversal + once for tree construction.
    // Space: O(n) — for storing the in-order list + recursive call stack in worst-case.

    // 1. Get the values
    vector<int> inorder;
    getInorder(root, inorder);

    // 2. build tree
    TreeNode *newTree = buildTree(inorder, 0, inorder.size() - 1);

    return newTree;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    TreeNode* newTree = binaryTreeToBST(root);
    inorder(newTree);
}
