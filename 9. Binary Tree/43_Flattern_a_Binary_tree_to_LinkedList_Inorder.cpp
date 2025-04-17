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

TreeNode* binaryTreeToSortedLinkedList(TreeNode* root) {
    // Time complexity: O(n), where n is the number of nodes in the binary tree.
    // space complexity: O(1)

    if (root == NULL) {
        return NULL;
    }

    TreeNode* curr = root;

    // Head of the flattened list
    TreeNode* head = NULL; 

    // Keeps track of the last processed node
    TreeNode* prev = NULL;

    while (curr != NULL) {
        if (curr->left == NULL) {
            // Process the current node
            if (head == NULL) {
                // Set head on the first encountered node
                head = curr; 
            }
            if (prev != NULL) {
                // Link previous node to current node
                prev->right = curr; 
            }

            // Move prev pointer
            prev = curr; 
            
            // Move to the right subtree
            curr = curr->right; 
        } 
        else {
            // Find the inorder predecessor (rightmost node in the left subtree)
            TreeNode* pred = curr->left;
            while (pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == NULL) {
                // Establish a temporary link and move left
                pred->right = curr;
                curr = curr->left;
            } else {
                // Remove the temporary link
                pred->right = NULL;

                // Process current node
                if (head == NULL) {
                    head = curr;
                }
                if (prev != NULL) {
                    prev->right = curr;
                }
                prev = curr;

                // Set left to NULL to break cycles
                curr->left = NULL;
                
                // Move to the right subtree
                curr = curr->right; 
            }
        }
    }
    return head; // Return the head of the flattened list
}

int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(19);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(17);
    root->right->right = new TreeNode(20);

    // brute
    

    // optimal 
    TreeNode* FlatternResult = binaryTreeToSortedLinkedList(root);
    inorder_traversal(FlatternResult);
}