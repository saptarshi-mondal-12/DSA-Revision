#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Maximum Binary Tree

NOTE: Variation of Q35.

You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

Create a root node whose value is the maximum value in nums.
Recursively build the left subtree on the subarray prefix to the left of the maximum value.
Recursively build the right subtree on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.



Example 1:

        6
       / \
      3   5
       \  /
        2 0
         \
          1

Input: nums = [3,2,1,6,0,5]
Output: [6,3,5,null,2,0,null,null,1]
Explanation: The recursive calls are as follow:
- The largest value in [3,2,1,6,0,5] is 6. Left prefix is [3,2,1] and right suffix is [0,5].
    - The largest value in [3,2,1] is 3. Left prefix is [] and right suffix is [2,1].
        - Empty array, so no child.
        - The largest value in [2,1] is 2. Left prefix is [] and right suffix is [1].
            - Empty array, so no child.
            - Only one element, so child is a node with value 1.
    - The largest value in [0,5] is 5. Left prefix is [0] and right suffix is [].
        - Only one element, so child is a node with value 0.
        - Empty array, so no child.


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

void preorder(TreeNode* root) {
    if (root == nullptr) return;
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


// Brute------------------------------------------------------------------------------------------
TreeNode *buildTree(vector<int> &nums, int inStart, int inEnd){
    if (inStart > inEnd)
        return NULL;

    // Find index of the maximum element in the current subarray
    int maxIndex = inStart;
    for (int i = inStart + 1; i <= inEnd; ++i){
        if (nums[i] > nums[maxIndex])
        {
            maxIndex = i;
        }
    }

    // Create a new TreeNode with max value
    TreeNode *root = new TreeNode(nums[maxIndex]);

    // Recursively build the left subtree
    root->left = buildTree(nums, inStart, maxIndex - 1);

    // Recursively build the right subtree
    root->right = buildTree(nums, maxIndex + 1, inEnd);

    // Return the current root node
    return root;
}

TreeNode *constructMaximumBinaryTree(vector<int> &nums){
    // The time complexity is O(n²) in the worst case because we scan for the maximum in each subarray. In the best case, when the tree is balanced, it's O(n log n). 
    
    // The space complexity is O(n) because we build a tree of n nodes and also use recursive stack space.

    TreeNode *newTree = buildTree(nums, 0, nums.size() - 1);
    return newTree;
}




// Optimal------------------------------------------------------------------------------------------
TreeNode* optimal_constructMaximumBinaryTree(vector<int>& nums) {
    // Time: O(n) Each element is pushed and popped at most once from the stack.
    // Space: O(n) Stack holds up to n nodes in the worst case.

        
    stack<TreeNode*> st;

    for (int num : nums) {
        TreeNode* current = new TreeNode(num);

        // Pop smaller elements and assign as left child
        while (!st.empty() && st.top()->data < num) {
            current->left = st.top();
            st.pop();
        }

        // If stack not empty, assign current as right child
        if (!st.empty()) {
            st.top()->right = current;
        }

        st.push(current);
    }

    // The bottom of the stack is the root
    while (st.size() > 1) st.pop();
    return st.top();
}



int main() {
    vector<int> nums = {3, 2, 1, 6, 0, 5};

    /* Our compliled answer is different from question output because in question they print in level order traversal and we use preorder traversal to print my ans. But our answer is correct*/
    
    // brute
    // TreeNode* root = constructMaximumBinaryTree(nums);
    // preorder(root);



    // optimal
    TreeNode* root = optimal_constructMaximumBinaryTree(nums);
    preorder(root);
}