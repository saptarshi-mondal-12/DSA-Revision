#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. All Nodes Distance K in Binary Tree

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
You can return the answer in any order.

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
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

void markParent(TreeNode* root, map<TreeNode*, TreeNode*>&mp){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        if(curr->left){
            mp[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            mp[curr->right]=curr;
            q.push(curr->right);
        }
    }
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    // Time Complexity: O(N) (since we traverse each node once)
    // Space Complexity: O(N) (for storing parent-child mapping and BFS queue)

    vector<int>result;

    // if k==0 return target->val
    if(k==0){
        result.push_back(target->data);
        return result;
    }

    // Map to store parent pointers
    map<TreeNode*, TreeNode*>mp;

    // Function to mark parent
    markParent(root, mp);

    // Start traversing from target
    queue<TreeNode*>q;
    q.push(target);

    // Map to keep track of visited nodes
    map<TreeNode*,int>visited;

    // Mark target node as visited
    visited[target]=1;
    
    // Variable to store the distance from target node
    int distance=0;

    // Loop until distance == k
    while(!q.empty()){
        // Get the number of nodes at the current level
        int size=q.size();

        // Flag to check if new nodes are discovered
        int flag=0;

        // Process all nodes at the current level
        for(int i=0;i<size;i++){
            TreeNode*curr=q.front();
            q.pop();

            // Check left child
            if(curr->left!=NULL && !visited[curr->left]){
                // Set flag = 1 since a new node is discovered
                flag=1;

                // Mark left child as visited
                visited[curr->left]=1;

                // Push left child into the queue
                q.push(curr->left);
            }

            // Check right child
            if(curr->right!=NULL && !visited[curr->right]){
                // Set flag since a new node is discovered
                flag=1;

                // Mark right child as visited
                visited[curr->right]=1;

                // Push right child into the queue
                q.push(curr->right);
            }

            // check parent for current node
            if(mp[curr] && !visited[mp[curr]]){
                flag=1;
                visited[mp[curr]]=1;
                q.push(mp[curr]);
            }
        }

        // If any node was discovered in this level, increment the distance
        if(flag==1){
            distance++;
        }

        // if distance is equal to k, extract element and break out from loop
        if(distance==k){
            while(!q.empty()){
                TreeNode* curr=q.front();
                result.push_back(curr->data);
                q.pop();
            }
            break;
        }
    }
    return result;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->right->right = new TreeNode(8);
    root->right->left = new TreeNode(0);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    int k=2;
    TreeNode* target=root->left;
    vector<int>preorder=distanceK(root, target, k);

    for(int i=0;i<preorder.size(); i++){
        cout<<preorder[i]<<" ";
    }
}