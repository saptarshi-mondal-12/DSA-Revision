#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Print all k-sum paths in a binary tree - Amazon 

A binary tree and a number k are given. Print every path in the tree with sum of the nodes in the path as k. 
A path can start from any node and end at any node and must be downward only, i.e. they need not be root node and leaf node; and negative numbers can also be there in the tree.

Examples: 

Input : k = 5  
Root of below binary tree:
           1
        /     \
      3        -1
     /  \     /   \
    2   1    4     5                        
       /    / \     \                    
      1    1   2     6    
                       
Output :
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 



Intuition --------------------------------------------------------------------------

The basic idea to solve the problem is to do a preorder traversal of the given tree. We also need a container (vector) to keep track of the path that led to that node. At each node we check if there are any path that sums to k, if any we print the path and proceed recursively to print each path.

✅ Approach:
    1. Traverse the tree using DFS (preorder).
    2. Maintain a path vector from the root to the current node.
    3. At each node, check all sub-paths ending at current node and calculate their sum.
    4. If any sub-path sums to k, print it.*/

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printKPath(Node *root, int k, vector<int> &path){
    if (root == NULL)
        return;

    // Add current node to the path
    path.push_back(root->data);

    // Traverse left and right subtree
    printKPath(root->left, k, path);
    printKPath(root->right, k, path);

    // Check for paths ending at this node that sum to k
    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--){
        sum += path[i];
        if (sum == k){
            // Print the path
            for (int j = i; j < path.size(); j++){
                cout << path[j] << " ";
            }
            cout << endl;
        }
    }

    // Backtrack
    path.pop_back();
}

void printKPathUtil(Node *root, int k){
    // Time Complexity: O(N²) in the worst case (for skewed trees), where N is number of nodes.

    vector<int> path;
    printKPath(root, k, path);
}

int main() {
    /* Constructing the tree:
               1
            /     \
          3        -1
        /   \     /   \
      2     1   4       5                        
           /   / \         \                    
          1   1   2          6    
    */

    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(-1);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(6);

    int k = 5;
    cout << "Paths with sum " << k << " are:\n";
    printKPathUtil(root, k);
}