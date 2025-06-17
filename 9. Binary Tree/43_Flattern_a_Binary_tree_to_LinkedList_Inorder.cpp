#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

void inorder_traversal(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
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
    // Time complexity: O(N), where n is the number of nodes in the binary tree.
    // space complexity: O(H)

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
    return ret; // Return the head of the flattened list
}

int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(19);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(17);
    root->right->right = new TreeNode(20);
    

    // optimal 
    TreeNode* FlatternResult = binaryTreeToSortedLinkedList(root);
    inorder_traversal(FlatternResult);
}