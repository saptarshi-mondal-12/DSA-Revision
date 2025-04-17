#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Recover Binary Search Tree

You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Input: root = [1,3,null,null,2]
   1
  /
 3
  \
   2
Output: [3,1,null,null,2]
   3
  /
 1
  \
   2
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

Intuition: Optimal Solution

Do i need to store inorder. No Instead of storing values, if we detect the two misplaced nodes during inorder traversal itself and swap them directly at the end.
Key Idea:
    In a correct BST, the inorder traversal produces a sorted sequence.
    If two nodes are swapped, two inversions appear in the inorder sequence.
    We detect these two swapped nodes while traversing and swap them at the end.

How It Works:
    1. We do an inorder traversal while maintaining a pointer prev to track the previous node.
    2. If we find prev->val > root->val, we have an inversion (swapped nodes).
        The first occurrence gives us the first misplaced node (first).
        The second occurrence gives us the second misplaced node (second).
    3. After traversal, we swap the values of first and second to correct the BST.

How Swapping Affects Inorder Traversal
    Since inorder traversal of a BST gives a sorted sequence, swapping two nodes disrupts this order.

    EDGE CASE: When two nodes are swapped, two cases are possible:
        Case 1: The swapped nodes are not adjacent → 2 inversions
        Case 2: The swapped nodes are adjacent in inorder traversal → 1 inversion


CASE 1: The swapped nodes are not adjacent → 2 inversions
Eg. inorder = [3, 25, 7, 8, 10, 15, 20, 5]
    nodes = 25 & 5 (need to swap) - not adjacent
    (prev->val > root->val) i.e (25 > 7) (1st violation)
    (prev->val > root->val) i.e (20 > 5) (2nd violation)

    first=25 
    middle=7
    last=5
    swap only (first, last)
    

CASE 2: The swapped nodes are adjacent → 1 inversions
Eg. inorder = [3, 5, 8, 7, 10, 15, 20, 25]
    nodes = 8 & 7 (need to swap) - are adjacent node
    (prev->val > root->val) i.e (8 > 7) (1st violation)

    first=8
    middle=7
    last=NULL

Q. What if we have not find any 2nd violation?
Ans: So Just in case if we do not find any 2nd violation swap (first, middle).
This are the only pair which is violated (8,7). means adjacent i.e (first,middle). so swap it

That's why we store middle (for case 2)

By detecting inversions during inorder traversal, we can directly find and swap the incorrect nodes in O(n) time and O(1) space—without extra storage or sorting.

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

void printInorderTraversal(TreeNode* root){
    if(root==NULL){
        return;
    }
    printInorderTraversal(root->left);
    cout<<root->val<<" ";
    printInorderTraversal(root->right);
}

void solve(TreeNode* root, vector<int>&inorder){
    // Base case: If the current node is NULL, return
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    solve(root->left, inorder);
    
    // Store the current node's value in the inorder vector
    inorder.push_back(root->val);
    
    // Traverse the right subtree
    solve(root->right, inorder);
}

void check(TreeNode* root, vector<int>&inorder, int &curr){
    // Base case: If the current node is NULL, return
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    check(root->left, inorder, curr);

    // If the current node's value is incorrect, replace it with the correct value from the sorted inorder vector
    if (root->val != inorder[curr]) {
        root->val = inorder[curr];
    }

    // Move the pointer to the next element in the inorder vector
    curr += 1;

    // Traverse the right subtree
    check(root->right, inorder, curr);
}

void brute_recoverTree(TreeNode* root) {
    /* 
    Time Complexity: O(n) + O(n log n) + O(n)
    O(n) (for inorder traversal) + O(n log n) (for sorting) + O(n) (for replacing values) = O(n log n)
    
    Space Complexity: O(n) (to store the inorder traversal)

    
    Intuition:
    Step 1. Perform an inorder traversal and store the values in a vector. 
       Since inorder traversal of a BST gives a sorted sequence, 
       swapping two nodes results in an unsorted sequence.
    
    Step 2. Sort the stored inorder sequence to get the correct order.
    
    Step 3. Perform another inorder traversal and replace the incorrect values 
       with the correct ones from the sorted vector.
    */

    // Step 1: Store elements of BST using inorder traversal
    vector<int> inorder;
    solve(root, inorder);

    // Step 2: Sort the inorder vector to get the correct BST sequence
    sort(inorder.begin(), inorder.end());

    // Step 3: Use a pointer to update incorrect values in the tree
    int curr = 0;
    check(root, inorder, curr);

}


// -----------------------------------------------------------------------------------

class Solution {
public:
    TreeNode* first = NULL, *second = NULL, *prev = NULL, *middle;
    void inorder(TreeNode* root) {
        if (!root) return;
    
        // Traverse left subtree
        inorder(root->left);
    
        // Detect swapped nodes
        if (prev != NULL && (prev->val > root->val)) {
            // First occurrence: Store first and middle
            if (first == NULL){
                first = prev;
                middle=root;
            }
            // Second occurrence 
            else{
                second = root;
            }
        }
    
        // Update prev node
        prev = root;
    
        // Traverse right subtree
        inorder(root->right);
    }

    void optimal_recoverTree(TreeNode* root){
        // Time Complexity: O(n) since we do a single inorder traversal
        // Space compelxity: O(1) (not calculate recursive stack space)
        // So If interviewer say he is calculating recursive stack space then 
        // hey sir there is a morris traversal which we can definetely use in order to get O(1) space complexity. 

        // Find swapped nodes using inorder traversal
        inorder(root);

        // Swap values of the two incorrect nodes
        if (first && second) {
            swap(first->val, second->val);
        }
        //
        else if(first && middle){
            swap(first->val, middle->val);
        }
    }
};


int main(){
    
    TreeNode* root = new TreeNode(8);
    
    // Left subtree
    root->left = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    // Right subtree
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    // 1. brute soln
    // brute_recoverTree(root);
    // printInorderTraversal(root);


    // 2. optimal solution
    Solution s;
    s.optimal_recoverTree(root);
    printInorderTraversal(root);

}