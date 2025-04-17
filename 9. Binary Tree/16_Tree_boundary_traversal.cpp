/* 
Tree Boundary Traversal


Given a Binary Tree, perform the boundary traversal of the tree. The boundary traversal is the process of visiting the boundary nodes of the binary tree in the anticlockwise direction, starting from the root.

Left Boundary: Traverse the left boundary of the tree. Start from the root and keep moving to the left child; if unavailable, move to the right child. Continue this until we reach a leaf node.

Bottom Boundary: Traverse the bottom boundary of the tree by traversing the leaf nodes using a simple preorder traversal. We check if the current node is a lead, and if so, its value is added to the boundary traversal array.

Right Boundary: The right boundary is traversed in the reverse direction, similar to the left boundary traversal starting from the root node and keep moving to the right child; if unavailable, move to the left child. Nodes that are not leaves are pushed into the right boundary array from end to start to ensure that they are added in the reverse direction.

        1
    2       3
4      5|6     7

arr=[1,2,4,5,6,7,3]

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

void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout<<endl;
}

bool isLeaf(Node* root){
    // checking if node is a leaf
    if (root->left==NULL && root->right==NULL){
        return true;
    }
    return false;
}

void addLeftBoundary(Node* root, vector<int>&result){
    Node* curr=root->left;
    while(curr){
        // if current node is not leaf, add its value to result
        if(!isLeaf(curr)){
            result.push_back(curr->data);
        }
        // Move to left child if exist, otherwise move to right child
        if(curr->left){
            curr=curr->left;
        }else{
            curr=curr->right;
        }
    }

}

void addLeaves(Node* root, vector<int>&result){
    // if current node is leaf, add its value to the result
    if(isLeaf(root)){
        result.push_back(root->data);
        return;
    }
    if(root->left){
        addLeaves(root->left, result);
    }
    if(root->right){
        addLeaves(root->right, result);
    }
}

void addRightBoundary(Node* root, vector<int>&result){
    Node* curr=root->right;
    vector<int>temp;
    while(curr){
        // if current node is not leaf, add its value to result
        if(!isLeaf(curr)){
            temp.push_back(curr->data);
        }
        // Move to right child if exist, otherwise move to left child
        if(curr->right){
            curr=curr->right;
        }else{
            curr=curr->left;
        }
    }
    // Reverse and add the values from the temporary vector to the result
    for (int i=temp.size()-1; i>=0; --i) {
        result.push_back(temp[i]);
    }
}


vector<int> treeBoundary(Node* root){
    // Time complexity - O(n)
    // space complexity - O(n)
    vector<int>result;
    if(root==NULL){
        return result;
    }
    // if root is not a leaf, add its value to result
    if(!isLeaf(root)){
        result.push_back(root->data);
    }

    // 1. add left boundary 
    addLeftBoundary(root,result);
    // 2. add leaves
    addLeaves(root,result);
    // 3. add right boundary
    addRightBoundary(root, result);

    return result;
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

    vector<int>res=treeBoundary(root);
    printResult(res);

}