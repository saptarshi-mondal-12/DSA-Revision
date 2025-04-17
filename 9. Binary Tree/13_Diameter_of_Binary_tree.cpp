/* 
Diameter Binary Tree
The Diameter of a Binary Tree is the longest distance between any two nodes of that tree. This path may or may not pass through the root.
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



int calculateHeight(Node* root, int& diameter){
    if(root==NULL) return 0;

    int lh=calculateHeight(root->left, diameter);
    int rh=calculateHeight(root->right, diameter);

    // Calculate the diameter at the current node and update the global variable
    diameter=max(diameter, lh+rh);

    // Return the height of the current subtree
    return 1+max(lh, rh);
}

int optimal_diameterOfBinaryTree(Node* root){
    // Time complexity - O(n)
    // space complexity - O(1)

    int diameter=0;
    calculateHeight(root, diameter);
    return diameter;
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



    // optimal
    cout<<optimal_diameterOfBinaryTree(root)<<endl;



    

}