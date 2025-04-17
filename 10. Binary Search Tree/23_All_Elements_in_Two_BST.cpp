#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Q. All Elements in Two Binary Search Trees

Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
    2         1
   / \       / \
  1   4     0   3

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


void inorder(TreeNode* root, vector<int>&result){
    if(root==NULL){
        return;
    }
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}
vector<int> brute_getAllElements(TreeNode* root1, TreeNode* root2) {
    // Time complexity: O(m) + O(n) + O((m+n)log(m+n))
    // Space complexity: O(m+n)
    vector<int>result;

    inorder(root1, result);
    inorder(root2, result);

    sort(result.begin(), result.end());
    return result;
}


// --------------------------------------------------------------------

vector<int> optimal_getAllElements(TreeNode* root1, TreeNode* root2) {
    // TC= O(m+n)
    // SC = O(m+n) for the stack - in the worst case, we may need to store the entire tree there.


    vector<int> res;
    stack<TreeNode*> s1, s2;

    while (root1 || root2 || !s1.empty() || !s2.empty())
    {
        while (root1 != NULL)
        {
            s1.push(root1);
            root1 = root1->left;
        }
        while (root2 != NULL)
        {
            s2.push(root2);
            root2 = root2->left;
        }
        if (s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val))
        {
            root1 = s1.top();
            s1.pop();
            res.push_back(root1->val);
            root1 = root1->right;
        }
        else
        {
            root2 = s2.top();
            s2.pop();
            res.push_back(root2->val);
            root2 = root2->right;
        }
    }
    return res;
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


    TreeNode* root2 = new TreeNode(20);
    root2->left = new TreeNode(10);
    root2->right = new TreeNode(30);


    // brute
    // vector<int>result=brute_getAllElements(root1, root2);


    // optimal
    vector<int>result=optimal_getAllElements(root1, root2);
    for(auto it: result){
        cout<<it<<" ";
    }

}