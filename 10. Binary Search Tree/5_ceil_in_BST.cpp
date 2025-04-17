#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Q. Ceil in a Binary Search Tree

Given a Binary Search Tree and a key, return the ceiling of the given key in the Binary Search Tree.

Ceiling of a value refers to the value of the smallest node in the Binary Search Tree that is greater than or equal to the given key.
If the ceiling node does not exist, return -1.

Ceil: Immediate greater than key
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


int findCeil(TreeNode* root, int key){
    // Time complexity : O(log n)
    // space complexity : O(1)

    if (root == NULL) return -1;
    
    int ans=-1;
    
    while(root!=NULL){
        // If the key is smaller, update ceil and move to the left subtree beacuse e have to find Immediate greater so going to left getting more smaller value
        if (key <= root->data ){
            ans=root->data;
            root=root->left;
        }

        // If the key is greater, move to the right subtree
        else if(key > root->data ){
            root=root->right;
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

    int key = 8;
    cout<<findCeil(root, key);  
}