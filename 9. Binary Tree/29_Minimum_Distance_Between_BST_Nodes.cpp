#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Minimum Distance Between BST Nodes

Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

       4
    2     6
  1   3  

Input: root = [4,2,6,1,3]
Output: 1


NOTE - GIVEN BST
*/

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
    // TC- O(N)
    // SC- O(H) H- height of tree

    // Intuition - Inorder traversal of BST gives sorted order of elements.
    // So, we can find the minimum difference between the adjacent nodes in inorder traversal.
    
    if(root==NULL){
        return 0;
    }
    stack<Node*>st;
    Node* current=root;
    Node* previous=NULL;
    int mini=INT_MAX;


    // current != NULL: We are still going down the tree (left or right)
    // !st.empty(): There are nodes waiting to be processed
    // The traversal is not finished as long as either of these is true.

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