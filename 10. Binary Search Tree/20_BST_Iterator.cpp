#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Binary Search Tree Iterator

Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):
    ✅ BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
    ✅ boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
    ✅ int next() Moves the pointer to the right, then returns the number at the pointer.
    Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.
You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.


Input: ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output: [null, 3, 7, true, 9, true, 15, true, 20, false]
          7
        /  \
       3    15
            / \
           9   20

Explanation:
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False


Expalnation with example :
Intuition: use stack LIFO operation

        7
      /   \
     3     10
    / \    /
   2   6  9
  /   /  /
 1   5  8
    /
   4

[7,3,2,1] , top = 1, pop and retun 1, now stack = [7,3,2] again top=2 , pop and return 2 (i.e next smallest)

BSTiterator(7)
next = 1
next = 2
next = 3
hasNext() = true
next = 4
next = 5
next = 6
next = 7
next = 8
next = 9
next = 10

*/

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

// brute solution
class BSTIterator {   
public: 
    // storing element of BST (inorder -> sorted)
    vector<int>inorder;
    
    // store size of inorder
    int size;
    
    // starting point
    int nextPointer;
    
    // Performing inorder traversal for storing element 
    void inorderTraversal(TreeNode* root, vector<int>&inorder){
        if(root==NULL){
            return;
        }
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
    
    // constructor 
    BSTIterator(TreeNode* root) {
        inorderTraversal(root, inorder);
        size = inorder.size();
        nextPointer=0;
    }
        
    // return val at next
    int next() {
        if(hasNext()){
            int i=nextPointer;
            nextPointer++;
            return inorder[i];
        }
        return -1;
    }
        
    // check whether we have a next smallest number 
    bool hasNext() {
        if(nextPointer < size){
            return true;
        }else{
            return false;
        }   
    }
};


// ---------------------------------------------------------------------------------------


// optimal solution
class BSTIterator { 
    // Time complexity: O(1)
    // Space complexity: O(h)  
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    // return the next smallest number 
    int next() {
        TreeNode* curr=st.top();
        st.pop();
        pushAll(curr->right);
        return curr->val;  
    }

    // check whether we have a next smallest number 
    bool hasNext() {
        return !st.empty(); 
    }

    void pushAll(TreeNode* node){
        /* push extreme left till we get a null. 
        for eg. suppose we are at node 7. pushing all of its left is [7,3,2,1]. See in diagram
        or we are at node 6. pushing all left is [7,6,5,4] 
        */
        while(node!=NULL){
            st.push(node);
            node=node->left;
        }
    }
};

int main(){
    
    TreeNode* root = new TreeNode(8);
    
    // Left subtree
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    // Right subtree
    root->right = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

 
    /* 1. brute - TC=O(1) , SC=O(n)
    Intuition: We Use vector and store inorder traversal of BST and keep a pointer next at start of vector.
    So Whenever we call next() return val at next (return inorder[next]) and move pointer next to ahead +1. 
    */



    /* 2. optimal solution - TC=O(1), TC=O(h) if we observe carefully we use only a height of some tree.  
    Intuition: If i follow the property of inorder traversal i.e (left, root, right). then we can solve without using an extra O(n) space. All operation takes O(1) time compelxity
    
    we use a stack data structure and for every node we move to extreme left and store value in stack.
    (left, node , right)
    For eg. Suppose we are at node 7, Going to extreme left means and store element look like -> stack=[7,3,2,1] , now top = 1, pop the top and retun 1, now stack = [7,3,2] again top=2 , pop and return 2 (i.e next smallest). so on . 
    */


    
}
