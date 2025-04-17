#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q. Kth Smallest Element in a BST

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

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

brute: 
    A brute force approach would be to traverse the BST using an inorder traversal which will get us an array containing all node values in the ascending sorted order. Following this traversal, we retrieve the Kth smallest element by accessing the element at index k-1 in the array considering array indices start from 0. 

    NOTE : Inorder Traversal of BST is always in sorted order

Optimal:
A more efficient approach for finding the K-th smallest in a Binary Search Tree (BST) without using extra space would involve an optimised traversal technique directly targeting the K-th elements without storing all elements in an array. We maintain a counter variable to track the number of visited nodes, stopping when the Kth element is found in each traversal.

Algorithm for Kth Smallest Element:

Step 1: Perform inorder traversal from the root node. At every visited node, increment a counter variable to keep track of visited nodes. Inorder Traversal: Traverse the left subtree, then current node then right subtree.

Step 2: When the counter reaches K, store the value of the current node as the Kth smallest.

Step 3: Return this value as the Kth smallest.
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

int brute_kthSmallest(TreeNode* root, int k) {
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
    // Calculate Kth smallest
    int kthSmallest=nums[k-1];
    return kthSmallest;
}

void inorder(TreeNode* root, int& counter, int k, int& kSmallest) {
    if (root==NULL || counter >= k) return;

    // Traverse left subtree
    inorder(root->left, counter, k, kSmallest);

    // Increment counter after visiting left subtree
    counter++;

    // Check if current node is the Kth smallest
    if (counter == k) {
        kSmallest = root->val;
        return;
    }

    // Traverse right subtree if
    // Kth smallest is not found yet
    inorder(root->right, counter, k, kSmallest);
}
int optimal_kthSmallest(TreeNode* root, int k) {
    // Time complexity : O(n)
    // space complexity : O(1)

    int kSmallest=-1;
    // Counter to track visited nodes
    int counter = 0; 
    inorder(root, counter, k, kSmallest);
    return kSmallest;
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


    // brute
    cout<<brute_kthSmallest(root, 9)<<endl;

    // optimal
    cout<<optimal_kthSmallest(root, 9);
}