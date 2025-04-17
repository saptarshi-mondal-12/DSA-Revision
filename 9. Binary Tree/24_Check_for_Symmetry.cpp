/* 
Check for symmetry tree (mirror)


        1
    2       2
3      4|4     3

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

bool checkSymmetric(Node* left, Node* right){
    if(left==NULL || right==NULL){
        return left==right;
    }
    if(left->data!=right->data){
        return false;
    }
    return (checkSymmetric(left->left, right->right) && checkSymmetric(left->right, right->left));
}


bool isSymmetric(Node* root) {
    // Time complexity: O(n)
    // Space complexity: O(n)

    // (root->left)    | (root->right)
    // root left right | root right left

    if(root==NULL){
        return true;
    }
    return checkSymmetric(root->left,root->right);   
}



int main(){
    
    Node* root=new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right = new Node(2);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    cout<<isSymmetric(root);

}