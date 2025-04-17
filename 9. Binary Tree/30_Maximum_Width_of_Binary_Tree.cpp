#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* 
Q. Maximum Width of Binary Tree

Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.


        1
    3       2
5      3       9
    

Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).


Intuition - 
To determine the maximum width of a tree, an effective strategy would be to assign and identify indexes for the leftmost and rightmost nodes at each level. Using these indexes, we can calculate the width for each level by subtracting the index of the leftmost node from that of the rightmost node.

Start by assigning an index to the root node as 0. For each level, the left child gets an index equal to 2 * parent index, and the right child gets an index equal to 2 * parent index + 1. Using a level order traversal, we use the leftmost and rightmost nodes at each level and using their indices, get the width at that level. Keep track of the maximum width encountered during the traversal. Whenever a wider level is found, update the maximum width.
1
2,3
4,5,6,7
8,9,10,11,12,13,14,15
so on and it could be very large 

But if we 2*parent it would be a overflow case which is 2x and if it is 10^5 it will be very large

So we start from 1 at each level 

1. index them left=2*i+1, right=2*i+2
2. maximum among all leve is my answer i.e 
width = last-first+1

eg 
1
12
1234
12345678

i=4-1
2*3+1 = 7
2*3+2 = 8

this is how we get no for particular index so do i-1 for each node

ans= 8-1+1 = 8
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

int widthOfBinaryTree(TreeNode* root) {
    // Time complexity - O(n) where N is the number of nodes in the binary tree. Each node of the binary tree is enqueued and dequeued exactly once, hence all nodes need to be processed and visited. 
    // space complexity - O(n) where N is the number of nodes in the binary tree. In the worst case, the queue has to hold all the nodes of the last level of the binary tree, 

    // If the root is null the width is zero
    if(root==NULL){
        return 0;
    }

    // Initialize a variable 'maxWidth' to store the maximum width
    int maxWidth=0;

    // Create a queue to perform level-order traversal, where each element is a pair of TreeNode* and its position in the level
    queue<pair<TreeNode*, int>>q;

    // Push the root node and its position (0) into the queue
    q.push({root,0});


    // Perform level order traversal 
    while(!q.empty()){
        // Get the number of nodes at the current level
        int size=q.size();

        // Get the position of the front node in the current level
        int min=q.front().second;

        // store first and last positions of nodes at current level
        int first, last;

        // Process each node at curent level
        for(int i=0;i<size;i++){
            // Calculate current position relative to the minimum position in the level
            long long int cur_id=q.front().second - min;

            // Get current node
            TreeNode* node = q.front().first;

            // Pop the front node from the queue
            q.pop();

            // If this is the first node in the level, update the 'first' variable
            if(i == 0){
                first=cur_id;
            }

            // If this is the last node in the level, update the 'last' variable
            if(i==size-1){
                last=cur_id;
            }
            
            // Enqueue the left child of the current node with its position
            if (node->left) {
                q.push({node->left, cur_id * 2 + 1});
            }

            // Enqueue the right child of the current node with its position
            if (node->right) {
                q.push({node->right, cur_id * 2 + 2});
            }
        }

        // Update the maximum width by calculating the difference between the first and last positions, and adding 1
        maxWidth= max(maxWidth, last-first+1);
    }

    return maxWidth;
}



int main(){
    
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->left->left = new TreeNode(6);

    
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(7);

    cout<<widthOfBinaryTree(root);
}