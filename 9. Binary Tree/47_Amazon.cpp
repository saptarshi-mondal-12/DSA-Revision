#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Lowest Common Ancestor of Deepest Leaves

Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:
    The node of a binary tree is a leaf if and only if it has no children
    The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
    The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.

Input: root = [3,5,1,6,2,0,8,null,null,7,4]
           1
        /    \
       5      1
     /  \    / \
    6    2   0  8
        / \
        7  4

Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree, and it's the lca of itself.


Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.
 
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

pair<int, TreeNode*> dfs(TreeNode* root) {
    if (!root){
        // pair<int, TreeNode*> represent -> {height, TreeNode}
        return {0, nullptr};
    }

    auto left = dfs(root->left);
    auto right = dfs(root->right);

    int left_height = left.first;
    int right_height = right.first;

    if (left_height == right_height) {
        return {left_height + 1, root};  // Both subtrees have the same height, root is LCA
    } else if (left_height > right_height) {
        return {left_height + 1, left.second};  // Left subtree is deeper
    } else {
        return {right_height + 1, right.second};  // Right subtree is deeper
    }
}

TreeNode* lcaDeepestLeaves(TreeNode* root) {
    // Time complexity: O(n) - We only need to traverse all the nodes in the tree once.
    // Space complexity: O(n) - The space complexity is mainly the recursive space, with the worst case being O(n).

    
    return dfs(root).second;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    cout<<lcaDeepestLeaves(root)->data<<endl;
    
}
