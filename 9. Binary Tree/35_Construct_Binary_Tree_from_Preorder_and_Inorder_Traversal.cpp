#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
      3
     / \
    9   20
        /  \
       15   7

Output: [3,9,20,null,null,15,7]

Intuition: 
Before we dive into the algorithm, it's essential to grasp the significance of inorder and preorder traversals. Inorder traversal allows us to identify a node and its left and right subtrees, while preorder traversal ensures we always encounter the root node first. Leveraging these properties, we can uniquely construct a binary tree. The core of our approach lies in a recursive algorithm that creates one node at a time. We locate this root node in the inorder traversal, which splits the array into the left and right subtrees.

inorder =  [40,20,50,10,60,30] (left,root,right)
            |------|    |---|
            left        right
            subtree     subtree

preorder = [10,20,40,50,30,60] (root, left, right)
            ^
            |
           root

The first element of the preorder array is the root of the binary tree
and root->left in inorder array is our new left subtree and root->right in inorder array is our new right subtree.

         10
       /    \
I [40,20,50]  [60,30]I
P [20,40,50]  [30,60]P

so our new inorder and preorder is 
inorderLeft= [40,20,50], inorderRight= [60,30]
preorderLeft=[20,40,50], preorderRight=[30,60]

Again repeat same process: 
The first element of the preorder array is the root of the binary tree

    10
    / \
   20
   / \
  40  50

process right part i.e inorderRight, preorderRight
The first element of the preorder array is the root of the binary tree

      10
    /    \
   20     30
   / \    /
  40 50  60


Imagination : O=root
inorder =  [(---IL---),O,(----IR---)]
preorder = [O,(---PL---),(----PR---)]


Algorithm:
Step 1:Create an empty map to store the indices of elements in the inorder traversal. 

Step 2: Create a recursive helper function `buildUniqueTree` with the following parameters:

    Preorder vector
    Start index of preorder (preStart), initially set to 0
    End index of preorder (preEnd), initially set to preorder.size() - 1.
    Inorder vector
    Start index of inorder (inStart), initially set to 0.
    End index of inorder (inEnd), initially set to inorder.size() - 1.
    Map for efficient root index lookup in the inorder traversal.

Step 3: Base Case: Check if preStart is greater than preEnd or inStart is greater than inEnd. If true, return NULL, indicating an empty subtree/node.

Step 4: The root node for the current subtree is the first element in the preorder traversal (preorder[preStart]). Find the index of this root node in the inorder traversal using the map (inMap[rootValue]). This is the rootIndex.

Step 5: Hence, the left subtree ranges from inStart to rootIndex. Subtracting these indexes gives us the leftSubtreeSize.

Step 6: TMake two recursive calls to buildTree to build the left and right subtrees: 
    For the left subtree:
        Update preStart to preStart + 1 (moving to the next element in preorder)
        Update preEnd to preStart + leftSubtreeSize (end of left subtree in preorder)
        Update inEnd to rootIndex - 1 (end of left subtree in inorder)

    For the right subtree:
        Update preStart to preStart + leftSubtreeSize + 1 (moving to the next element after the left subtree)
        Update preEnd to the original preEnd (end of right subtree in preorder)
        Update inStart to rootIndex + 1 (start of right subtree in inorder)

Step 7: Return the root node constructed for the current subtree. The function returns the root of the entire binary tree constructed from the preorder and inorder traversals.

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

TreeNode* buildUniqueTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>&mp){
    // Base case: If the start indices exceed the end indices, return NULL
    if(preStart > preEnd || inStart > inEnd){
        return NULL;
    }

    // Create a new TreeNode with value at the current preorder index
    TreeNode* root=new TreeNode(preorder[preStart]);

    // Find the index of the current root value in the inorder traversal
    int rootIndex=mp[root->data];

    // Calculate the number of elements in the left subtree in inorder
    int numLeft=rootIndex-inStart;

    // Recursively build the left subtree
    root->left=buildUniqueTree(preorder, preStart+1, preStart+numLeft, inorder, inStart, rootIndex-1, mp);

    // Recursively build the right subtree
    root->right=buildUniqueTree(preorder, preStart+numLeft+1, preEnd, inorder, rootIndex+1, inEnd, mp);

    // Return the current root node
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    /*Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This is because each node of the Binary Tree is visited once.
    Space Complexity: O(N) where N is the number of nodes in the Binary Tree. The inorder hashmap to store the inorder array for fast lookup takes up space proportional to the input nodes. 
    */

    // Create a map to store indices of elements in the inorder traversal
    map<int, int>mp;

    // Populate the map with indices of elements in the inorder traversal
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }

    // Call the private helper function to recursively build the tree
    TreeNode* root=buildUniqueTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);

    return root;  
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int>preorder = {3,9,20,15,7};
    vector<int>inorder = {9,3,15,20,7};
    TreeNode* result=buildTree(preorder, inorder);
    preorder_traversal(result);
}