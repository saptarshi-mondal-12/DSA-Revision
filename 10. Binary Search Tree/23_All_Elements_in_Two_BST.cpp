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



// Brute soln ----------------------------------------------------------------------------------

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



// Optimal Soln-----------------------------------------------------------------------------------


void inorderTraversal(TreeNode* root ,vector<int>& inorderContainer){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left, inorderContainer);
    inorderContainer.push_back(root->val);
    inorderTraversal(root->right, inorderContainer);
}

vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
    // Time complexity: O(n+m)
    // space complexity: O(n+m)

    int n=nums1.size();
    int m=nums2.size();

    vector<int>result;

    int i=0, j=0;
    while(i<n && j<m){
        if(nums1[i] <= nums2[j]){
            result.push_back(nums1[i]);
            i++;
        }else{
            result.push_back(nums2[j]);
            j++;
        }
    }
    while(i<n){
        result.push_back(nums1[i]);
        i++;
    }
    while(j<m){
        result.push_back(nums2[j]);
        j++;
    }
    return result;     
}

vector<int> optimal_getAllElements(TreeNode *root1, TreeNode *root2) {
    // Time complexity: O(n+m) + O(m+n)
    // Space complexity: O(m+n) 

    /*Intuition: 
    1. traverse both the tree and store their value in 2 seperate vector.
    2. use merge function to merge the both sorted array.
    */

    // 1. Traverse tree to store element 
    vector<int>inorder1;
    vector<int>inorder2;
    inorderTraversal(root1, inorder1);
    inorderTraversal(root2, inorder2);

    // 2. merge both sorted array to get a sorted list
    vector<int>mergeArray = merge(inorder1, inorder2);

    // return new merge tree
    return mergeArray;
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
    vector<int>result=brute_getAllElements(root1, root2);
    for(auto it: result){
        cout<<it<<" ";
    }
    cout<<endl;


    // optimal
    vector<int> result1 = optimal_getAllElements(root1, root2);
    for (int val : result1) {
        cout << val << " ";
    }

}