/* 
Iterative postorder Traversal (left->right->root)

        1
    2       3
4      5|6     7

arr=[4,5,2,6,7,3,1]

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

void postorder_iterative_traversal(Node* root){
    // Time complexity - O(2n)
    // space complexity - O(n)
    
    vector<int>postorder;
    if(root==NULL){
        return;
    }

    // think in term of skew tree: root->right-> right right right right

    stack<Node*>st;
    Node* curr=root;
    while(curr!=NULL || !st.empty()){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }else{
            Node* temp=st.top()->right;
            if(temp==NULL){
                temp=st.top();
                st.pop();
                postorder.push_back(temp->data);
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }else{
                curr=temp;
            }
        }
    }
    
    for(int i=0;i<postorder.size(); i++){
        cout<<postorder[i]<<" ";
    }

}


int main(){
    Node* root=new Node(1);
    
    // left
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    root->left->right->right=new Node(6);
    root->left->right->right->right=new Node(7);

    // right
    root->right=new Node(3);
    // root->right->left=new Node(6);
    // root->right->right=new Node(7);

    postorder_iterative_traversal(root);

}