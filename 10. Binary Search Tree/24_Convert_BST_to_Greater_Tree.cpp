#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Q. Convert BST to Greater Tree

Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

                4(30)
            /            \ 
        (36)1             6(21)
          /   \            /  \
    (36)0      2(35)  (30)5    7(15)
                  \             \
               (33)3             8(8)

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


void inorder(TreeNode* root, int &totalSum){
    if(root==NULL){
        return;
    }
    inorder(root->left, totalSum);
    totalSum+=root->val;
    inorder(root->right, totalSum);
}
void modify_Value(TreeNode* root, int &totalSum){
    if(root==NULL){
        return;
    }
    modify_Value(root->left, totalSum);
    totalSum-=root->val;
    root->val= root->val+totalSum;
    modify_Value(root->right, totalSum);
}
TreeNode* mySolution_convertBST(TreeNode* root) {
    // Time complexity: O(n) + O(n)
    // Space complexity: O(n) recursion stack
    int totalSum=0;
    inorder(root, totalSum);
    modify_Value(root, totalSum);
    return root;
}


// -------------------------------------------------------------------------------

void solve(TreeNode *root,int &total){
    if(root == NULL){
        return ;
    }

    // First traversing right
    solve(root->right,total);

    // changeing value
    total+=root->val;
    root->val=total;

    // Second traversing left
    solve(root->left,total);
}  
TreeNode* optimal_convertBST(TreeNode* root) {
    // Time complexity: O(n)
    // Space complexity: O(n) recursion stack

    /* Intuition: First observe give example carefully
    
    1. First traverse right sub tree(having greater value then node) and then left sub tree(having lesser value then node)
    
    2. Take a variable named as total which store sum of node values up to which we traverse and assign total value to root value.
    */

    int total=0;
    solve(root,total);
    return root;    
}


int main(){
    TreeNode* root1 = new TreeNode(8);
    
    // Left subtree
    root1->left = new TreeNode(3);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(6);
    root1->left->right->left = new TreeNode(4);
    root1->left->right->right = new TreeNode(7);

    // Right subtree
    root1->right = new TreeNode(10);
    root1->right->right = new TreeNode(14);
    root1->right->right->left = new TreeNode(13);



 
    // My solution
    // TreeNode* resultNode = mySolution_convertBST(root1);
    // inorder(resultNode);


    // optimal
    TreeNode* resultNode = optimal_convertBST(root1);
    inorder(resultNode);
}