/* 
right View of binary tree


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

void recursion(Node* root, int level, vector<int>&result){
    if(root==NULL) return;
    if(result.size()==level){
        result.push_back(root->data);
    }
    recursion(root->right,level+1,result);
    recursion(root->left,level+1,result);
}

vector<int> RightViewOfBinaryTree(Node* root){

    // Time Complexity: O(N)
    // Space Complexity:O(H)

    // if i travel from left to tight then last node of every level will my right view of binary tree 

    // or if i travel from right to left (<--) the 1st node at every level is my right view of binary tree

    // Why i use level order traversal ? 
    // because in level order traversal i have to store all node which takes more space like in worst case - TC-O(n), SC-O(n) for full binary tree

    // But in recurive way TC=O(n) and SC-O(H) height of tree
    // which recursion - recursive pre order - root right left

    vector<int>result;
    recursion(root,0,result);
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
    root->left->right->left = new Node(6);
    
    root->right = new Node(3);
    root->right->right = new Node(7);

    vector<int>res=RightViewOfBinaryTree(root);
    printResult(res);

}