#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Longest Univalue Path

Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

The length of the path between two nodes is represented by the number of edges between them.


Example 1:
                5
              /   \
             4     5
            / \     \
           1   1     5

Input: root = [5,4,5,1,1,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 5 -> 5 -> 5).
*/

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

int solve(TreeNode *root, int parent, int &ans){
    if (root == NULL){
        return 0;
    }

    int left = solve(root->left, root->val, ans);
    int right = solve(root->right, root->val, ans);

    // The longest univalue path will cover nodes on both sides of the root.
    ans = max(ans, left + right);

    // The number of nodes will be zero if the root value isn't equal to the root.
    // Otherwise return the max of left and right nodes plus one for the root itself.
    if (root->val == parent){
        return max(left, right) + 1;
    }
    else{
        return 0;
    }
}
int longestUnivaluePath(TreeNode *root){
    // Time complexity: O(n)
    // Space complexity: O(n)
    
    int ans = 0;
    // -1 for the parent value for the tree root node.
    solve(root, -1, ans);
    return ans;
}
