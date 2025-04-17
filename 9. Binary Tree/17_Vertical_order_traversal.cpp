/* 
Vertical Order Traversal of Binary Tree

Given a Binary Tree, return the Vertical Order Traversal of it starting from the Leftmost level to the Rightmost level. If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Input:Binary Tree: 1 2 3 4 10 9 11 -1 5 -1 -1 -1 -1 -1 -1 -1 6
Output: Vertical Order Traversal: [[4],[2, 5], [1, 10, 9, 6],[3],[11]]
Explanation: Vertical Levels from left to right:
				
Level -2: [4]
Level -1: [2]
Level 0: [1, 10, 9, 6] (Overlapping nodes are added in their level order sequence)
Level 1: [3]
Level 2: [11

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

vector<vector<int>> findVertical(Node* root){

    /*Time Complexity: O(N * log2N * log2N * log2N) where N represents the number of nodes in the Binary Tree.

            Postorder Traversal performed using BFS as a time complexity of O(N) as we are visiting each and every node once.
            Multiset Operations to insert overlapping nodes at a specific vertical and horizontal level also takes O(log2N) complexity.
            Map operations involve insertion and retrieval of nodes with their vertical and level as their keys. Since there are two nested maps, the total time complexity becomes O(log2N)*O(log2N).

    Space Complexity: O(N + N/2) where N represents the number of nodes in the Binary Tree.

            The map for storing nodes based on their vertical and level information occupies an additional space complexity of O(N) as it stores all N nodes of the Binary Tree.
            The queue for breadth first traversal occupies a space proportional to the maximum level of the tree which can be O(N/2) in the worst case of a balanced tree.
    */


    // map to store nodes based on vertical and level information {-1:{0:{1},1:{2,3,3}}}
    map<int,map<int,multiset<int>>>nodes;

    // queue for traversal, each element is in pair containing node, and its vertical and level information
    queue<pair<Node*, pair<int,int>>>q;
    
    // push root with initial vertical and level
    q.push({root,{0,0}});

    while (!q.empty()){
        // retrieve the node and its vertical and level information from front of queue
        auto p=q.front();
        q.pop();

        // extract root
        Node* temp=p.first;

        // extract vertical column no
        int x=p.second.first;

        // extract level no
        int y=p.second.second;

        // insert the node value into corresponding vertical and level in the map
        nodes[x][y].insert(temp->data);

        // Process left child
        if(temp->left){
            q.push({temp->left,{x-1,y+1}});
        }
        // Process right child
        if(temp->right){
            q.push({temp->right,{x+1,y+1}});
        }    
    }
    // prepare final result - vertical,level,data - {-2:{2:{4}} -1:{1:{2},3:{5}}}
    vector<vector<int>>ans;

    for(auto p: nodes){

        vector<int>col;
        for(auto q:p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
    return ans;   
}

void printResult(vector<vector<int>>&result){
    for(auto level:result){
        for(auto node: level){
            cout<<node<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}




int main(){
    Node* root=new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    vector<vector<int>>res=findVertical(root);
    // printResult(res);

}