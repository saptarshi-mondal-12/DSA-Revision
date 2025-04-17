/* 
Iterative Inorder Traversal (left->root->right)

        1
    2       3
4      5|6     7

arr=[4,2,5,1,6,3,7]

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

void inorder_iterative_traversal(Node* root){
    // Time complexity - O(n)
    // space complexity - O(n)
    
    vector<int>inorder;
    if(root==NULL){
        return;
    }

    stack<Node*>st;
    Node* node=root;

    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }else{
            if(st.empty()) break;
            node=st.top();
            st.pop();
            inorder.push_back(node->data);
            node=node->right;
        }
    }

    for(int i=0;i<inorder.size(); i++){
        cout<<inorder[i]<<" ";
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

    inorder_iterative_traversal(root);

}