#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/* Q1. Binary Tree Validation - AMAZON 2025

Given a list of TreeNode objects (val, left, right), determine whether they form a valid binary tree.
Example: [TN(1, 2, 3), TN(2, None, None), TN(3, None, None)] → True 


Definition of Valid Binary Tree: 
    1. Every node has at most one parent.
    2. A valid binary tree must have exactly one root
    3. Have no cycles (no node points to itself or is visited more than once).
    4. All nodes must be connected (i.e., form one single tree).


✅ Step-by-Step Plan:

*/

class TreeNode{
    public:
    int data;
    int left;
    int right;

    TreeNode(int val, int left, int right){
        data=val;
        this->left=left;
        this->right=right;
    }
};

bool dfs(int nodeVal, unordered_map<int, TreeNode*>& nodeMap, unordered_set<int>& visited){
    if(nodeVal == -1) return true;

    if (visited.count(nodeVal)) return false; // cycle detected
    visited.insert(nodeVal);

    TreeNode* node = nodeMap[nodeVal];
    if (!node) return false;

    bool left = dfs(node->left, nodeMap, visited);
    bool right = dfs(node->right, nodeMap, visited);

    return left && right;
}


bool isValidBinaryTree(vector<TreeNode*> nodes){
    unordered_set<int>childrenSet;
    unordered_map<int,TreeNode*>nodeMap;
    unordered_map<int,int>childToParent;

    // Step 1: map all nodes and check for multiple parent;
    for(auto node: nodes){
        nodeMap[node->data] = node;

        if(node->left != -1){
            // check if node->left already has a parent
            if(childToParent.count(node->left)){
                return false;
            }
            
            // map child with parent
            childToParent[node->left] = node->data;

            // insert child in children set
            childrenSet.insert(node->left);
        }

        if(node->right != -1){
            // check if node->right already has a parent
            if(childToParent.count(node->right)){
                return false;
            }
            
            // map child with parent
            childToParent[node->right] = node->data;

            // insert child in children set
            childrenSet.insert(node->right);
        }
    }

    // step 2: Find the root (root = the only node that is not present in childSet)--------------------------
    int root = -1;
    for(auto node: nodes){

        // if node->data is not present in children set, that is our root
        if(childrenSet.find(node->data) == childrenSet.end()){
            if(root==-1){
                root=node->data;
            }else{
                // we find more than one root
                return false;
            }
        }
    }
    // if no root is found
    if(root==-1) return false;


    // Step 3: DFS to check for cycles------------------------------------------------------------------------
    unordered_set<int>visited;
    if(dfs(root, nodeMap, visited) == false){
        return false;
    }


    // Step 4: All node must be connected ---------------------------------------------------------------------
    if(visited.size() == nodes.size()){
        return true;
    }
    return false;
}

int main() {
    vector<TreeNode*> nodes;
    nodes.push_back(new TreeNode(1, 2, 3));
    nodes.push_back(new TreeNode(2, -1, -1));
    nodes.push_back(new TreeNode(3, -1, -1));

    cout << (isValidBinaryTree(nodes) ? "True" : "False") << endl;  // Output: True
}
