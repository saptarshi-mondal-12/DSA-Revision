#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Check if a given Binary Tree is Sum Tree. - AMAZON 2025 

Given a binary tree, the task is to check if it is a Sum Tree. A Sum Tree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is Sum Tree and the sum of an empty tree can be considered as 0. A leaf node is also considered a Sum Tree.

Input: 

    26
    /\      2nd level 4+6 = 10 | 3+0 = 3
  10  3     1st level 10+10 = 20 | 3+3 = 6 
  /\   \    0th level 20+6 = 26
 4  6   3

Output: Valid
*/

class Node{
    public:
    int data ;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int checkSumTree(Node* root, bool &ans){
    if (root == NULL) return 0;
    
    if (root->left == NULL && root->right == NULL) {
        return root->data; // leaf node
    }
    
    int left = checkSumTree(root->left, ans);
    int right = checkSumTree(root->right, ans);
    
    // If current node does not satisfy sum tree property, mark false
    if (root->data != left + right) {
        ans = false;
    }
    
    return left + right + root->data;
}


bool isValid(Node* root){
    // Time Complexity: O(n)
    // Space Complexity: O(h) h=height of tree


    bool ans = true;
    checkSumTree(root, ans);
    return ans;
}

int main(){
    Node* root = new Node(26);
    root->left=new Node(10);
    root->right=new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    if(isValid(root)){
        cout<<"Valid"<<endl;
    }else{
        cout<<"Invalid"<<endl;
    }
}