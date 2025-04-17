/* 
Root to node path 


        1
    2       3
4      5
    6     7

output: [1,2,5,7]
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

bool getPath(Node* root, vector<int>&arr, int x){
    // if we reach at leaves return false
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


vector<int> isSymmetric(Node* root, int x) {
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
    

    vector<int>result=isSymmetric(root, 7);
    for(auto it: result){
        cout<<it<<" ";
    }
    cout<<endl;

}