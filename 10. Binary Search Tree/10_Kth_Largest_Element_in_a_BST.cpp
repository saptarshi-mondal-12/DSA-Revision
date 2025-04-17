#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q. Kth Larget Element in a BST

Given the root of a binary search tree, and an integer k, return the kth Larget value (1-indexed) of all the values of the nodes in the tree.

         (8)
       /     \
     (3)     (10)
     / \       \
   (2) (6)     (14)
   /   / \     /
 (1) (4) (7) (13)
       \
       (5)


Intuition: 
Algorithm for Kth Largest Element:

Step 1: Perform reverse inorder traversal from the root node. At every visited node, increment a counter variable to keep track of visited nodes. Traverse the right subtree, then current node then left subtree.

Step 2: When the counter reaches K, store the value of the current node as the Kth smallest.
Step 2: Return this value as the Kth largest.

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

void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int brute_kthLargest(TreeNode* root, int k) {
    // Time complexity : O(n)
    // space complexity: O(n) + O(n)


    // Vector to store the elements of the BST
    vector<int>nums;
    stack<TreeNode*>st;

    // Perform inorder traversal
    while(true){
        if(root!=NULL){
            st.push(root);
            root=root->left;
        }else{
            if(st.empty()){
                break;
            }else{
                root=st.top();
                st.pop();
                nums.push_back(root->val);
                root=root->right;
            }
        }
    }
    // Calculate Kth largest
    int n=nums.size();
    int kthLargest=nums[n-k];
    return kthLargest;
}

void reverseInorder(TreeNode* root, int& counter, int k, int& kthLargest) {
    if (root==NULL || counter >= k) return;

    // Traverse right subtree
    reverseInorder(root->right, counter, k, kthLargest);

    // Increment counter after visiting left subtree
    counter++;

    // Check if current node is the Kth largest
    if (counter == k) {
        kthLargest = root->val;
        return;
    }

    // Traverse left subtree if Kth largest is not found yet
    reverseInorder(root->left, counter, k, kthLargest);
}


int optimal_kthLargest(TreeNode* root, int k) {
    // Time complexity : O(n)
    // space complexity : O(1)

    int kthLargest=-1;
    // Counter to track visited nodes
    int counter = 0; 
    reverseInorder(root, counter, k, kthLargest);
    return kthLargest;
}



int main(){
    TreeNode* root = new TreeNode(8);

    // Left subtree
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->left->right = new TreeNode(5);  
    root->left->right->right = new TreeNode(7);

    // Right subtree
    root->right = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    inorder(root);
    cout<<endl;


    int k=2;

    // brute
    cout<<brute_kthLargest(root, k)<<endl;

    // optimal
    cout<<optimal_kthLargest(root, k);
}