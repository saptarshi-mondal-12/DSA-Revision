/* 
Lowest common Ancestor

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”


Intuition ----------------------------------------

🔹 How recursion captures this idea

Base case:
    If the current node is one of the targets (a or b), return it upward.
    ➝ Because this node could be part of the LCA.

Recursive exploration:
    a. Search left and right subtrees.
    b. If neither side finds anything → return NULL.
    c. If only one side finds a target → bubble it up (propagate the “found node”).

Critical moment (intuition of LCA):
    a. If both left and right subtrees return non-null, it means:
        One target was found in the left subtree.
        The other target was found in the right subtree.
    So the current node is the split point → LCA.


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

/* 
          1
        /   \
       2     3
     /   \
    4     5
         / \
        6   7

*/
Node* LowestCommonAncestor(Node* root, Node* a, Node* b) {
    // Time complexity: O(n)
    // Space complexity: O(H) axulary stack space for recursive 
    

    // Base case: If the current node is one of the targets (a or b), return it upward. Because this node could be part of the LCA.
    if(root==NULL || root==a || root==b){
        return root;
    }

    Node* lh=LowestCommonAncestor(root->left,a,b);
    Node* rh=LowestCommonAncestor(root->right,a,b);

    // result
    if(lh==NULL){
        return rh;
    }else if(rh==NULL){
        return lh;
    }else{
        // if both (lh & rh) are not null means we get our LCA, so return root
        return root;
    }

}




int main(){
    
    /* 
          1
        /   \
       2     3
     /   \
    4     5
         / \
        6   7

    */
    Node* root=new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    Node* a=root->left->right->left = new Node(6);
    Node* b=root->left->right->right = new Node(7);

    root->right = new Node(3);

    int result=LowestCommonAncestor(root,a,b)->data;

    cout<<result;
    

}