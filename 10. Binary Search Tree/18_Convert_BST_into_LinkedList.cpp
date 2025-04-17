#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q. Convert Binary Search Tree in Linkedlist

Intuition- 
if we perform a morris inorder traversal, we can solve the problem
In morris traversalwe are returning a inorder vector as our answer 
Here we are return a node i.e head of a linkedList.
    1
     \
      2 
       \ 
        3
         \
          4
           \
            5

So for this question, morris inorder traversal has some slightly changes. instead of push_back element in vector we are creating a node tree i.e head (Head of the flattened tree) and a prev to Keeps track of the last processed node. 

below line is added : 

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

TreeNode* printLinkedList(TreeNode* root){
    while(root!=NULL){
        cout<<root->val<<" ";
        root=root->right;
    }
    cout<<endl;
}

TreeNode* binaryTreeToSortedLinkedList(TreeNode* root) {
    // Time complexity: O(n), where n is the number of nodes in the binary tree.
    // space complexity: O(1)

    if (root == NULL) {
        return NULL;
    }

    TreeNode* curr = root;

    // Head of the flattened tree
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
    TreeNode* result = binaryTreeToSortedLinkedList(root);
    printLinkedList(result);

}