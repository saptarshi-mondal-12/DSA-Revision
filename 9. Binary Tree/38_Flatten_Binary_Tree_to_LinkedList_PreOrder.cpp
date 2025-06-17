#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q.  Flatten Binary Tree to Linked List - Pre-order

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.

The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Input: root = [1,2,5,3,4,null,6]
      1
    /   \
   2     5
  / \     \
 3   4     6

Output: [1,null,2,null,3,null,4,null,5,null,6]

    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6

*/

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder_traversal(TreeNode *root){
    if (root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void flatten(TreeNode *root){
    // Time complexity - O(n)
    // space complexity - O(n)

    // Base case: If the current node is NULL, return.
    if (root == NULL){
        return;
    }

    // Use a stack for iterative traversal.
    stack<TreeNode *> st;

    // Push the root node onto the stack.
    st.push(root);

    // Continue the loop until the stack is empty.
    while (!st.empty()){
        // Get the top node from the stack.
        TreeNode *currNode = st.top();

        // Pop the top node.
        st.pop();

        // Push the right child onto the stack.
        if (currNode->right != NULL){
            st.push(currNode->right);
        }

        // Push the left child onto the stack.
        if (currNode->left != NULL){
            st.push(currNode->left);
        }

        // Connect the right child to the next node in the stack.
        if (!st.empty()){
            currNode->right = st.top();
        }

        // Set the left child to NULL to form a right-oriented linked list.
        currNode->left = NULL;
    }

    // preorder_traversal(root);
}

void preorder(TreeNode *curr, TreeNode *&prev){
    if (curr == NULL)
        return;

    // Save left and right child before modifying
    TreeNode *left = curr->left;
    TreeNode *right = curr->right;

    prev->left = NULL;
    prev->right = curr;
    prev = curr;

    preorder(left, prev);
    preorder(right, prev);
}

void optimal_flatten(TreeNode *root){
    // Time complexity: O(n)
    // Space complexity: O(H)

    // Dummy node
    TreeNode *dummy = new TreeNode(-1);
    TreeNode *prev = dummy;

    // Call modified traversal
    preorder(root, prev);

    // No need to reassign root — tree is modified in-place
    delete dummy;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    // brute
    // flatten(root);

    // optimal
    optimal_flatten(root);

    preorder_traversal(root);
}
