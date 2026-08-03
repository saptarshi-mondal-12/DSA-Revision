#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Root to node path 

Problem  Statement: Given a Binary Tree and a reference to a root belonging to it. Return the path from the root node to the given leaf node.
    No two nodes in the tree have the same data value.
    It is assured that the given node is present and a path always exists.

Input:Binary Tree: 1 2 3 4 5 -1 -1 -1 -1, Node: 7
output: [1,2,5,7]


        1
    2       3
4      5
    6     7


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

bool getPath(Node* root, vector<int>&arr, int x){
    // If the current node is null then we return false, indicating the end of the path.
    if(root==NULL){
        return false;
    }
    // always add present val into array
    arr.push_back(root->data);

    // if it is equal to x, i got my path and going to return my ans true
    if(root->data==x){
        return true;
    }

    // if not then i go left & right 
    if(getPath(root->left,arr,x) || getPath(root->right,arr,x)){
        return true;
    }
    arr.pop_back();
    return false; 
}


vector<int> solve(Node* root, int x) {
    // Time complexity: O(n)
    // Space complexity: O(H)

    // inorder traversal
    vector<int>result;
    if (root==NULL){
        return result;
    }
    getPath(root,result,x);

    return result;
}




int main(){
    
    Node* root=new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    root->right = new Node(3);
    
    int targetLeafValue=7;
    vector<int>result=solve(root, targetLeafValue);
    for(auto it: result){
        cout<<it<<" ";
    }
    cout<<endl;

}