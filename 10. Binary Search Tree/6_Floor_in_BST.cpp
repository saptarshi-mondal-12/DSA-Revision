#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Q. Floor in a Binary Search Tree

Given a Binary Search Tree and a key, return the floor of the given key in the Binary Search Tree.

Floor of a value refers to the value of the largest node in the Binary Search Tree that is smaller than or equal to the given key.
If the floor node does not exist, return -1.

NOTE: FLOOR: greatest value node of the BST which is smaller than or equal to x.
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


int findFloor(TreeNode* root, int key){
    // Time complexity : O(log n)
    // space complexity : O(1)
    if (root == NULL) return -1;
    
    int ans=-1;
        
    while(root!=NULL){
        // If the key is greater, update ceil and move to the right subtree beacuse e have to find greater so going to right getting more greater value
        if (root->data <= key){
            ans=root->data;
            root=root->right;
        }
    
        else{
            root=root->left;
        }
    }
    return ans;
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

    int key = 9;
    cout<<findFloor(root, key);  
}