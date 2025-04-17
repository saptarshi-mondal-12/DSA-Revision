/* 
Check if 2 tree are identical or not 
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
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



bool isSameTree(Node* root1, Node* root2){
    // Time complexity - O(n)
    // space complexity - O(1)

    // If both root are NULL, they are identical
    if(root1==NULL && root2==NULL) return true;

    // If only one of the root is NULL, they are not identical
    if( root1== NULL || root2==NULL) return false;

    // Check if the current nodes have the same data value and recursively check their left and right subtrees
    return ((root1->data == root2->data) && isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right));

}





int main(){

    // 1 root
    Node* root1=new Node(1);
    // left
    root1->left=new Node(2);
    root1->left->left=new Node(4);
    root1->left->right=new Node(5);

    // right
    root1->right=new Node(3);
    root1->right->left=new Node(6);
    root1->right->right=new Node(7);


    // 2 root 
    Node* root2=new Node(1);
    
    // left
    root2->left=new Node(2);
    root2->left->left=new Node(4);
    root2->left->right=new Node(5);

    // right
    root2->right=new Node(3);
    root2->right->left=new Node(6);
    root2->right->right=new Node(7);


    
    cout<<isSameTree(root1, root2)<<endl;


}