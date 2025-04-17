#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Q. Search in a Binary Search Tree

Given a Binary Search Tree and a key value return the node in the BST having data equal to ‘key’ otherwise return false.

Input:Binary Search Tree: [8, 5, 12, 4, 7, 10, 14, -1, -1, 6, -1] 
Key = 10
Output=true

*/

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

bool searchBST(TreeNode* root, int val){
    // Time Complexity: O(log2N) 
    // where N is the number of nodes in the Binary Search Tree. In the best case scenario, where the tree is balanced, the time complexity is the height of the tree ie. log2N. In the worst-case scenario, where the tree is degenerate (linear), the time complexity becomes O(n), as it would require traversing all nodes along the path from the root to the leaf.

    // Space Complexity: O(1)

    while(root!=NULL){
        // check If the root's data is equal to val, return true. 
        if (root->data==val){
            return true;
        }
        // If val is greater, move right.
        else if(root->data < val){
            root=root->right;
        }

        // If val is smaller, move left.
        else if(root->data > val){
            root=root->left;
        }
    }
    return false;
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

    int target=10;
    cout<<searchBST(root, target);

    
}