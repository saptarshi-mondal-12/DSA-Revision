#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* 
Q. Children Sum in a Binary Tree

Given a binary tree having n nodes. Check whether all of its nodes have a value equal to the sum of their child nodes. Return 1 if all the nodes in the tree satisfy the given properties, else it returns 0. For every node, the data value must be equal to the sum of the data values in the left and right children. Consider the data value 0 for a NULL child. Also, leaves are considered to follow the property.

Input:
Binary tree
       35
      /  \
     20   15
    / \   / \
   15  5 10  5

Output: 1
Explanation: Here, every node is sum of its left and right child.

Input:
Binary tree
       1
     /   \
    4     3
   /  
  5    
Output: 0
Explanation: Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of root node. Hence, this tree does not satisfy the given condition.
*/

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


int isSumProperty(TreeNode* root){
    // Time Complexity: O(N)
    // Space Complexity: O(N)

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            // Get the front node in the queue.
            TreeNode* curr=q.front();

            // Store the current node's value that is going to be checked
            int val=curr->data;

             // Remove the processed node from the queue.
            q.pop();

            // Variable to store the sum of child node values.
            int total=0;

            // If the left child exists, push it into the queue and add its value to total.
            if(curr->left!=NULL){
                q.push(curr->left);
                total+=curr->left->data;
            }

            // If the right child exists, push it into the queue and add its value to total.
            if(curr->right!=NULL){
                q.push(curr->right);
                total+=curr->right->data;
            }

            // If the current node is not a leaf and its value is not equal to the sum of its children, return 0.
            if( (total != val) && ((curr->left!=NULL) || (curr->right!=NULL)) ){
                return 0;    
            }
        }    
    }
    return 1; 
}




int main(){
    TreeNode* root=new TreeNode(35);
    root->left = new TreeNode(20);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);

    if(isSumProperty(root)){
        cout<<"True: Follow Children Sum Property"<<endl;
    }else{
        cout<<"False"<<endl;
    }

}