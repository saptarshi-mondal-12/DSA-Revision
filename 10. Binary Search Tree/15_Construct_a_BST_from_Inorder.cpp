#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Q. Construct a Binary Search Tree from Inorder

Given a vector inorder. Construct a binary search tree from given inorder. 
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

TreeNode* bulidTree(vector<int>& inorder, int start, int end){
    if(start>end){
        return NULL;
    }

    // Find mid to create our new node
    int mid=(start+end)/2;

    // creating new node
    TreeNode* root=new TreeNode(inorder[mid]);

    root->left=bulidTree(inorder, start, mid-1);
    root->right=bulidTree(inorder, mid+1, end);

    return root;
}

TreeNode* construct_Inorder_to_BST(vector<int>& inorder){
    TreeNode* newTree = bulidTree(inorder, 0, inorder.size()-1);
    return newTree;
}


int main(){
    vector<int>inOrder={1,2,3,4,5,6,7,8,9,10,11,12};
    TreeNode* root = construct_Inorder_to_BST(inOrder);
    inorder(root);
}