/* 
Check if the Binary Tree is Balanced Binary Tree
A Binary Tree is balanced if, for all nodes in the tree, the difference between left and right subtree height is not more than 1.

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int dfsHeight(Node* root){
    // Base case: if the current node is NULL, return 0 (height of an empty tree)
    if(root==NULL){
        return 0;
    }

    // Recursively calculate the height of the left subtree
    int lh=dfsHeight(root->left);

    // If the left subtree is unbalanced, propagate the unbalance status
    if(lh==-1){
        return -1;
    }

    // Recursively calculate the height of the right subtree
    int rh=dfsHeight(root->right);

    // If the right subtree is unbalanced, propagate the unbalance status
    if(rh==-1){
        return -1;
    }

    // If it's greater than 1, the tree is unbalanced,
    if(abs(rh-lh) > 1){
        return -1;
    }
    
    // Return the maximum height of left and right subtrees, adding 1 for the current node
    return 1+max(lh,rh);
}

bool isBalanced(Node* root){
    // Time Complexity: O(N)
    // Space Complexity: O(1) 

    return dfsHeight(root)!=-1;

}




int main(){
    Node* root=new Node(1);
    
    // left
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->right=new Node(6);
    root->left->right->right->right=new Node(7);

    // right
    root->right=new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<isBalanced(root);

}