#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Morris postorder Traversal of a Binary tree

Intuition: everything same as morris traversal The approach to performing Morris Traversal for Postorder is similar to Morris traversal for Preorder except swapping between left and right node links.
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

vector<int> postorderTraversal(TreeNode* root) {
    /*
    Time Complexity: O(2N)
    Space Complexity: O(1)
    */

    // Vector to store the postorder traversal result
    vector<int>postorder;

    // if root is NULL, return
    if(root==NULL){
        return postorder;
    }

    // Pointer to the current node, starting from the root
    TreeNode* curr=root;

    // Loop until the current node is not NULL
    while(curr!=NULL){
        // If the current node's right child is NULL
        if(curr->right==NULL){
            // Add the value of the current node to the postorder vector and Move to the left child
            postorder.push_back(curr->data);
            curr=curr->left;
        }
        else{
            
            TreeNode* prev=curr->right;
            while(prev->left!=NULL && prev->left!=curr){
                prev=prev->left;
            }

            if(prev->left==NULL){
                prev->left=curr;
                postorder.push_back(curr->data);
                curr=curr->right;
            }else{
                prev->left=NULL;
                curr=curr->left;
            }
        }
    }
    // reverse the preorder traversal result
    reverse(postorder.begin(), postorder.end());
    return postorder;   
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    vector<int>postorder=postorderTraversal(root);

    for(int i=0;i<postorder.size(); i++){
        cout<<postorder[i]<<" ";
    }
}