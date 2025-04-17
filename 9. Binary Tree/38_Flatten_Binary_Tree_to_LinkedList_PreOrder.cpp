#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q.  Flatten Binary Tree to Linked List

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

void preorder_traversal(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void flatten(TreeNode* root) {
    // Time complexity - O(n)
    // space complexity - O(n)

    // Base case: If the current node is NULL, return.
    if (root==NULL){
        return;
    }

    // Use a stack for iterative traversal.
    stack<TreeNode*>st;

    // Push the root node onto the stack.
    st.push(root);

    // Continue the loop until the stack is empty.
    while(!st.empty()){
        // Get the top node from the stack.
        TreeNode* currNode=st.top();

        // Pop the top node.
        st.pop();

        // Push the right child onto the stack.
        if(currNode->right!=NULL){
            st.push(currNode->right);
        }

        // Push the left child onto the stack.
        if(currNode->left!=NULL){
            st.push(currNode->left);
        }

        // Connect the right child to the next node in the stack.
        if(!st.empty()){
            currNode->right=st.top();
        }

        // Set the left child to NULL to form a right-oriented linked list.
        currNode->left=NULL;
    }
}


void optimal_flatten(TreeNode* root) {
    // Time Complexity: O(N)
    // space complexity: O(1)

    /* Intuition: Morris Traversal
    on the left subtree whichever is the last node of preorder i connected it to the right of the root and kept on doing for every tree.

    Step 1: Start with the current node as the root of the tree.

    Step 2: While the current node is not null we traverse the tree in a while loop:

        If the current node has a left child:
            a. Find the rightmost node in the left subtree.
            b. Connect the rightmost node of the left subtree to the current node’s right child.
            c. Update the current node’s right child to be its left child.
            d. Set the current node’s left child to null.
    Move to the current node’s right child.
    If the current node has no right child:
        Move to the current node’s left child (if it exists) or null.
    
        Step 3: Repeat until all nodes are processed.

    After 1 operatio it look like (4 ka right 5 ho javega (prev->right=curr->right;), aur 1 ka right 2 ho jayega (curr->right=curr->left ) aur 1 ka left null ho jayega (curr->left=NULL)

      1
       \
    _____
   2     
  / \     
 3   4     
      \
       5
        \
         6


    */

    TreeNode* curr=root;
    // Iterate until 'curr' becomes NULL
    while (curr!=NULL){
        // Check if the current node has a left child
        if(curr->left!=NULL){

            // If yes, find the rightmost node in the left subtree
            TreeNode* prev = curr->left;
            while (prev->right!=NULL) {
                prev = prev->right;
            }

            // Connect the rightmost node in the left subtree to the current node's right child
            prev->right=curr->right;

            // Move the entire left subtree to the right child of the current node
            curr->right=curr->left;

            // Set the left child of the current node to NULL
            curr->left=NULL;
        }
        // Move to the next node on the right side
        curr=curr->right;
    }

    // preorder_traversal(root);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    // brute
    flatten(root);

    // optimal
    optimal_flatten(root);
}
