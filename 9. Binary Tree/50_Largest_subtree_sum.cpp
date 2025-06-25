#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Largest subtree sum in a tree

Given a binary tree. The task is to find subtree with maximum sum in the tree and return its sum.

Input:
              1
            /   \
           2      3
          / \    / \
         4   5  6   7
Output: 28
Explanation: As all the tree elements are positive, the largest subtree sum is equal to sum of all tree elements.

Input:
               1
            /    \
          -2      3
          / \    /  \
         4   5  -6   2
Output: 7
Explanation: Subtree with largest sum is :
  -2
 /  \
4    5
Also, entire tree sum is also 7.

*/

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int solve(Node *root, int &ans){
    if (root == NULL){
        return 0;
    }

    int left = solve(root->left, ans);
    int right = solve(root->right, ans);

    int currSum = root->data + left + right;

    ans = max(ans, currSum);

    return currSum;
}

int findLargestSubtreeSum(Node *root){
    // Time complexity: O(n)

    int ans = INT_MIN;
    solve(root, ans);
    return ans;
}

int main() {
  
    // Representation of the given tree
    //          1
    //        /   \
    //      -2     3
    //      / \   / \
    //     4   5 -6  2
    Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);

    cout << findLargestSubtreeSum(root);
    return 0;
}