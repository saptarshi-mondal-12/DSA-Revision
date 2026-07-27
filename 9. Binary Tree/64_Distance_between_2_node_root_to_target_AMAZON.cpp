// Distance between 2 node in a binary tree - root to target - AMAZON 2026

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int findDistance(TreeNode*root, int target){
    if(root->data == target) return 0;
    queue<TreeNode*>q;
    q.push(root);
    int level = 0;
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->data == target){
                return level;
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        level++;
    }
    return -1;
}



int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    int target = 5;
    int ans = findDistance(root,target);
    cout<<ans<<endl;
}