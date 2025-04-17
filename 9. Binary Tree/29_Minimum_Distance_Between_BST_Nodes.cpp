
/* 
Minimum Distance Between BST Nodes

Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

       4
    2     6
  1   3  

Input: root = [4,2,6,1,3]
Output: 1

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
int minDiffInBST(Node* root){
    if(root==NULL){
        return 0;
    }
    stack<Node*>st;
    Node* current=root;
    Node* previous=NULL;
    int mini=INT_MAX;

    while(!st.empty() || current!=NULL){
        while(current!=NULL){
            st.push(current);
            current=current->left;
        }
        current=st.top();
        st.pop();

        if(previous!=NULL){
            mini=min(mini, current->data-previous->data);
        }
        previous=current;
        current=current->right;
    }
    return mini;   
}

int main(){
    // Constructing a BST:
    //       4
    //      / \
    //     2   6
    //    / \
    //   1   3
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout<<minDiffInBST(root);

    
    
    

    

}