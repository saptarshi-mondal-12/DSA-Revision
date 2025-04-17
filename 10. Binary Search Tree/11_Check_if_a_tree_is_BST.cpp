#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q. Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Input: root = [2,1,3]
Output: true

Intuition: 
if i provide a range of a particular node then that node decide if i lie in between that range or not
For every node we will give them a range [lowerRange, higherRange].
lowerRange < x < higherRange (node have to in between this range)

          8
         /  \
        3    10
       / \     \
       2  6     14



                8 [INT_MIN, INT_MAX]
         /                        \
        3 [INT_MIN, 8]            10 [8, INT_MAX]
     /                 \               \
    2[INT_MIN, 3]      6 [8, INT_MAX]   14 [10, INT_MAX]
   
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

bool checkValidBST(TreeNode* root, long long minVal, long long maxVal) {
    if (root == NULL) return true;
    if (root->val >= maxVal || root->val <= minVal) return false;
    
    bool leftValid = checkValidBST(root->left, minVal, root->val);
    bool rightValid = checkValidBST(root->right, root->val, maxVal);
    
    return leftValid && rightValid;
}

bool isValidBST(TreeNode* root) {
    // Time complexity : O(n)
    // space complexity : O(1)

    return checkValidBST(root, LLONG_MIN, LLONG_MAX);
}



int main(){
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

    if(isValidBST(root)){
        cout<<"It is a Valid Binary Search Tree"<<endl;
    }else{
        cout<<"Not a Binary Search Tree"<<endl;
    }

}