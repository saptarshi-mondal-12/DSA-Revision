/* 
Delete Leaves With a Given Value

Given a binary tree root and an integer target, delete all the leaf nodes with value target.
Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).

        1
    2       3
  2      2    4

Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).

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




Node* brute_removeLeafNodes(Node* root, int target) {
    // recursive approach 

    // Base case
    if (root==NULL ){
        return NULL;
    }

    // 1. visiting left children 
    root->left=brute_removeLeafNodes(root->left, target);
    // 2. visiting right children
    root->right=brute_removeLeafNodes(root->right, target);


    // 3. checking if current node value is equal to target
    if(root->left==NULL && root->right==NULL && root->data==target){
        return NULL;
    }

    return root;
}

Node* optimal_removeLeafNodes(Node* root, int target) {
    // iterative approach

    if(root==NULL){
        return root;
    }
    stack<Node*>st;
    Node* currNode=root;
    Node* lastRightNode=NULL;

    while(!st.empty() || currNode!=NULL){
        while(currNode!=NULL){
            st.push(currNode);
            currNode=currNode->left;
        }
        currNode=st.top();

        if( currNode->right != lastRightNode && currNode->right!=NULL){
            currNode=currNode->right;
            continue;
        }
        st.pop();

        if(currNode->left==NULL && currNode->right==NULL && currNode->data==target){
            if(st.empty()){
                return NULL;
            }
            Node* parent=st.top();
            if(parent->left==currNode){
                parent->left=NULL;
            }else{
                parent->right=NULL;
            }
        }

        lastRightNode=currNode;
        currNode=NULL;
    }
    return root;
}





int main(){
    
    Node* root=new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(2);
    

    root->right = new Node(3);
    root->right->left = new Node(2);
    root->right->right = new Node(4);

    int target = 2;
    // Node* res=brute_removeLeafNodes(root, target);
    Node* res=optimal_removeLeafNodes(root, target);

    print(res);
    

}