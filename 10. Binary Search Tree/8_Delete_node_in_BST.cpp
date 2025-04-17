#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q. Delete node in Binary Search Tree

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:
    1. Search for a node to remove.
    2. If the node is found, delete the node.

Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Intuition: delete key = 3

        8
       /  \
      3    10
     /  \    \
    2    6    14
   / \   / \   /
  1   5 4   7 13  


STEP 1: Find key and Disconnect key's right( 3->right is disconnected, current root = 3 )
        i.e. rightChild=root->right
          6    
         / \   
        4   7 

STEP 2: go to extreme right (key ke left ka ectreme right), current root = 3
        i.e lastRight=root->left i.e = 2 (2 ka extreme right)

STEP 3: Connect lastRight to rightChild
        8
       /  \
      3    10
     /       \
    2         14
   / \         /
  1   5       13 
       \
        6
       / \
      4   7

step 4: return root's left i.e node 2 is return, current root = 3
        After this, node 2 is connect to node 8 left, root->left=helper(root->left);
        Final result:
       8 
     /   \
    2     10         
   / \      \       
  1   5      14       
       \     /
        6    13
       / \
      4   7
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

TreeNode* helper(TreeNode* root){
    // if root's left is null, then return root's right
    // NOTE: cuurent node(root) has to delete i.e. we return root->right to connect;
    if(root->left==NULL){
        return root->right;
    }

    // if root's right is null, then return root's left
    if(root->right==NULL){
        return root->left;
    }

    // create a variable rightChild to store root's right 
    TreeNode* rightChild=root->right;

    // go to root's left and go right until we get null
    TreeNode* lastRight=root->left;
    while(lastRight->right!=NULL){
        lastRight=lastRight->right;
    }
    // connect lastRight to rightChild
    if(lastRight->right == NULL){
        lastRight->right=rightChild;
    }

    return root->left;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    // if root is NULL, return
    if(root==NULL){
        return NULL;
    }
    if(root->val == key){
        return helper(root);
    }
    TreeNode* dummy=root;
    while(root!=NULL){
        if (root->val > key){
            if(root->left != NULL && root->left->val==key){
                root->left=helper(root->left);
                break;
            }else{
                root=root->left;
            }
        }else{
            if(root->right != NULL && root->right->val==key){
                root->right=helper(root->right);
                break;
            }else{
                root=root->right;
            }
        }
    }
    return dummy; 
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




    TreeNode* result = deleteNode(root,4);
    inorder(result); 
}