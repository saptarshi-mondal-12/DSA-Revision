#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Count No Of Nodes in a binary tree

Given a Complete Binary Tree, count and return the number of nodes in the given tree. A Complete Binary Tree is a binary tree in which all levels are completely filled, except possibly for the last level, and all nodes are as left as possible.

Input: Binary Tree: 1 2 3 4 5 6    
        1
      /  \
     2    3
    / \   /
   4   5 6    
           
Output : 6
Explanation: There are 6 nodes in this Binary Tree.

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

int brute_countTotalNodes(TreeNode* root){
    // Time complexity : O(n)
    // space complexity : O(n)

    queue<TreeNode*>q;
    q.push(root);
    int totalNodes=0;
    while (!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* curr=q.front();
            totalNodes+=1;
            q.pop();

            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
    return totalNodes;
}

int solve(TreeNode* root){
    if(root==NULL) return 0;

    int left=solve(root->left);
    int right=solve(root->right);

    return 1 + (left+right);
}

int optimal_countTotalNodes(TreeNode* root){
    // Time comlexity: O(n) where n is the total number of nodes in the binary tree. Each node is visited exactly once (checked and counted).
    // Space complexity: O(h) where h is the height of the tree.

    int noOfNodes=solve(root);
    return noOfNodes;
}


int main(){
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    

    // brute
    cout<<brute_countTotalNodes(root)<<endl;

    // optimal
    cout<<optimal_countTotalNodes(root)<<endl;
}