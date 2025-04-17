/* 
Maximum height/depth in binary tree

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

int maximum_depth(Node* root){
    // Time Complexity: O(N)
    // Space Complexity: O(N) worst case in case of skew tree

    if(root==NULL){
        return 0;
    }
    int lh=maximum_depth(root->left);
    int rh=maximum_depth(root->right);
    return 1+max(lh,rh);
}


int main(){
    Node* root=new Node(1);
    
    // left
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->left->left=new Node(6);


    // right
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->left->left->right=new Node(7);

    cout<<maximum_depth(root);

}