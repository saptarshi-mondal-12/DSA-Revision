/* 
Iterative preorder Traversal (root->left->right)

        1
    2       3
4      5|6     7

arr=[1, 2, 4, 5, 3, 6, 7 ]

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

void preorder_iterative_traversal(Node* root){
    // Time complexity - O(n)
    // space complexity - O(n)
    
    vector<int>preorder;
    if(root==NULL){
        return;
    }

    stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        preorder.push_back(root->data);
        if(root->right!=NULL){
            st.push(root->right);
        }
        if(root->left!=NULL){
            st.push(root->left);
        }
    }

    for(int i=0;i<preorder.size(); i++){
        cout<<preorder[i]<<" ";
    }

}


int main(){
    Node* root=new Node(1);
    
    // left
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    // right
    root->right=new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    preorder_iterative_traversal(root);

}