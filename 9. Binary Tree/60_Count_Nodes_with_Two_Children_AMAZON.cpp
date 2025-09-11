#include<bits/stdc++.h>
using namespace std;


/* Q. Count Nodes with Two Children - Amazon 2025

Count the number of nodes in a binary tree that have both left and right children.
*/

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int countNode(Node* root){
    // Time Complexity: O(n) (each node is visited once)
    // Space Complexity: O(n) (queue can hold up to n/2 nodes in worst case, for a full binary tree)

    int result=0;

    if(root == NULL) return 0;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        // Push children into queue
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
        
        // Check if both children exist
        if(node->left != NULL && node->right != NULL){
            result++;
        }
    }

    return result;
}

int main(){
    Node* root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<countNode(root)<<endl;

}