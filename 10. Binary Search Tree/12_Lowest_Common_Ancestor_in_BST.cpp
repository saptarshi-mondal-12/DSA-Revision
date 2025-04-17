#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q. . Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Intuition: 
The Lowest Common Ancestor (LCA) of two nodes p and 𝑞 in a Binary Search Tree (BST) is the lowest (deepest) node in the tree that has both p and 𝑞 as its descendants.
        6
       / \
      2   8
     / \  / \
    0   4 7 9
       / \
      3   5

If p=2 and q=8, the LCA is 6 because it's the lowest node that has both 2 and 8 as descendants.
If p=2 and q=4, the LCA is 2 because node 2 itself is an ancestor of 4.

Since we are given a Binary Search Tree (BST), we can exploit its properties:

Left Subtree Property: All values in the left subtree of a node are smaller than the node's value.
Right Subtree Property: All values in the right subtree are greater than the node's value.

Approach Used in Your Code
1. Base Case:
    If root == NULL, return NULL since there's no ancestor.

2. Compare root->val with p->val and q->val
    If both p and q are greater than root->val, then LCA must be in the right subtree.
    If both p and q are smaller than root->val, then LCA must be in the left subtree.

3. If root is Between p and q 
    If one value is smaller and the other is greater (or one is equal to root), then root itself is the LCA.
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    // Time complexity : O(H) height of tree
    // space complexity : O(1)

    // Base case: if the root is null, return null (no ancestor found)
    if(root==NULL){
        return NULL;
    }

    // Store the current node's value
    int curr=root->val;

    // If both p and q are greater than current node, search in the right subtree
    if(curr < p->val && curr < q->val){
        return lowestCommonAncestor(root->right, p, q);
    }

    // If both p and q are smaller than current node, search in the left subtree
    if(curr > p->val && curr > q->val){
        return lowestCommonAncestor(root->left, p, q);
    }

    // If neither of the above cases match, the current node is the LCA
    return root;     
}


TreeNode* iterative_lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Time complexity : O(log n) 
    // space complexity : O(1)

    while (root) {
        int curr = root->val;

        // If both p and q are greater than root, move right
        if (curr < p->val && curr < q->val) {
            root = root->right;
        }
        // If both p and q are smaller than root, move left
        else if (curr > p->val && curr > q->val) {
            root = root->left;
        }
        // Otherwise, we found the LCA
        else {
            return root;
        }
    }
    // In case no LCA is found (shouldn't happen in a valid BST)
    return NULL; 
}


int main(){
    TreeNode* root = new TreeNode(8);
    /*
        (8)
       /     \
     (3)     (10)
     / \       \
   (2) (6)     (14)
   /   / \     /
 (1) (4) (7) (13)
       \
       (5)
       
    */

    // Left subtree
    root->left = new TreeNode(3);
    TreeNode* p = root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->left->right = new TreeNode(5);  
    TreeNode* q = root->left->right->right = new TreeNode(7);

    // Right subtree
    root->right = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    // common root of 2 and 7 is 3


    // Recursive solution 
    TreeNode* LCA = lowestCommonAncestor(root, p, q);
    cout<<LCA->val<<endl;


    // iterative solution more efficient
    TreeNode* LCA = iterative_lowestCommonAncestor(root, p, q);
    cout<<LCA->val<<endl;
}