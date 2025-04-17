#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. MinimumTime To burn a binary tree
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.

Input: root[] = [1,2,3,4,5,N,6,N,N,7,8,N,9,N,N,N,N,N,10],  target = 8
Output: 7

       1
      /  \
     2    3
    / \     \
   4   5     6
      / \     \
      7  8     9
                \
                10
       

Explanation: If leaf with the value 8 is set on fire. 
After 1 sec: 5 catches fire.
After 2 sec: 2, 7 catches fire.
After 3 sec: 4, 1 catches fire.
After 4 sec: 3 catches fire.
After 5 sec: 6 catches fire.
After 6 sec: 9 catches fire.
After 7 sec: 10 catches fire.
It takes 7s to burn the complete tree.


Input: root[] = [1, 2, 3, 4, 5, N, 7, 8, N, 10], target = 10
Output: 5
Explanation: If leaf with the value 10 is set on fire. 
- After 1 sec: Node 5 catches fire.
- After 2 sec: Node 2 catches fire.
- After 3 sec: Nodes 1 and 4 catches fire.
- After 4 sec: Node 3 and 8 catches fire.
- After 5 sec: Node 7 catches fire.
It takes 5s to burn the complete tree.


Intuition: 
We need to determine the minimum time required to burn the entire binary tree if a given target node catches fire. The fire spreads to its left child, right child, and parent in 1 second. Our goal is to calculate the maximum time required to burn all nodes.

Step 1: Traverse the Tree and Store Parent Pointers
bfsToMergeParents:
    The problem involves both upward (parent) and downward (child) movement of fire.
    A standard tree only has child pointers, so we need to store parent-child relationships to move upwards.

        Solution: We traverse the tree and store the parent of each node in a map. Maps child nodes to their parents using BFS.
        And The fire starts from a given node (target). Se also identifies the target node (where the fire starts)  while mapping parent-child relationships,

----------------------------------------------------------------------------------------------------------
Step 2: Start BFS from the Target Node and spread fire
findMaxDistance:
    Fire spreads level by level to all adjacent nodes (left, right, parent).
    We use BFS (Breadth-First Search) since it processes nodes level by level.
    A queue helps us track nodes burning at each second.
    We maintain a visited map to prevent revisiting burned nodes.
    This ensures each node burns exactly once.
    The BFS runs in multiple iterations.
    Each iteration (or level) represents 1 second of fire spreading.
    We count how many iterations it takes to burn all nodes.

minTime:
    Calls bfsToMergeParents to create the parent mapping and find the target.
    Calls findMaxDistance to compute the burning time.
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


int findMaxDistance(map<TreeNode*, TreeNode*>&mpp, TreeNode* target){
    queue<TreeNode*>q;
    q.push(target);

    // Map to keep track of visited nodes
    map<TreeNode*, int> visited;

    // Mark target node as visited
    visited[target]=1;

    // Variable to store the time required to burn the tree
    int time=0;
    while(!q.empty()){
        // Get the number of nodes at the current level
        int size=q.size();
        
        // Flag to check if new nodes are burned
        int flag=0;
        for(int i=0;i<size;i++){ // Process all nodes at the current level
            TreeNode* curr=q.front();
            q.pop();

            // Check left child
            if(curr->left && !visited[curr->left]){
                // Set flag since a new node is burned
                flag=1;

                // Mark left child as visited
                visited[curr->left]=1;

                // Push left child into the queue
                q.push(curr->left);
            }

            // Check right child
            if(curr->right && !visited[curr->right]){
                // Set flag since a new node is burned
                flag=1;

                // Mark right child as visited
                visited[curr->right]=1;

                // Push right child into the queue
                q.push(curr->right);
            }

            // Check parent node (using map)
            if(mpp[curr] && !visited[mpp[curr]]){
                // Set flag since a new node is burned
                flag=1;

                // Mark parent as visited
                visited[mpp[curr]]=1;

                // Push parent node into the queue
                q.push(mpp[curr]);
            }
        }
        // If any node was burned in this level, increment the time
        if(flag==1){
            time+=1;
        }
    }
    return time;
}

TreeNode* bfsToMergeParents(TreeNode* root, map<TreeNode*, TreeNode*>&mpp, int start){
    queue<TreeNode*>q;
    q.push(root);

    // Variable to store the target node
    TreeNode* res; 
    
    while(!q.empty()){ // BFS traversal
        // Get the front node
        TreeNode* curr=q.front();

        // If this node is the target node, Store it as the target node
        if(curr->data==start){
            res=curr;
        }

        // Remove the node from the queue
        q.pop();

        // Map left child to its parent
        if(curr->left){
            // Store parent of left child
            mpp[curr->left]=curr;

            // Push left child into queue
            q.push(curr->left);
        }
        if(curr->right){
            // Store parent of right child
            mpp[curr->right]=curr;
            q.push(curr->right);
        }
    }
    // Return the target node
    return res;
}
int minTime(TreeNode* root, int start) {
    // Time Complexity: O(N) (since we traverse each node once)
    // Space Complexity: O(N) (for storing parent-child mapping and BFS queue) 
    
    // Map to store parent pointers
    map<TreeNode*, TreeNode*>mpp;

    // Find target node and map parents
    TreeNode* target=bfsToMergeParents(root, mpp, start);

    // Function to find the minimum time required to burn the tree
    int maxi=findMaxDistance(mpp, target);
    return maxi;
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(9);
    root->right->right->right->right = new TreeNode(10);

    int start=8;
    cout<<minTime(root, start);

}