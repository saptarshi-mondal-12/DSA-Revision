#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Morris Inorder Traversal of a Binary tree

Given a Binary Tree, implement Morris Inorder Traversal and return the array containing its inorder sequence.
Morris Inorder Traversal is a tree traversal algorithm aiming to achieve a space complexity of O(1) without recursion or an external data structure. The algorithm should efficiently visit each node in the binary tree in inorder sequence, printing or processing the node values as it traverses, without using a stack or recursion.

Algorithm / Intuition: 
Morris Traversal is a tree traversal algorithm that allows for an in-order traversal of a binary tree without using recursion or a stack. It uses threading to traverse the tree efficiently. The key idea is to establish a temporary link between the current node and its in-order successor.

Case 1: The current node has no left subtree.

    a. Print the value of the current node.
    b. Then to the right child of the current node.

If there is no left subtree, we simply print the value of the current node because there are no nodes to traverse on the left side. After that, we move to the right child to continue the traversal.

Case 2: There is a left subtree, and the right-most child of this left subtree is pointing to null.

    a. Set the right-most child of the left subtree to point to the current node.
    b. Move to the left child of the current node.
In this case, we haven't visited the left subtree yet. We establish a temporary link from the rightmost node of the left subtree to the current node. This link helps us later to identify when we've completed the in-order traversal of the left subtree. After setting the link, we move to the left child to explore the left subtree.

Case 3: There is a left subtree, and the right-most child of this left subtree is already pointing to the current node.

    a. Print the value of the current node.
    b. Revert the temporary link (set it back to null).
    c. Move to the right child of the current node.

This case is crucial for maintaining the integrity of the tree structure. If the right-most child of the left subtree is already pointing to the current node, it means we've completed the in-order traversal of the left subtree. We print the value of the current node and then revert the temporary link to restore the original tree structure. Finally, we move to the right child to continue the traversal.

Note: The temporary links added in Case 2 are essential for identifying the completion of the left subtree in Case 3. It's critical to revert these links to avoid altering the original structure of the tree.

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

vector<int> inorderTraversal(TreeNode* root) {
    /*
    Time Complexity: O(2N) where N is the number of nodes in the Binary Tree.
        The time complexity is linear, as each node is visited at most twice (once for establishing the temporary link and once for reverting it).
        In each step, we perform constant-time operations, such as moving to the left or right child and updating pointers.
    
    Space Complexity: O(1) 
    */

    // Vector to store the inorder traversal result
    vector<int>inorder;

    // if root is NULL, return
    if(root==NULL){
        return inorder;
    }

    // Pointer to the current node, starting from the root
    TreeNode* curr=root;

    // Loop until the current node is not NULL
    while(curr!=NULL){
        // If the current node's left child is NULL
        if(curr->left==NULL){
            // Add the value of the current node to the inorder vector
            inorder.push_back(curr->data);
            // Move to the right child
            curr=curr->right;
        }
        else{
            // If the left child is not NULL, find the predecessor (rightmost node in the left subtree)
            TreeNode* prev=curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }

            // If the predecessor's right child is NULL, establish a temporary link and move to the left child
            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }else{
                // If the predecessor's right child is already linked, remove the link, add current node to inorder vector, and move to the right child
                prev->right=NULL;
                inorder.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    // Return the inorder traversal result
    return inorder;   
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    vector<int>inorder=inorderTraversal(root);

    for(int i=0;i<inorder.size(); i++){
        cout<<inorder[i]<<" ";
    }
}