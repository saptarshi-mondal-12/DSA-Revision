#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Q. Predecessor and Successor
You are given root node of the BST and an integer key. You need to find the in-order successor and predecessor of the given key. If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

Input: root[] = [8, 1, 9, N, 4, N, 10, 3, N, N, N]
key = 8
Output: 4 9
Explanation: In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.


Input: root[] = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4, N, N]
key = 11
Output: 10 -1
Explanation: In given BST, the inorder predecessor of 11 is 10 whereas it does not have any inorder successor.
*/

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};


void findPreSuc(TreeNode* root, int key){
    // Time complexity : O(H) height of tree
    // space complexity : O(1)

    TreeNode* dummy1=root;
    TreeNode* dummy2=root;

    // Finding successor
    int successor=-1;
    while(dummy1!=NULL){
        if(key >= dummy1->val){
            dummy1=dummy1->right;
        }else{
            successor=dummy1->val;
            dummy1=dummy1->left;
        }
    }
    // immediate greater of key
    cout<<"Successor of "<<key<<" is: "<<successor<<endl;
        
    
    // Finding predecessor
    int predecessor=-1;
    while(dummy2!=NULL){
        if(dummy2->val < key){
            predecessor=dummy2->val;
            dummy2=dummy2->right;
        }else{
            dummy2=dummy2->left;
        }
    }
    // immediate greater of key
    cout<<"Predecessor of "<<key<<" is: "<<predecessor<<endl;
}



int main(){
    TreeNode* root = new TreeNode(8);
    
    // Left subtree
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    // Right subtree
    root->right = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    int key = 8;
    findPreSuc(root, key);  
}