#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Morris preorder Traversal of a Binary tree

We extend Morris Inorder Traversal to Preorder Morris Traversal and modify the algorithm to print the current node’s value before moving to the left child when the right child of the inorder predecessor is null.

This change ensures that the nodes are processed in the desired order for Preorder Traversal. The basic structure of Morris Traversal remains intact, but the printing step is adjusted, resulting in a Preorder Traversal that is still in-place and has a constant space complexity.

In Morris Inorder Traversal, we are traversing the tree in the way: Left, Root, Right. In Morris Preorder traversal we want to traverse the tree in the way: Root, Left, Right. Therefore, the following code changes are required:

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

vector<int> preorderTraversal(TreeNode* root) {
    /*
    Time Complexity: O(2N)
    Space Complexity: O(1)
    */

    // Vector to store the preorder traversal result
    vector<int>preorder;

    // if root is NULL, return
    if(root==NULL){
        return preorder;
    }

    // Pointer to the current node, starting from the root
    TreeNode* curr=root;

    // Loop until the current node is not NULL
    while(curr!=NULL){
        // If the current node's left child is NULL
        if(curr->left==NULL){
            // Add the value of the current node to the preorder vector
            preorder.push_back(curr->data);
            // Move to the right child
            curr=curr->right;
        }
        else{
            // If the current node has a left child Create a pointer to traverse to the rightmost node in the left subtree
            TreeNode* prev=curr->left;

            // Traverse to the rightmost node in the left subtree or until we find a node whose right child is not yet processed
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }

            // If the right child of the rightmost node is NULL
            if(prev->right==NULL){
                // Set the right child of the rightmost node to the current node
                prev->right=curr;

                // Add the value of the current node to the preorder vector
                preorder.push_back(curr->data);

                // Move to the left child
                curr=curr->left;
            }else{
                // If the right child of the rightmost node is not NULL Reset the right child to NULL
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    // Return the preorder traversal result
    return preorder;   
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    vector<int>preorder=preorderTraversal(root);

    for(int i=0;i<preorder.size(); i++){
        cout<<preorder[i]<<" ";
    }
}