/* 
postorder Traversal (left->right->root)

        1
    2       3
4      5|6     7

arr=[4,5,2,6,7,3,1]

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

void postorder_traversal(Node* root){
    if(root==NULL){
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<" ";
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

    postorder_traversal(root);

}