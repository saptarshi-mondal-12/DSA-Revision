#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Binary Tree Cameras - AMAZON

You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.


* = camera at current node



Example 1:
         1
        /*\
       2   3


Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.


Example 2:
       1
      /
     2
     *
    /
   3
  /
 4
  *
   \
    5

Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.

Intuition---------------------------------------------------------------

We are placing cameras on tree nodes, and each camera can monitor:
    the node itself,
    its parent,
    and its immediate children.



We use post-order traversal (left → right → node) to make decisions from the bottom-up.
For each node, we classify its state as:

    -1: Node needs a camera
    0: Node has a camera
    1: Node is covered (by one of its children)

🔄 How It Works
When visiting a node: First, recursively check its left and right children.
Then:
    If any child needs a camera (-1), we must place a camera at this node.
    If any child has a camera (0), this node is already covered, so return 1.
    If both children are covered (1), this node needs a camera, so return -1.
    Finally, after the whole traversal, if the root is still not covered, we place one last camera at the root.

🧠 Why Bottom-Up?
We want to avoid placing cameras on leaves, because their coverage is limited.
Instead, it’s better to place cameras on parents of leaves, which can cover more nodes.


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

// Building tree:
    //         0
    //        / \
    //       0   0
    //          / \
    //         0   0

int cameraRequire(TreeNode *root, int &camera){
    if (root == NULL){
        return 1;
    }

    int left = cameraRequire(root->left, camera);
    int right = cameraRequire(root->right, camera);

    // If anyone of my child (left or right) require camera
    if (left == -1 || right == -1){
        camera++;
        return 0;
    }

    // If anyone of my child (left or right) have camera, then i am cover. so return 1
    if (left == 0 || right == 0){
        return 1;
    }

    return -1;
}
int minCameraCover(TreeNode *root){
    // Time: O(N) — Each node is visited once.
    // Space: O(H) — Due to recursion stack, where H = height of tree (O(log N) for balanced, O(N) for skewed).

    // -1 : I need a camera
    //  0 : I have a camera
    //  1 : I am covered

    int camera = 0;
    if (cameraRequire(root, camera) == -1){
        camera++;
    }
    return camera;
}

int main(){
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(0);

    cout << "Minimum Cameras Needed: " << minCameraCover(root) << endl;
}
