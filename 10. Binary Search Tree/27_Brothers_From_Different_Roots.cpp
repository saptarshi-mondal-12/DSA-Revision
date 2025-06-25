#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Brothers From Different Roots

Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x, your task is to complete the function countPairs(), that returns the count of all pairs of (a, b), where a belongs to one BST and b belongs to another BST, such that a + b = x.

Example 1:

Input: BST1:
       5
     /   \
    3     7
   / \   / \
  2   4 6   8

BST2:
       10
     /    \
    6      15
   / \    /  \
  3   8  11   18

x = 16
Output: 3
Explanation: The pairs are: (5, 11), (6, 10) and (8, 8)
*/

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


// Brute -------------------------------------------------------------------------------------

void getValues(Node *root, vector<int> &inorder){
    if (root == NULL)
        return;

    getValues(root->left, inorder);
    inorder.push_back(root->data);
    getValues(root->right, inorder);
}
int countPairs(Node *root1, Node *root2, int x){
    // Time complexity: O(n+m) + O(n*m)
    // Space comppexity: O(n+m)

    /* Intuition: 
        1. Get value from both tree and store in a vector.
        2. count pair using 2 for loop
    */

    vector<int> inorder1;
    vector<int> inorder2;

    getValues(root1, inorder1);
    getValues(root2, inorder2);

    int totalPairs = 0;

    for (int i = 0; i < inorder1.size(); i++){
        for (int j = 0; j < inorder2.size(); j++){
            if (inorder1[i] + inorder2[j] == x){
                totalPairs++;
            }
        }
    }
    return totalPairs;
}




// Optimal -----------------------------------------------------------------------------------

int optimal_countPairs(Node *root1, Node *root2, int x){
    // Time complexity: O(n+m) + O(n+m)
    // Space comppexity: O(n+m)

    /* Intuition: 
        1. Get value from both tree and store in a vector.
        2. count pair using 2 pointer
            a. First pointer ie start --> 0th index of inorder1
            b. second pointer ie end --> m-1 th index of inorder2 where m = inorder2.size()
    */

    vector<int> inorder1;
    vector<int> inorder2;

    getValues(root1, inorder1);
    getValues(root2, inorder2);

    int totalPairs = 0;

    // inorder 1 - ascending order
    // 2 3 4 5 6 7 8       
        
    // inoder 2 - ascending  order
    // 3 6 8 10 11 15 18
        
    int n=inorder1.size();
    int m=inorder2.size();
        
    int start=0, end=m-1;
        
    while(start<n && end>=0){
        int currSum=inorder1[start] + inorder2[end];
            
        if(currSum == x){
            totalPairs++;
            start++;
            end--;
        }
        else if(currSum > x){
            end--;
        }
        else if(currSum < x){
            start++;
        }
    }
    return totalPairs;
}




int main(){
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);

    Node* root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(15);
    root2->left->left = new Node(3);
    root2->left->right = new Node(8);
    root2->right->left = new Node(11);
    root2->right->right = new Node(18);

    int x=16;

    // brute
    cout<<countPairs(root1, root2, x)<<endl;

    // Optimal
    cout<<optimal_countPairs(root1, root2, x)<<endl;
}
