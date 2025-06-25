#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Sum of nodes on the longest path 

Given a binary tree root[], you need to find the sum of the nodes on the longest path from the root to any leaf node. If two or more paths have the same length, the path with the maximum sum of node values should be considered.


Input: root[] = [4, 2, 5, 7, 1, 2, 3, N, N, 6, N]
         4
       /   \
      2     5
     / \   / \
    7   1 2   3
       /
      6

Output: 13
Longest path: 4 → 2 → 1 → 6
Sum: 4 + 2 + 1 + 6 = 13

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

pair<int, int> getSum(Node *root){
    if (root == NULL)
        return {0, 0};

    auto left = getSum(root->left);
    auto right = getSum(root->right);

    if (left.first > right.first){
        return {left.first + 1, left.second + root->data};
    }
    else if (left.first < right.first){
        return {right.first + 1, right.second + root->data};
    }
    else{ // equal height, take max sum
        return {left.first + 1, max(left.second, right.second) + root->data};
    }
}
int sumOfLongRootToLeafPath(Node *root){
    // Time Complexity: O(N)

    int sumOfLongestPath = getSum(root).second;
    return sumOfLongestPath;
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->right->left = new Node(2);
    root->right->right = new Node(3);
    root->left->right->left = new Node(6);

    int result = sumOfLongRootToLeafPath(root);
    cout << "Sum of nodes on the longest path: " << result << endl;
}
