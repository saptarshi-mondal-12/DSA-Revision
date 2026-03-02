#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q.  Flatten Binary Tree to Linked List - In-order

Input: root = [1,2,5,3,4,null,6]
      1
    /   \
   2     5
  / \     \
 3   4     6

Inorder = [3,2,4,1,5,6]

Output: [3,null,2,null,4,null,1,null,5,null,6]

    3
     \
      2
       \
        4
         \
          1
           \
            5
             \
              6

*/

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Inorder traversal (used for printing the flattened list)
void inorder_traversal(TreeNode* root){
    if(root == NULL) return;
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

// -------- IN-PLACE INORDER FLATTEN --------
void flattenInorder(TreeNode* curr, TreeNode*& prev, TreeNode*& head){
    if(curr == NULL) return;

    // Left
    flattenInorder(curr->left, prev, head);

    // Process current
    curr->left = NULL;

    if(prev == NULL){
        // first inorder node becomes head
        head = curr;
    } else {
        prev->right = curr;
    }

    prev = curr;

    // Right
    flattenInorder(curr->right, prev, head);
}

TreeNode* inorderFlatten(TreeNode* root){
    // Time complexity: O(N)
    // Space complexity: O(H)

    /* 
    Intuition: 
        We need to flatten a binary tree in-place into a right-skewed linked list following inorder traversal, i.e., Left → Root → Right.
        All left pointers must be set to NULL, and the right pointer should point to the next node in inorder sequence.”

    Core idea (MOST IMPORTANT)
        In inorder traversal, nodes are visited in sorted order (for BST).
        So while traversing, I keep a pointer prev that always points to the previously visited node.
        When I visit the current node, I connect prev->right to curr, set curr->left = NULL, and then update prev = curr.

    Key insight (say this clearly): The first node visited in inorder becomes the head, so I store it separately.
    */

    TreeNode* prev = NULL;
    TreeNode* head = NULL;
    flattenInorder(root, prev, head);
    return head;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    // In-place inorder flatten
    TreeNode* head = inorderFlatten(root);

    // Print flattened list
    inorder_traversal(head);

    return 0;
}
