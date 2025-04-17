#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Q. Merge 2 BST

Given two BSTs, return elements of merged BSTs in sorted form.

Input: root1 = [5, 3, 6, 2, 4]

      5
     / \
    3   6
   / \
  2   4

root2 = [2, 1, 3, N, N, N, 7, 6, N]

      2
     / \
    1   3
         \
          7
         /
        6

Output: [1, 2, 2, 3, 3, 4, 5, 6, 6, 7]
Explanation: After merging and sorting the two BST we get [1, 2, 2, 3, 3, 4, 5, 6, 6, 7].

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

void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void inorderTraversal(TreeNode* root ,vector<int>& inorderContainer){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left, inorderContainer);
    inorderContainer.push_back(root->val);
    inorderTraversal(root->right, inorderContainer);
}

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

vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size();
    int m=nums2.size();

    vector<int>result;

    int i=0, j=0;
    while(i<n && j<m){
        if(nums1[i] <= nums2[j]){
            result.push_back(nums1[i]);
            i++;
        }else{
            result.push_back(nums2[j]);
            j++;
        }
    }
    while(i<n){
        result.push_back(nums1[i]);
        i++;
    }
    while(j<n){
        result.push_back(nums2[j]);
        j++;
    }
    return result;     
}

TreeNode* brute_merge_2_BST(TreeNode *root1, TreeNode *root2) {
    // Time complexity: O(m+n)
    // Space complexity: O(m+n) 

    /*Intuition: 
    1. traverse both the tree and store their value in 2 seperate vector.
    2. use merge function to merge the both sorted array.
    3. bulid the tree with sorted array. (Question becomes construct a BST tree from inorder)
    */

    // 1. Traverse tree to store element 
    vector<int>inorder1;
    vector<int>inorder2;
    inorderTraversal(root1, inorder1);
    inorderTraversal(root2, inorder2);

    // 2. merge both sorted array to build BST
    vector<int>mergeArray = merge(inorder1, inorder2);

    // 3. build the tree
    TreeNode* root = bulidTree(mergeArray, 0, mergeArray.size()-1);

    // return new merge tree
    return root;
}



// --------------------------------------------------------------------------------------------------------------



TreeNode* binaryTreeToSortedLinkedList(TreeNode* root) {
    // Time complexity: O(n), where n is the number of nodes in the binary tree.
    // space complexity: O(1)

    if (root == NULL) {
        return NULL;
    }

    TreeNode* curr = root;

    // Head of the flattened list
    TreeNode* head = NULL; 

    // Keeps track of the last processed node
    TreeNode* prev = NULL;

    while (curr != NULL) {
        if (curr->left == NULL) {
            // Process the current node
            if (head == NULL) {
                // Set head on the first encountered node
                head = curr; 
            }
            if (prev != NULL) {
                // Link previous node to current node
                prev->right = curr; 
            }

            // Move prev pointer
            prev = curr; 
            
            // Move to the right subtree
            curr = curr->right; 
        } 
        else {
            // Find the inorder predecessor (rightmost node in the left subtree)
            TreeNode* pred = curr->left;
            while (pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == NULL) {
                // Establish a temporary link and move left
                pred->right = curr;
                curr = curr->left;
            } else {
                // Remove the temporary link
                pred->right = NULL;

                // Process current node
                if (head == NULL) {
                    head = curr;
                }
                if (prev != NULL) {
                    prev->right = curr;
                }
                prev = curr;

                // Set left to NULL to break cycles
                curr->left = NULL;
                
                // Move to the right subtree
                curr = curr->right; 
            }
        }
    }
    return head; // Return the head of the flattened list
}

TreeNode* mergeLinkedList(TreeNode* head1, TreeNode* head2){
    // Time complexity: O(n), where n is the number of nodes in the binary tree.
    // space complexity: O(1)
    TreeNode* head=NULL;
    TreeNode* tail=NULL;

    while(head1!=NULL && head2!=NULL){
        if(head1->val < head2->val){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;

            }else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;
            }else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }

        }
    }

    while(head1!=NULL){
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }
    while(head2!=NULL){
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;
    }

    return head;
}

int countNodes(TreeNode* head){
    // Time complexity: O(n), where n is the number of nodes in the binary tree.
    // space complexity: O(1)
    int count=0;
    TreeNode* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->right;
    }
    return count;
}

TreeNode* buildBSTfromSortedLinkedList(TreeNode* &head, int n){
    // Time complexity: O(n), where n is the number of nodes in the binary tree.
    // space complexity: O(1)

    if(n<=0 || head==NULL){
        return NULL;
    }

    TreeNode* left=buildBSTfromSortedLinkedList(head, n/2);
    TreeNode* root=head;
    root->left=left;
    head=head->right;

    root->right=buildBSTfromSortedLinkedList(head, n-n/2-1);
    return root;
}

TreeNode* optimal_merge_2_BST(TreeNode *root1, TreeNode *root2){
    /* 
    Time complexity: O(n1 + n2)
        Step 1: O(n1 + n2)
        Step 2: O(n1 + n2)
        Step 3: O(n1 + n2)
        Step 4: O(n1 + n2)

    space complexity: O(h1+h2) height of tree1 + tree2
        Step 1: O(1)
        Step 2: O(1)
        Step 3: O(1)
        Step 4: O(h1+h2) (recursion stack depth)
    */ 


    // 1. Convert BST into sorted linkedlist
    TreeNode* head1 = binaryTreeToSortedLinkedList(root1);
    head1->left=NULL;

    TreeNode* head2 = binaryTreeToSortedLinkedList(root2);
    head2->left=NULL;


    // 2. function to merge both sorted linkedList
    TreeNode* head = mergeLinkedList(head1, head2);


    // 3. Function to convert sorted linkedList into BST
    TreeNode* result = buildBSTfromSortedLinkedList(head, countNodes(head));

    return result;
}



int main(){
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->right = new TreeNode(6);
    
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->right->right = new TreeNode(7);
    root2->right->right->left = new TreeNode(6);


    
    // brute
    TreeNode* result1 = brute_merge_2_BST(root1, root2);
    inorder(result1);
    cout<<endl;

    // optimal
    TreeNode* result = brute_merge_2_BST(root1, root2);
    inorder(result);
}