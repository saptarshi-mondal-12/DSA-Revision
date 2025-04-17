#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

bool check(TreeNode* &root){
    queue<TreeNode*>q;
    q.push(root);

    int leafPosition = -1;
    int flag = true;

    int level=0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }

            if(curr->left == NULL && curr->right == NULL){
                if(flag){
                    leafPosition=level;
                    flag = false;
                }else{
                    if (leafPosition != level){
                        return false;
                    }
                }
            }
        }
        level++;
    }
    return true;
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    /* 
         1
        /  \
       2    3
      / \  / \
     4   5 6  7
    */
    cout<<endl;
    if(check(root)){
        cout<<"True : Leaves are at same level"<<endl;
    }else{
        cout<<"False : Leaves are not at same level"<<endl;
    }
}