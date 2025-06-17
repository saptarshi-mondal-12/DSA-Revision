#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q. Convert Binary Search Tree in sorted Linkedlist

You are given a Binary Search Tree (BST) with n nodes, each node has a distinct value assigned to it. The goal is to flatten the tree such that, the left child of each element points to nothing (NULL), and the right child points to the next element in the sorted list of elements of the BST (look at the examples for clarity). You must accomplish this without using any extra storage, except for recursive calls, which are allowed.

Note: If your BST does have a left child, then the system will print a -1 and will skip it, resulting in an incorrect solution.

Example 1:

Input:
          5
        /    \
       3      7
      /  \    /   \
     2   4  6     8

Output: 2 3 4 5 6 7 8

Explanation: After flattening, the tree looks like this
    2
     \
      3
       \
        4
         \
          5
           \
            6
             \
              7
               \
                8
Here, left of each node points to NULL and right contains the next node.
*/


class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

void inorederTraversal(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorederTraversal(root->left);
    cout<<root->val<<" ";
    inorederTraversal(root->right);
}


void inorder(TreeNode* curr, TreeNode*& prev){
    // Base case
    if (curr == NULL)
        return;
    inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}

TreeNode* binaryTreeToSortedLinkedList(TreeNode* root) {
    // Time Complexity: O(N)
    // Auxiliary Space: O(H)
        
    // Dummy node
    TreeNode* dummy = new TreeNode(-1);
    
    // Pointer to previous element
    TreeNode* prev = dummy;
    
    // Calling in-order traversal
    inorder(root, prev);
    
    prev->left = NULL;
    prev->right = NULL;
    TreeNode* ret = dummy->right;
    
    // Delete dummy node
    delete dummy;
    return ret;
}


int main(){
    TreeNode* root = new TreeNode(8);
    
    // Left subtree
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    // Right subtree
    root->right = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    // iterative method
    binaryTreeToSortedLinkedList(root);
    inorederTraversal(root);

}