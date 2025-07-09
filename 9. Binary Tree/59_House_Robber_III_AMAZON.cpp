#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. House Robber III | Amazon

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.



Example 1:
                3
              /   \
             2     3
             \      \
              3      1


Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.



Example 2:
                3
              /   \
             4     5
            / \     \
           1   3     1


Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.



Intuition: ----------------------------------------------------------------------------------

It returns a pair<int, int>:
    first → maximum money when not robbing this node
    second → maximum money when robbing this node 

So, when you do:
    auto left = dfs(root->left);
    auto right = dfs(root->right);

You get:
    left.first: max money from left subtree when left is NOT robbed
    left.second: max money from left subtree when left is robbed

Similarly for right

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

pair<int, int> solve(TreeNode *root){
    if (root == NULL){
        return {0, 0};
    }

    auto left = solve(root->left);
    auto right = solve(root->right);

    int rob = root->val + left.first + right.first;
    int notRob = max(left.first, left.second) + max(right.first, right.second);

    return {notRob, rob};
}
int rob(TreeNode *root){
    // Time complexity: O(n) each node is visited once
    // Space complexity: O(h)

    pair<int, int> res = solve(root);
    int ans = max(res.first, res.second);
    return ans;
}

int main(){

}
