#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Input: root = [1,2,3,null,null,4,5]
        1
       /  \
      2    3
          / \
         4   5
Output: [1,2,3,null,null,4,5]

Algorithm:

Serialisation:
    Step 1: Check if the tree is empty: If the root is null, return an empty string.

    Step 2: Initialise an empty string: This string will store the serialised binary tree.

    Step 3: Use a queue for level-order traversal: Initialise a queue and enqueue the root.

    Step 4: Within the level-order traversal loop:

    Dequeue a node from the queue.
    If the node is null, append "#" to the string.
    If the node is not null, append its data value along with a ‘,’ (comma) to the string. This comma acts as a delimiter that separates the different node values in the string. Enqueue its left and right children.

    Step 5: Return the final string containing the serialised representation of the tree.

    Final string = [1,2,3,#,#,4,5,#,#,#,#]

Deserialization: 
    Step 1:Check if the serialised data is empty: If it is, return null.

    Step 2: Tokenize the serialised data: Use a stringstream to tokenize the input string using the comma as a delimiter.

    Step 3: Read the root value: Read the first token and create the root node with this value.

    Step 4: Use a queue for level-order traversal: Initialise a queue and enqueue the root.

    Step 5: Within the level-order traversal loop:

        Dequeue a node from the queue.
        Read the value for the left child from the stringstream.
        If it is "#", set the left child to null. If it's not "#", create a new node with the value and set it as the left child.
        Read the next value in the stringstream for the right child.
        If it is "#", set the right child to null. If it's not "#", create a new node with the value and set it as the right child.
        Enqueue the left and right children into the queue for further traversal.

    Step 6: Return the reconstructed root: The final result is the root of the reconstructed tree.
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

void inorder(TreeNode* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout << root->data <<" ";
    inorder(root->right);
}

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    // check if tree is empty
    if(root==NULL){
        return "";
    }

    // Initialize an empty string to store serialized data
    string s="";

    // use a queue for level order traversal
    queue<TreeNode*>q;

    // start with tree node
    q.push(root);

    // Perform level order travversal
    while (!q.empty()){
        // Get front node from queue
        TreeNode* currNode=q.front();
        q.pop();

        // Check if the current node is null and append "#" to the string
        if(currNode==NULL){
            s+="#,";
        }else{ 
            // Append the value of the current node to the string
            s += to_string(currNode->data)+",";

            // Push the left and right children to the queue for further traversal
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }

    // Return the serialized string
    return s;    
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    // Check if the serialized data is empty
    if(data==""){
        return NULL;
    }

    // Use a stringstream to tokenize the serialized data
    stringstream s(data);
    string str;

    // Read the root value from the serialized data
    getline(s,str,',');
    TreeNode* root=new TreeNode(stoi(str));

    // Use a queue for level-order traversal
    queue<TreeNode*>q;

    // Start with the root node
    q.push(root);
    
    // Perform level order traversal to reconstruct the tree
    while(!q.empty()){
        // Get the front node in the queue
        TreeNode* currNode=q.front();
        q.pop();
        
        // Read the value of the left child from the serialized data
        getline(s, str, ',');

        // If the value is not "#", create a new left child and push it to the queue
        if(str!="#"){
            TreeNode* leftNode = new TreeNode(stoi(str));
            currNode->left=leftNode;
            q.push(leftNode);
        }

        // Read the value of the right child from the serialized data
        getline(s, str, ',');

        // If the value is not "#", create a new right child and push it to the queue
        if(str!="#"){
            TreeNode* rightNode = new TreeNode(stoi(str));
            currNode->right=rightNode;
            q.push(rightNode);
        }
    }

    // Return the reconstructed root of the tree
    return root; 
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string s = serialize(root);
    TreeNode* ans = deserialize(s);
    inorder(ans);

    /*Time Complexity: O(N)

        serialize function: O(N), where N is the number of nodes in the tree. This is because the function performs a level-order traversal of the tree, visiting each node once.

        deserialize function: O(N), where N is the number of nodes in the tree. Similar to the serialize function, it processes each node once while reconstructing the tree.

    Space Complexity: O(N)

        serialize function: O(N), where N is the maximum number of nodes at any level in the tree. In the worst case, the queue can hold all nodes at the last level of the tree.
        
        deserialize function: O(N), where N is the maximum number of nodes at any level in the tree. The queue is used to store nodes during the reconstruction process, and in the worst case, it may hold all nodes at the last level.
    */
}   
