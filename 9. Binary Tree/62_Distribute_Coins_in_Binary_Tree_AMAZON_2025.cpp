#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Distribute Coins in Binary Tree - AMAZON 2025 

You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.
In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.


Input: root = [3,0,0]
        3
       / \ 
      0   0
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.


Input: root = [0,3,0]
        0
       / \ 
      3   0
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.


Intuition: -----------------------------------------------------------------------------



*/

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

class soln{
    public: 

    int result=0;

    int dfs(Node *root){
        // Base case: if root is NULL return
        if (root == NULL){
            return 0;
        }

        

        // Get extra coins from left subtree
        int left_extraCoins = dfs(root->left);

        // Get extra coins from right subtree
        int right_extraCoins = dfs(root->right);

        // Calculate Extra coins for current node
        // -1 for itself node and remaining coin is extra coins
        int extraCoins = (root->data - 1) + left_extraCoins + right_extraCoins;
        result += abs(extraCoins);

        return extraCoins;
    }
    int distributeCoins(Node *root){
        // Time complexity: O(n)
        // Space complexit: O(h)

        dfs(root);
        return result;
    }

};


int main(){
    Node *root = new Node(0);
    root->left = new Node(3);
    root->right = new Node(0);
    
    soln s;
    cout << s.distributeCoins(root) << endl;
}