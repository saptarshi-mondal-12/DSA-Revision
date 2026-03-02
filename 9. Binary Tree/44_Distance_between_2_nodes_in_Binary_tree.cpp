#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Find distance between any 2 node in binary tree
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

TreeNode* findLCA(TreeNode* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (root->val == n1 || root->val == n2) return root;

    TreeNode* leftLCA = findLCA(root->left, n1, n2);
    TreeNode* rightLCA = findLCA(root->right, n1, n2);

    if(leftLCA==NULL){
        return rightLCA;
    }else if(rightLCA==NULL){
        return leftLCA;
    }else{
        // if both (lh & rh) are not null means we get our LCA, so return root
        return root;
    }
}

int findDistanceFromLCA(TreeNode* root, int target, int count) {
    // Base case: if the current node is NULL, return -1 (target not found in this path)
    if (root == NULL) return -1;

    // If the current node matches the target, return the current depth (distance from LCA)
    if (root->val == target) return count;

    // Recursively search for the target in the left subtree
    int left = findDistanceFromLCA(root->left, target, count + 1);

    // If the target is found in the left subtree, return the result (don't search for right)
    if (left != -1) return left;

    // Otherwise, search in the right subtree and return the result
    return findDistanceFromLCA(root->right, target, count + 1);
}

int findDistanceBetweenNodes(TreeNode* root, int n1, int n2) {
    // Time complexity: O(n)
    // space complexiy: O(h)

    /* Intuition: 
    Step 1: Find LCA (Lowest Common Ancesstor) between 2 nodes. 
    Step 2: Find distance between LCA to node1 and LCA to node2. 
    Step 2: Add both the distance and return 
    */

    // Step1: Finding LCA between node1 & node2
    TreeNode* lca = findLCA(root, n1, n2);
    
    // if either node is missing
    if (lca == NULL) return -1; 

    // Step 2: Find distance between LCA to node1
    int d1 = findDistanceFromLCA(lca, n1, 0);
    // Find distance between LCA to node2
    int d2 = findDistanceFromLCA(lca, n2, 0);

    // Total distance between n1 and n2
    return d1 + d2;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(4);
    root->left->right->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);

    /* 
         1
        /  \
       2    3
      / \    \
     4   5    7
          \
           4
            \ 
             6
           
    */
    

    cout<<findDistanceBetweenNodes(root, 4, 6);

    /*optimize solution 
    map each node with its level - perform level order traversal

    calculate distance between 2 node using below formula
    distance = level[node1] + level[node2] - 2*level[LCA]
    return distance
    */ 
}