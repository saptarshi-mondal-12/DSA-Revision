#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* 
Q. Modify Binary tree that follows children sum property

Given a binary tree of nodes 'N', you need to modify the value of its nodes, such that the tree holds the Children sum property.

A binary tree is said to follow the children sum property if, for every node of that tree, the value of that node is equal to the sum of the value(s) of all of its children nodes( left child and the right child).

Note :
1. You can only increment the value of the nodes, in other words, the modified value must be at least equal to the original value of that node.
2. You can not change the structure of the original binary tree.
3. A binary tree is a tree in which each node has at most two children.      
4. You can assume the value can be 0 for a NULL node and there can also be an empty tree.

Input: 2 35 3 2 5 10 2
        2
      /   \
    35     10
   /   \   /  \
  2     3 5    2


output: 35 38 3 50 5 12 7 
        2
      /   \
    35     10
   /   \   /  \
  2     3 5    2


Intuition: 
The constraint is that we cannot decrease the value of any node, only increase it. Also, the structure of the binary tree cannot be changed. If we follow a bottom-up approach and try to adjust parent values based on children, we may reach a situation where the sum of children is less than parent's value, requiring us to decrease the parent's value, which is not allowed.

For e.g. 
        50
      /   \
    7       2
   /   \   /  \
  3     5 1    30

  bottom up

        50
      /   \
    8       31
   /   \   /  \
  3     5 1    30

  root: 8+31=39 -> cannot change 50 to 39, we can only increment the value not decrement 50 to 39


A key insight here is that there's no restriction on how much we can increase the value of each node. Hence, we have the flexibility to adjust the values as needed to ensure that the Children Sum Property holds true at every node in the tree. 

This means that if the sum of the values of a node's children is less than the node's value, we can simply increase the values of the children (and potentially the grandchildren and so on) until the property is satisfied. Using recursive calls, we traverse the binary tree, addressing each node and its children iteratively. At each step, we calculate the sum of the children's values and compare it with the parent node's value.

We modify the tree in such a way that the value of each node becomes the value of its left and right children. If a node is a left or right child and its parent is of a greater value, since we cannot decrease the value of the parent, we increase the value of the children nodes so that the Binary Tree follows the children sum property.

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


void changeTree(TreeNode* root){
    // Time complexity - O(n)
    // space complexity - O(h) (where h is the height of the tree, O(log n) in a balanced tree, O(n) in a skewed tree)

    if (root == NULL) {
        return;
    }

    // Calculate the sum of the values of the left and right children, if they exist.
    int child = 0;
    if (root->left) {
        child += root->left->data;
    }
    if (root->right) {
        child += root->right->data;
    }

    // Compare the sum of children with the current node's value and update
    if (child >= root->data) {
        root->data = child;
    } else {
        // If the sum is smaller, update the child with the current node's value.
        if (root->left) {
            root->left->data = root->data;
        } else if (root->right) {
            root->right->data = root->data;
        }
    }

    // Recursively call the function on the left and right children.
    changeTree(root->left);
    changeTree(root->right);

    // Calculate the total sum of the values of the left and right children, if they exist.
    int tot = 0;
    if (root->left) {
        tot += root->left->data;
    }
    if (root->right) {
        tot += root->right->data;
    }

    // If either left or right child exists, update the current node's value with the total sum.
    if (root->left or root->right) {
        root->data = tot;
    }
}

void inorder_traversal(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}


int main(){
    TreeNode* root=new TreeNode(2);
    root->left = new TreeNode(35);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    cout<<"before: ";
    inorder_traversal(root);
    cout<<endl;
    changeTree(root);
    cout<<"After: ";
    inorder_traversal(root);
}