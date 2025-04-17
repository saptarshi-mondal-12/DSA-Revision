
/* 
Create Binary Tree From Descriptions

You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

    If isLeft == 1, then childi is the left child of parent.
    If isLeft == 0, then childi is the right child of parent.
    Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.

        50
    20      80
  15  17  19

Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent. The resulting binary tree is shown in the diagram. After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).

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

void print(Node* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}



Node* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_set<int>children;
    map<int, Node*>mp;
    for(int i=0;i<descriptions.size();i++){
        int parent=descriptions[i][0];
        int child=descriptions[i][1];
        int isLeft=descriptions[i][2];

        //1. creating parent node 
        if(mp.find(parent)==mp.end()){
            Node* n=new Node(parent);
            mp[parent]=n;
        }

        //2. creating child node 
        if(mp.find(child)==mp.end()){
            Node* n=new Node(child);
            mp[child]=n;
        }

        // adding child to left or right
        if(isLeft==1){
            mp[parent]->left=mp[child];
        }else{
            mp[parent]->right=mp[child];
        }

        children.insert(child);

        // The root is the node that is not in the children set 

    }
    int root=0;
    for(auto it:mp){
        if(children.find(it.first)==children.end()){
            root=it.first;
            break;
        }
    }
    return mp[root];
}





int main(){
    vector<vector<int>>v={{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
    Node* root=createBinaryTree(v);
    print(root);

    
    
    

    

}