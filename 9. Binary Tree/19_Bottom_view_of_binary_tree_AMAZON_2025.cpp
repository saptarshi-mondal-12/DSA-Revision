#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Bottom View of Binary Tree - AMAZON 2025 

Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the later one in the level order traversal is considered. For example, in the below diagram, 7 and 34 both are the bottommost nodes at a horizontal distance of 0 from the root, here 34 will be considered.  

        20 
       /  \
      8    22
     / \   / \
    5   7 34  25

[5, 8, 34, 22, 25]

*/

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

vector<int> BottomViewOfBinaryTree(Node* root){
    // Time Complexity: O(N)
    // Space Complexity:O(N)

    vector<int>result;

    if(root==NULL) return result;

    // using level order traversal 
    map<int,int>mp;

    queue<pair<Node*,int>>q;
    q.push({root,0});
    
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        Node* node=it.first;
        int lineNo=it.second;
        mp[lineNo]=node->data;

        if(node->left){
            q.push({node->left,lineNo-1});
        }
        if(node->right){
            q.push({node->right,lineNo+1});
        }
    }
    for(auto it:mp){
        result.push_back(it.second);
    }
    return result;
}

void printResult(vector<int>&result){
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}




int main(){
    Node* root=new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int>res=BottomViewOfBinaryTree(root);
    printResult(res);

}