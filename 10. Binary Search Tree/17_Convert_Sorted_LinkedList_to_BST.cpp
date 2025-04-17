#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Q. Convert Sorted LinkedList to Binary Search Tree

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

*/
class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(int val){
        data=val;
        next=NULL;
    }
};

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

void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int countNodes(ListNode* head) {
    // Count the number of nodes in the linked list
    int count = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

TreeNode* recursive_buildBSTfromSortedLinkedList(ListNode*& head, int n) {
    // Base case
    if (n <= 0 || head == nullptr) {
        return nullptr;
    }

    // Construct left subtree
    TreeNode* left = recursive_buildBSTfromSortedLinkedList(head, n / 2);

    // Create root node
    TreeNode* root = new TreeNode(head->data);
    root->left = left;

    // Move head to the next node in the list
    head = head->next;

    // Construct right subtree
    root->right = recursive_buildBSTfromSortedLinkedList(head, n - n / 2 - 1);

    return root;
}

TreeNode* recursive_sortedListToBST(ListNode* head) {
    // Time complexity: O(n)
    // space complexity: O(1)


    // Convert sorted linked list to BST
    int n = countNodes(head);
    return recursive_buildBSTfromSortedLinkedList(head, n);
}



// ------------------------------------------------------------------------------



TreeNode* bulidTree(vector<int>& inorder, int start, int end){
    if(start>end){
        return NULL;
    }

    // Find mid to create our new node
    int mid=(start+end)/2;

    // creating new node
    TreeNode* root=new TreeNode(inorder[mid]);

    root->left=bulidTree(inorder, start, mid-1);
    root->right=bulidTree(inorder, mid+1, end);

    return root;
}

TreeNode* iterative_sortedListToBST(ListNode* head) {
    // Time complexity: O(n)
    // space complexity: O(n) we are using extra O(n) to store linkedlist element 

    /* Intuition - same question like -> construct a bst from inorder
   
    But here we have to construct a bst from linkedList

        1. Create a vector and store all the elements of linked list.
        2, Now find the middle element of the linked list and create it root of the tree and call for left array and right array for left and right child.
        3. Now recursively repeat above approach until the start becomes greater than end.
    */

    vector<int> vector;
    ListNode* temp = head;
    int noOfNodes=0;
    while(temp != NULL){
        noOfNodes++;
        vector.push_back(temp->data);
        temp = temp->next;
    }

    // vlaue store krke bst bana liya
    TreeNode* newTree = bulidTree(vector, 0, noOfNodes-1);
    return newTree;
}




int main(){
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);


    // recursive solution
    TreeNode* root1 = recursive_sortedListToBST(head);
    inorder(root1);
    cout<<endl;



    // iterative solution
    TreeNode* root = iterative_sortedListToBST(head);
    inorder(root);
}