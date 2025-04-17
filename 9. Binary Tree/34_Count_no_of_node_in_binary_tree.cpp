#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Count No Of Nodes in a binary tree

Given a Complete Binary Tree, count and return the number of nodes in the given tree. A Complete Binary Tree is a binary tree in which all levels are completely filled, except possibly for the last level, and all nodes are as left as possible.

Input: Binary Tree: 1 2 3 4 5 6    
        1
      /  \
     2    3
    / \   /
   4   5 6    
           
Output : 6
Explanation: There are 6 nodes in this Binary Tree.



Algorithm / Intuition: 

Given that the binary is a complete binary tree, we can exploit its properties to optimise the algorithm and achieve a better time complexity. In a complete binary tree, the last level may not be completely filled, but the nodes are positioned from left to right. This property allows us to determine the number of nodes using just the height. The relationship between the height of the binary tree (h) and the maximum number of nodes it can have, denoted by the formula: Maximum Number of Nodes: 2^h-1

If the last level of a binary tree is perfectly filled, known as a perfect binary tree, the count of nodes can be determined by the formula: 2h-1, where h is the height. To check if the last level of the Binary Tree is filled or not we can compare the left and right heights of the tree.

If the left height equals right height, it indicates that the last level is completely filled.
If the left height does not equal right height, the last level is not completely filled.

In the case where left height and right height differ, we can employ a recursive approach. We recursively calculate the number of nodes in the left subtree and in the right subtree , and then return the total count as 1 + leftNodes + rightNodes. If the height of the left subtree is equal to the height of the right subtree, we can directly calculate using the 2h-1 formula.

Step 1: Base Case If the given node is null, we return 0 as there are no nodes to count.

Step 2: Recursive Calls: Recursively find the left height and right height of the Binary Tree.

Step 3: Comparison: If the left height is equal to the right height implies that the tree’s last level is completely filled. Return the count of nodes using the formula: return (1 << lh) - 1, where << represents the left shift operator and represents the power of 2.

Step 4: If the left height is not equal to the right height implies that the tree’s last level is not completely filled. Recursively call the function to the left and right subtree and return the final number of nodes as 1 + countNodes(root->left) + countNodes(root->right)

Step 5: Implement the find left height and right height functions.

Start with the variable height set to 0.
Use a while loop to traverse the left/right side of the tree incrementing the height until reaching a leaf node.
Return the calculated height.
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

int brute_countTotalNodes(TreeNode* root){
    // Time complexity : O(n)
    // space complexity : O(n)

    queue<TreeNode*>q;
    q.push(root);
    int totalNodes=0;
    while (!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* curr=q.front();
            totalNodes+=1;
            q.pop();

            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
    return totalNodes;
}

// Function to find the left height of a tree
int findLeftHeight(TreeNode* root){
    int height=0;

    // Traverse left child until reaching the leftmost leaf
    while(root!=NULL){
        height++;
        root=root->left;
    }
    return height;
}

int findRightHeight(TreeNode* root){
    int height=0;
    while(root!=NULL){
        height++;
        root=root->right;
    }
    return height;
}

int optimal_countTotalNodes(TreeNode* root){
    /*Time Complexity: O(log N * log N) where N is the number of nodes in the Binary Tree.

        The calculation of leftHeight and rightHeight takes O(log N) time.
        In the worst case, when encountering the second case (leftHeight != rightHeight), the recursive calls are made at most log N times (the height of the tree).
        Therefore, the total time complexity is O(log N * log N).

    Space Complexity : O(H) ~ O(N) where N is the number of nodes in the Binary Tree.

        The space complexity is determined by the maximum depth of the recursion stack, which is equal to the height of the binary tree.
        Since the given tree is a complete binary tree, the height will always be log N.
        Therefore, the space complexity is O(log N).
    */

    // If the root is NULL, there are no nodes return 0
    if(root==NULL){
        return 0;
    }

    // find left height from current node
    int lh=findLeftHeight(root);

    // find right height from current node
    int rh=findRightHeight(root);

    // Check if the last level is completely filled 
    // If so, use formula = total nodes in a perfect binary tree ie. 2^h - 1
    if(lh==rh){
        return pow(2,lh)-1;
    }

    // If the last level is not completely filled, recursively count nodes in left and right subtrees if not check for 1 subtree(left) + subtree(right)
    return 1+optimal_countTotalNodes(root->left) + optimal_countTotalNodes(root->right);
}


int main(){
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    

    // brute
    cout<<brute_countTotalNodes(root)<<endl;

    // optimal
    cout<<optimal_countTotalNodes(root)<<endl;
}