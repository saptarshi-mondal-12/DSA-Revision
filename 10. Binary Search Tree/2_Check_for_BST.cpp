#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Q. Check if an array represents Inorder of Binary Search tree or not
Given an array of n elements. The task is to check if it is an Inorder traversal of any Binary Search Tree or not.

Examples: 

Input: arr[] = { 19, 23, 25, 30, 45 }
Output: true
Explanation: As the array is sorted in non-decreasing order, it is an Inorder traversal of any Binary Search Tree. 

Input : arr[] = { 19, 23, 30, 25, 45 }
Output : false
Explanation: As the array is not sorted in non-decreasing order, it is not an Inorder traversal of any Binary Search Tree.

Approach:

The idea is to use the fact that the in-order traversal of Binary Search Tree is sorted. So, just check if given array is sorted or not. 

NOTE: Inorder of binary search tree is always in sorted.
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

bool isInorder(vector<int> &arr) {
    // Time complexity - O(n)
    // space complexity - O(1)
    
    int n = arr.size();
  
    // Array has one or no element
    if (n == 0 || n == 1){
        return true;
    }

    for (int i = 1; i < n; i++)
        // Unsorted pair found
        if (arr[i-1] > arr[i]){
            return false;
        }

    // No unsorted pair found
    return true;
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

    vector<int>arr={19, 23, 25, 30, 45};
    cout<<isInorder(arr)<<endl;
}