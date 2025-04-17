/* 
Average of Levels in Binary Tree

Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.

Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].

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


vector<double> averageOfLevels(Node* root) {
    vector<double>result;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int count=0;
        int size=q.size();
        long long int totalSum=0;

        for(int i=0;i<size;i++){
            Node* node=q.front();
            q.pop();
            totalSum+=node->data;
            count++;

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        double avg = (double)totalSum / count;
        result.push_back(avg);
    }
    return result;
}


void printResult(vector<double>&result){
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}


int main(){
    Node* root=new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);

    root->right = new Node(3);
    root->right->right = new Node(7);

    vector<double>res=averageOfLevels(root);
    printResult(res);
}