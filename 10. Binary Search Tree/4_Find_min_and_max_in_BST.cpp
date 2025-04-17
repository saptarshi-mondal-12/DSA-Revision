#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Q. Find Minimum and Maximum element in BST
Given the root of a Binary Search Tree. The task is to find the minimum and maximum valued element in this given BST.

Approach: 

Finding Minimum:
    Start from the root and keep moving left until we reach the leftmost node.
    That node contains the minimum value.

Finding Maximum:
    Start from the root and keep moving right until we reach the rightmost node.
    That node contains the maximum value.
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

void findMinMax(TreeNode* root){
    // Time complexity : O(log n)
    // space complexity : O(1)
    
    if (!root){
        cout <<"BST is empty!"<< endl;
    }

    // Finding Minimum (Leftmost node)
    TreeNode* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    int minimum = temp->data;

    // Finding Maximum (Rightmost node)
    temp = root;
    while (temp->right != NULL){
        temp = temp->right;
    }
    int maximum = temp->data;

    // Printing results
    cout << "Minimum Element: " << minimum << endl;
    cout << "Maximum Element: " << maximum << endl;
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

    findMinMax(root);  
}