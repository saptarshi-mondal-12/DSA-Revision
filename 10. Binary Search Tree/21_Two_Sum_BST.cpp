#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Q. Two Sum IV - Input is a BST

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
        5
       / \
      3   6
     / \   \ 
    2   4   7
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

void inorderTraversal(TreeNode* root, vector<int>&inorder){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
}

bool brute_findTarget(TreeNode* root, int k){
    // Time complexity: O(n) + O(n)
    // space complexity: O(n)

    /*Intuition: We store the element of BST into a vector and perform a two pointer apprach (similarly like 2 sum).
        1. Store BST in a vector. 
        2. Perform 2 sum concept. (vector is sorted obviously)
    */

    vector<int>inorder;
    inorderTraversal(root, inorder);

    int i=0, j=inorder.size()-1;
    while (i<j){
        int total=inorder[i] + inorder[j];
        if (total == k){
            return true;
        }
        else if (total > k){
            j--;
        }else{
            i++;
        }
    }
    return false;
}


// -----------------------------------------------------------------

TreeNode* findPredecessor(TreeNode* root, TreeNode* key){
    // Time complexity : O(log n) we traverse down the tree only once, choosing left or right at each step.So, we visit at most H nodes (H = height of the tree).
    // space complexity : O(1)

    TreeNode* curr = root;
    TreeNode* predecessor = NULL;

    while (curr) {
        if (curr->val < key->val) {
            predecessor = curr;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    return predecessor; // largest but smaller than key
}


TreeNode* findSuccessor(TreeNode* root, TreeNode* key){
    // Time complexity : O(log n) we traverse down the tree only once, choosing left or right at each step.So, we visit at most H nodes (H = height of the tree).
    // space complexity : O(1)
    
    TreeNode* dummy1=root;

    TreeNode* curr = root;
    TreeNode* successor = NULL;

    while (curr) {
        if (curr->val > key->val) {
            successor = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return successor; // smallest but greater than key
}



bool optimal_findTarget(TreeNode* root, int k){
    // Time complexity: O(n log n)
    // space complexity: O(1)

    if (root == NULL) {
        return false;
    }

    // Moving left pointer to extreme left (leftmost node) - i.e at minimum node
    TreeNode* start = root;
    while (start->left != NULL) {
        start = start->left;
    }

    // Moving right pointer to extreme right - i.e at maximum node
    TreeNode* end = root;
    while (end->right != NULL) {
        end = end->right;
    }
    while (start != NULL && end != NULL && start != end) {
        int sum = start->val + end->val;
        if (sum > k) {
            end = findPredecessor(root, end);
        } else if (sum < k) {
            start = findSuccessor(root, start);
        } else {
            return true;
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

    
    // 1. brute 
    int k=9;
    cout<<brute_findTarget(root,k)<<endl;


    // 2. optimal solution
    cout<<optimal_findTarget(root,k)<<endl;
}