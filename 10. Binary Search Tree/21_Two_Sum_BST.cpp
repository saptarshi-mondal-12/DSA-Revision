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

bool findTarget(TreeNode* root, int k){
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

class BSTIterator {   
public:
    // Space complexity: twice of height - 2*O(h)

    // using 2 seperete stack for storing next and before 
    stack<TreeNode*>stackNext;
    stack<TreeNode*>stackBefore;
    
    BSTIterator(TreeNode* root) {
        // function to push all left element of curr node
        pushAllNext(root);
    
        // function to push all right element of curr node
        pushAllBefore(root);
    }
        
    // return the next smallest number 
    int next() {
        TreeNode* curr=stackNext.top();
        stackNext.pop();
        pushAllNext(curr->right);
        return curr->val;  
    }
    
    // return the next smallest number for eg. we are at node 7. 
    // pushing all right to stack is [5,6,7] return 7 and pop. now stack look like [5,6] (i.e i write next smallest number)
    int before() {
        TreeNode* curr=stackBefore.top();
        stackBefore.pop();
        pushAllBefore(curr->left);
        return curr->val;  
    }
        
    // function for pushing all left of a current node
    void pushAllNext(TreeNode* node){
        // pushing all left
        while(node!=NULL){
            stackNext.push(node);
            node=node->left;
        }
    }
    
    // function for pushing all right of a current node
    void pushAllBefore(TreeNode* node){
        // Pushing all right
        while(node!=NULL){
            stackBefore.push(node);
            node=node->right;
        }
    }
};

bool optimalfindTarget(TreeNode* root, int k){
    // Time complexity: O(n)
    // space complexity: 2 x O(h) - one for next and one for before so twice of height
    
    /* 
    Intuition: 

    We use the concept of a BST Iterator, which allows us to retrieve elements in ascending order whenever we call `next()`.   
        
    Q. But How do we implement `before()` to get elements in descending order?**  
    Ans: The answer is simple—just as `next()` pushes all left children, `before()` should push all right children, effectively doing the opposite of `next()`.  

    Example inorder traversal:  
    inorder = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]  

    To optimize space complexity (better than O(n)), we initialize two pointers:  
        i = next() = (logically pointing to the first element, i.e., 1)  
        j = before() = (logically pointing to the last element, i.e., 11)  

    By doing this we ca optimize the space complexity which is better than O(n)
    */

    BSTIterator a(root);
        int i=a.next();
        int j=a.before();
        while (i < j){
            int total = i+j;
            // if totalSum equal to k return true
            if(total == k){
                return true;
            }else if (total > k){ // if totalSum is greater reduce the value  
                j=a.before();
            }else{ // if totalSum is smaller increase the value  
                i=a.next();
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
    cout<<findTarget(root,k)<<endl;


    // 2. optimal solution
    cout<<optimalfindTarget(root,k)<<endl;
}