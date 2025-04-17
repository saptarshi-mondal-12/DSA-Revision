#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q. Largest BST

You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.

Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.

Input: root = [5, 2, 4, 1, 3]
        5
       /  \
      2    4
     / \
    1   3


Outpur: 3
Explanation:The following sub-tree is a BST of size 3
    2
    /\
   1  3

Intuition: 
✅ Approach: Postorder traversal (Left → Right → Root) ensures that when we process a node, we already have all the necessary information from its children.
✅ Key Idea: Each node gathers BST info from its left and right subtrees, avoiding redundant checks.

Instead of checking every subtree separately (which led to the O(N^2) approach), we can efficiently gather necessary information in a single traversal.
We traverse the tree in postorder and for each node, we compute:

    1. Whether the subtree rooted at the node is a valid BST.
    2. The size of the largest BST subtree within that subtree.
    3. The minimum and maximum values in the subtree (to check BST property efficiently).

Q. What Information Do We Need?
For each subtree rooted at a node, we need to determine:
    1. Is this subtree a valid BST?
    2. How many nodes are in the largest BST within this subtree?
    3. What are the minimum and maximum values in this subtree?

To store this information, we use a helper function that returns a struct (or tuple) with:
    size → Number of nodes in the largest BST subtree.
    minVal → Minimum value in the subtree.
    maxVal → Maximum value in the subtree.
    isBST → Boolean flag indicating whether the subtree is a valid BST.

Algorithm: 

Step 1: Base Case
Step 2: Recursive Calls - Get information from left and right subtrees using recursion.
Step 3: Check if Current Subtree is a BST
    A subtree rooted at root is a valid BST if and only if:
        The left subtree is a BST.
        The right subtree is a BST.
        The root value is greater than the maximum value in the left subtree.
        The root value is smaller than the minimum value in the right subtree.

Step 4: If Valid BST, Update Largest BST Size
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



bool checkValidBST(TreeNode* root, long long minVal, long long maxVal) {
    // Space Complexity: O(h), where h is the height of the tree. In the worst case, h could be n (if the tree is completely skewed)

    if (root == NULL) return true;
    if (root->val >= maxVal || root->val <= minVal) return false;
    
    bool leftValid = checkValidBST(root->left, minVal, root->val);
    bool rightValid = checkValidBST(root->right, root->val, maxVal);
    
    return leftValid && rightValid;
}

bool isValidBST(TreeNode* root) {
    // Time complexity : O(n)
    // space complexity : O(1)

    return checkValidBST(root, LLONG_MIN, LLONG_MAX);
}

int brute_countTotalNodes(TreeNode* root){
    // Time complexity : O(n)
    // space complexity : O(n)

    queue<TreeNode*>q;
    q.push(root);
    int totalNodes=0;
    while (!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* curr=q.front();
            totalNodes+=1;
            q.pop();

            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
    return totalNodes;
}

void postorder(TreeNode* root, int &largestBSTCount){
    // Space Complexity: O(h) for the recursion stack.

    if (root==NULL){
        return;
    }
    postorder(root->left, largestBSTCount);
    postorder(root->right, largestBSTCount);

    // check for valid BST
    if(isValidBST(root)){
        // if true count total no of nodes presenet in that BST
        int countTotalNodes = brute_countTotalNodes(root);

        // update largestBSTCount
        largestBSTCount = max(largestBSTCount, countTotalNodes);
    }
}

int brute_largestBst(TreeNode* root){
    // Time complexity: O(n^2) - Since postorder is called once for each node, and within each call we do two O(n) operations (checking validity and counting nodes), the overall time complexity will be:  O(n^2)
    // space complexity: O(n)

    /*Intuition: 
    1. We traverse the tree in postorder, go to each and every node and check for a valid BST.
    2. if a tree a valid BST, we count the no of nodes.
    3. At last we return largest count among all valid BST in given binary tree.
    */

    // Declare variable to store largest count of BST
    int largestBSTCount=0;

    // performing post order traversal
    postorder(root, largestBSTCount);

    return largestBSTCount;
}


// -------------------------------------------------------------------

class info {
    public:
    int maxi;    // Max value in subtree
    int mini;    // Min value in subtree
    bool isBST;  // Is subtree a BST
    int size;    // Size of the largest BST
};

info largestBSTHelper(TreeNode* root, int &maxSize) {
    /*  Q. Why we pass INT_MIN in place of maxi and in mini why we pass INT_MAX
        Ans: becasue to be a valid BST the condition is (left.maxi < root->val < right.mini)
            if root is null we pass {INT_MIN, INT_MAX, true, 0} that means
            left.maxi = INT_MIN and right,mini = INT_MAX
            so INT_MIN < root->val < INT_MAX
    */

    /*Step 1: Base case, if root is null return {maxi, mini, isBST, size} - The base case is executed when a node is NULL, which happens in two scenarios: When the tree itself is empty. When we reach a leaf node’s left or right child (both will be NULL). */
    if (root==NULL){
        // {maxi, mini, isBST, size}
        return {INT_MIN, INT_MAX, true, 0};
    }

    // Step 2: Recursively get info from left and right subtrees
    info left = largestBSTHelper(root->left, maxSize);
    info right = largestBSTHelper(root->right, maxSize);

    info currNode;
    currNode.size=left.size + right.size + 1;
    currNode.maxi=max(root->val, right.maxi);
    currNode.mini=min(root->val, left.mini);


    // Step 3: Check if Current Subtree is a BST
    if (left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini)) {
        currNode.isBST=true;
    }else{
        currNode.isBST=false;
    }

    // Step 4: If Valid BST, Update Largest BST Size
    if(currNode.isBST){
        maxSize=max(maxSize, currNode.size);
    }
    
    return currNode;
}

int optimal_largestBst(TreeNode* root) {
    // Time complexity: O(n) - Each node is visited once and processes its left and right subtree in constant time. Since it's a postorder traversal (bottom-up), each node contributes O(1) time.

    // space complexity: O(h) - where h is the tree height.
    
    int maxSize = 0;
    largestBSTHelper(root, maxSize);
    return maxSize;
}


int main(){
    TreeNode* root = new TreeNode(8);
    
    // Left subtree
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    // Right subtree
    root->right = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);


    // 1. brute 
    cout<<brute_largestBst(root)<<endl;

    // 2. optimal solution
    cout<<optimal_largestBst(root)<<endl;
}