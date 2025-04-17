/* 
Invert Binary Tree

Given the root of a binary tree, invert the tree, and return its root.

Full binary tree

Input: root = [4,2,7,1,3,6,9]

        4
    2       7
1      3|6     9


Output: [4,7,2,9,6,3,1]
        4
    7       2
9      6|3     1

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


Node* invertTree(Node* root) {
    // Time complexity: O(n)
    // Space complexity: O(1)

    if(root==NULL){
        return NULL;
    }

    // swap every node left and right 
    Node* temp=root->left;
    root->left=root->right;
    root->right=temp;

    invertTree(root->left);
    invertTree(root->right);
    return root;
}



int main(){
    
    Node* root=new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(9);

    Node* res=invertTree(root);

}