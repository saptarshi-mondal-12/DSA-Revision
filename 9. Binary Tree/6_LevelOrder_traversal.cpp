/* 
LevelOrder Traversal (Printing level wise)

        1
    2       3
4      5|6     7

arr=[1,2,3,4,5,6,7]

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

void levelorder_traversal(Node* root){
    // Time complexity - O(n)
    // space complexity - O(n)
    
    if(root==NULL){
        return;
    }
    // store ans
    vector<vector<int>>ans;
    // creating queue to store node
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        // getting size of current level
        int size=q.size();  

        // nodes at current level
        vector<int>level;
        for(int i=0;i<size;i++){
            Node* n=q.front();
            // remove front node from queue
            q.pop();
            level.push_back(n->data);

            // Enqueue child nodes if they exist
            if(n->left!=NULL){
                q.push(n->left);
            }
            if(n->right!=NULL){
                q.push(n->right);
            }         
        }
        ans.push_back(level);
    }

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
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

    levelorder_traversal(root);

}