/* 
Binary Tree Zigzag Level Order Traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

        1
    2       3
4      5|6     7

arr=[1,3,2,4,5,6,7]

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

vector<vector<int>> zigzagLevelOrder(Node* root){
    // Time complexity - O(n)
    // space complexity - O(n)

    vector<vector<int>>result;
    if(root==NULL){
        return result;
    }
    // Queue to perform level order traversal
    queue<Node*>q;
    q.push(root);

    // Flag to determine the direction of traversal from L-R OR R-L
    bool flag=true;

    while(!q.empty()){
        int size=q.size();
        // To store value of node at current level
        vector<int>row(size);

        // Traverse node at current level
        for(int i=0;i<size;i++){
            // get front node from queue
            Node* n=q.front();
            q.pop();
            int index=flag?i:(size-1-i);
            row[index]=n->data;

            // Enqueue the left and right children if they exist
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
        }
        if(flag){
            flag=false;
        }else{
            flag=true;
        }
        result.push_back(row);
    }
    return result;
    
}

void printResult(const vector<vector<int>>& result) {
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}



int main(){
    Node* root=new Node(1);
    
    // left
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    // right
    root->right=new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    vector<vector<int>>result=zigzagLevelOrder(root);
    printResult(result);

}