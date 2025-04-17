#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Construct Binary Tree from Postorder and Inorder Traversal

Given two integer arrays postorder and inorder where postorder is the postorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Input: postorder = [9,15,7,20,3], inorder = [9,3,15,20,7]
      3
     / \
    9   20
        /  \
       15   7

Output: [3,9,20,null,null,15,7]

Intuition: 
Before we dive into the algorithm, it's essential to grasp the significance of inorder and postorder traversals. Inorder traversal allows us to identify a node and its left and right subtrees, while postorder traversal ensures we always encounter the root node at last. Leveraging these properties, we can uniquely construct a binary tree. The core of our approach lies in a recursive algorithm that creates one node at a time. We locate this root node in the inorder traversal, which splits the array into the left and right subtrees.

inorder =  [40,20,50,10,60,30] (left,root,right)
            |------|    |---|
            left        right
            subtree     subtree

postorder = [40,50,20,60,30,10] (left, right, root)
            |------|  |---|  ^
                L       R    |
                            root


            

The last element of the postorder array is the root of the binary tree
and root->left in inorder array is our new left subtree i.e [40,20,50] and root->right in inorder array is our new right subtree i.e [60,30].

         10
       /    \
I [40,20,50]  [60,30]I
P [40,50,20]  [60,30]P

so our new inorder and preorder is 
inorderLeft= [40,20,50], inorderRight= [60,30]
preorderLeft=[40,50,20], preorderRight=[60,30]

Again repeat same process: 

The last element of the postorder array is the root of the binary tree

    10
    / \
   20
   / \
I [40]  [50]I
P [40]  [50]P

result: 
      10
    /    \
   20    30
  /  \   /
 40  50 60


Imagination : O=root
inorder =  [(---IL---),O,(----IR---)]
preorder = [(---PL---),(----PR---), O]

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

void preorder_traversal(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

TreeNode* buildUniqueTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>&mp){
    // Base case: If the subtree is empty, return NULL
    if(postStart > postEnd || inStart > inEnd){
        return NULL;
    }

    // Create a new TreeNode with the root value from postorder i.e is last node of postorder because (left, right,root)
    TreeNode* root = new TreeNode(postorder[postEnd]);

    // Find the index of the root value in inorder traversal
    int inRoot=mp[postorder[postEnd]];

    // Number of nodes in the left subtree
    int numsLeft = inRoot - inStart;
    
    // Recursively build the left and right subtrees
    root->left=buildUniqueTree(postorder, postStart, postStart+numsLeft-1, inorder, inStart, inRoot-1, mp);
    root->right=buildUniqueTree(postorder, postStart+numsLeft, postEnd-1, inorder, inRoot+1, inEnd , mp);

    // Return the root of the constructed subtree
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    /* Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This is because each node is processed and visited exactly once.
    Space Complexity: O(N + log2N) where N is the number of nodes in the Binary Tree.
    This complexity arises from the space used by the recursion stack during the recursive calls. In the worst case, the maximum depth of the recursion stack would be equal to the height of the Binary Tree and in the optimal case the recursion stack complexity would be O(log2N).
    */

    // Create a map to store the indices of elements in the inorder traversal
    map<int,int>mp;
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }

    // Call the recursive function to build the binary tree
    TreeNode* root = buildUniqueTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mp);
    return root; 
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int>postorder = {9,15,7,20,3};
    vector<int>inorder = {9,3,15,20,7};
    TreeNode* result=buildTree(inorder, postorder);
    preorder_traversal(result);
}