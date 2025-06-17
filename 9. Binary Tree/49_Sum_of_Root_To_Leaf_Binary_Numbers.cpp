#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/* Q. Sum of Root To Leaf Binary Numbers

You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.

          1
        /   \
       0     1
      / \   / \
     0   1 0   1

 
Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
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


int solve(Node* root, int currentSum){
    if (!root) return 0;

    // Build number: multiply current sum by 2 and add node's value
    currentSum = currentSum * 2 + root->data;

    // If it's a leaf node
    if (!root->left && !root->right) {
        return currentSum;
    }

    // Recurse left and right
    return solve(root->left, currentSum) + solve(root->right, currentSum);
}

int sumRootToLeaf(Node* root) {
    return solve(root, 0);
}



int main(){

    // 1 root
    Node* root1=new Node(1);
    // left
    root1->left=new Node(0);
    root1->left->left=new Node(0);
    root1->left->right=new Node(1);

    // right
    root1->right=new Node(1);
    root1->right->left=new Node(0);
    root1->right->right=new Node(1);


    cout<<sumRootToLeaf(root1);
}