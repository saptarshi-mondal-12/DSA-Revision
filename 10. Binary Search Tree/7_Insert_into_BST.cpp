#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q. Insert into a Binary Search Tree

You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

Intuition: 
Find where it can be inserted 
Where -> be always a leaf node
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

void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    // Time complexity: O(logn)
    // space complexity: O(1)

    // Create a new node with the value to be inserted
    TreeNode* newNode = new TreeNode(val);

    // If the tree is empty (root is NULL), return the new node as the root
    if(root==NULL){
        return newNode;
    }

    // Pointer to traverse the tree and find the correct insertion point
    TreeNode* curr=root;

    // Traverse the tree to find the correct position to insert the new node
    while(true){
        // If the value to insert is greater than or equal to the current node's value
        if(curr->val <= val){
            // If the right child exists, move to the right
            if(curr->right!=NULL){
                curr=curr->right;
            }
            else{ // If the right child does not exist, insert the new node here and exit the loop
                curr->right=newNode;
                break;
            }
        }
        // If the value to insert is smaller than the current node's value
        else{
            // If the left child exists, move to the left
            if(curr->left!=NULL){
                curr=curr->left;
            }
            else{ // If the left child does not exist, insert the new node here and exit the loop
                curr->left=newNode;
                break;
            }
        }
    }
    // Return the root of the modified BST
    return root;
}


int main(){
    TreeNode* root = new TreeNode(8);
    
    TreeNode* root = new TreeNode(8);

    // Left subtree
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->left->right = new TreeNode(5);  
    root->left->right->right = new TreeNode(7);

    // Right subtree
    root->right = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    TreeNode* result = insertIntoBST(root, 122);
    inorder(result);
}