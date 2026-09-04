#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Max Path Sum Between Two Leaves - AMAZON 2026

Given the root of a binary tree, where each node contains an integer value, find the maximum possible path sum between any two leaf nodes. If the tree has fewer than two leaf nodes, return -1.

Input: root = [1,2,3,4,5,6,7]
output: 18
Explanation: The maximum path sum between two leaves is 4 -> 2 -> 1 -> 3 -> 7 = 18.

Follow up: Can you print the path as well?

Ans: Yes, we can modify the solution to keep track of the nodes in the maximum path and print them.

*/

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int solve(Node* root, int &result){
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }

    int left = solve(root->left, result);
    int right = solve(root->right, result);

    if(root->left && root->right){
        result = max(result, root->data+left+right);
        return root->data + max(left,right);
    }

    // if root has only left child - try on skew tree
    if(root->left){
        return root->data + left;
    }
    return root->data + right;
}

int MaximumPathSumBetween2Leaves(Node* root){

    if(root == NULL){
        return 0;
    }
    
    int result = 0;
    solve(root, result);
    return result;
}

int main(){
    /*
            1
        2       3
      4   5   6   7
    
    */


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<MaximumPathSumBetween2Leaves(root)<<endl;

    return 0;
}
