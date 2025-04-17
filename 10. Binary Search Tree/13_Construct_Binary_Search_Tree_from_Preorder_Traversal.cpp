#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q. Construct Binary Search Tree from Preorder Traversal

Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Input: preorder = [1,3]
Output: [1,null,3]

------------------------------------------------------------------------------------
Intuition: 

brute: construct BST from given preorder and inorder
    We know that inorder of a binary search tree is always sorted. 
    Now think, I have given preorder in question and a inorder -> sort(preorder)
    So question become same as (construct a unique biary from tree from given inorder and preorder)

    So sort the preorder to get inorder and apply the logic of above question.
    preorder=[8,5,1,7,10,12]
    inorder=[1,5,7,8,10,12] sorted of preorder

Efficient: Using ranges(Q. check if tree is a BST)
    We are taking extra O(n log n) to sort the preorder so in this solution we avoid the  extra O(n log n)
    recursive solution
    we use ranges something like this (Q. check if tree is a BST)
    starting node i.e root always belong to range [INT_MIN, INT_MAX]
    root->Left will be [INT_MIN, root->val]
    root->right will be [root->val, INT_MAX]
          [INT_MIN, INT_MAX]
                   8
                 /   \
   [INT_MIN, 8] 2     10 [8, INT_MAX]

   preorder=[8,5,1,7,10,12]
   we use only upper bound. 

   1. everything left should be < 8 and everything on right should be > 8
   2. so for left upper bound will be [, 8] and u see 5,1,7 < 8 so this guys are part of left
   so if we use this property we can solve the problem 

   Note: when u are going right pass same upper bound because i should be > 5 not less than 5, i=7
   but up=5 . left of 5 everything < 5 and 7>5 so we cannot insert node 7 at right of 1. so we return null 
   now 5. ub=8 and 7<8 so we can insert 7 at right of 5.
         8
        /  
       5 ub=8
      /  \
ub=5 1    7


so whenever we calling left node->val will be our upper bound: (root->left, root->val)
and for right previous previous bound will be our upper bound: (root->right, )
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

TreeNode* buildUniqueBST(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>&mp){
    // Base case: If the start indices exceed the end indices, return NULL
    if(preStart > preEnd || inStart > inEnd){
        return NULL;
    }

    // Create a new TreeNode with value at the current preorder index
    TreeNode* root=new TreeNode(preorder[preStart]);

    // Find the index of the current root value in the inorder traversal
    int rootIndexInInorder = mp[root->val]; 

    // Calculate the number of elements in the left subtree in inorder
    int numsLeft=rootIndexInInorder - inStart; 

    // Recursively build the left subtree
    root->left=buildUniqueBST(preorder,preStart+1, preStart+numsLeft, inorder, inStart, rootIndexInInorder-1, mp);
    
    // Recursively build the right subtree
    root->right=buildUniqueBST(preorder,preStart+numsLeft+1, preEnd, inorder, rootIndexInInorder+1, inEnd, mp);

    return root;
}

TreeNode* brute_bstFromPreorder(vector<int>& preorder){
    // Time complexity : O(n log n) to sort + O(n) to create BST
    // space complexity : O(n) to store inorder

    // 1. create inorder and copy element of preorder
    vector<int>inorder(preorder.begin(), preorder.end());

    // 2. sort the inorder because inorder of BST is sorted
    sort(inorder.begin(), inorder.end());

    // 3. Create a map to store indices of elements in the inorder traversal
    map<int, int>mp;

    // 4. Populate the map with indices of elements in the inorder traversal
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }

    // 5. Call the private helper function to recursively build the tree
    TreeNode* root=buildUniqueBST(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);

    // 6. return root
    return root;
}


TreeNode* bulidTree(vector<int>& preorder, int &i, int upperBound){
    // Base case: if we ran out of element return or if curent element > than upper bound then return 
    if(i==preorder.size() || preorder[i] > upperBound){
        return NULL;
    }

    // create new node 
    TreeNode* root = new TreeNode(preorder[i]);

    // increment the pointer to next element
    i++;

    // moving to left root->val is our UB
    root->left=bulidTree(preorder, i, root->val);

    // moving to right prev upperBound is our UB
    root->right=bulidTree(preorder, i, upperBound);

    return root;
}

TreeNode* efficient_bstFromPreorder(vector<int>& preorder){
    // Time complexity : O(3n) because we are visiting each node atmost 3 time at worst case which is as good as ~ O(n) look for node 5: 1. 8->5 , 1->5 (going to left againg come back to 5), 7->5
    // space complexity : O(1)

    // note we are passing i as reference means it changes the original value in the memory 
    int i=0;
    TreeNode* root = bulidTree(preorder,i, INT_MAX);
    return root; 
}


int main(){
    vector<int>preorder={8,5,1,7,10,12};

    // brute -> 
    // TreeNode* root = brute_bstFromPreorder(preorder);

    // efficient 
    TreeNode* root = efficient_bstFromPreorder(preorder);

    inorder(root);

}