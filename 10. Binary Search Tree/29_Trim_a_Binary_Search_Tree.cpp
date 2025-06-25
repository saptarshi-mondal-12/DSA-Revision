#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Trim a Binary Search Tree
Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.

Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.



Example 1:
         1                1
        / \      ==>       \
       0   2                2


Input: root = [1,0,2], low = 1, high = 2
Output: [1,null,2]


Example 2:
              3                  3
            /   \               /
           0     4   ==>       2
            \                 /
             2               1
             /
            1


Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
Output: [3,2,null,1]


*/

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};
void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Brute Soln------------------------------------------------------------------------------
void getValues(TreeNode *root, vector<int> &deleteContainer, int low, int high){
    if (root == NULL)
        return;

    getValues(root->left, deleteContainer, low, high);
    if (root->val < low || root->val > high){
        deleteContainer.push_back(root->val);
    }
    getValues(root->right, deleteContainer, low, high);
}

TreeNode *helper(TreeNode *root, int key){
    // Time complexity: O(h) h is the height of tree
    // Space complexity: O(n) recursive stack space
    if (root == NULL)
        return NULL;

    if (root->left == NULL)
        return root->right;
    if (root->right == NULL)
        return root->left;

    TreeNode *leftChild = root->left;
    TreeNode *rightChild = root->right;

    // Go to exctre right of left child
    TreeNode *curr = leftChild;
    while (curr->right != NULL){
        curr = curr->right;
    }
    if (curr->right == NULL){
        curr->right = rightChild;
    }
    return leftChild;
}

void deleteNode(TreeNode *&root, int key){
    // Time complexity: O(log n)

    if (root == NULL)
        return;

    if (root->val == key){
        root = helper(root, key);
        return;
    }

    TreeNode *curr = root;

    while (curr != NULL){
        if (key <= curr->val){
            if (curr->left != NULL && curr->left->val == key){
                curr->left = helper(curr->left, key);
                break;
            }
            else{
                curr = curr->left;
            }
        }
        else{
            if (curr->right != NULL && curr->right->val == key){
                curr->right = helper(curr->right, key);
                break;
            }
            else{
                curr = curr->right;
            }
        }
    }
}

TreeNode *trimBST(TreeNode *root, int low, int high){
    // Time complecity:  ⇒ O(n + k log n) => O(n) + O(k log n) where k = no of node to delete
    // space complexity: O(n) in wordet case

    // store the value that is to be deleted
    vector<int> deleteContainer;
    getValues(root, deleteContainer, low, high);

    // Using for loop to delete each value
    for (int i = 0; i < deleteContainer.size(); i++){
        int key = deleteContainer[i];

        // function to delete a node i.e key
        deleteNode(root, key);
    }
    return root;
}





// Optimal Soln ----------------------------------------------------------------------------
TreeNode *optimal_trimBST(TreeNode *root, int low, int high){
    // Time complexity: O(n)
    // Space complexity: O(h)

    /*Intuition:
    Remove all nodes with values outside the range [low, high], while maintaining the BST structure.

    Key BST Properties:
        Left subtree: all nodes < root
        Right subtree: all nodes > root

    So if:
        root->val < low ⇒ all nodes in the left subtree are too small ⇒ discard left, trim right
        root->val > high ⇒ all nodes in the right subtree are too large ⇒ discard right, trim left
    */

    if (root == NULL)
        return NULL;

    // If current node's value is less than low, discard the left subtree
    if (root->val < low)
        return trimBST(root->right, low, high);

    // If current node's value is greater than high, discard the right subtree
    if (root->val > high)
        return trimBST(root->left, low, high);

    // Node is in range: recursively trim left and right subtrees
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    return root;
}





int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(0);
    root->right=new TreeNode(2);

    int low=1, high=2;
    optimal_trimBST(root, low, high);
    inorder(root);
}