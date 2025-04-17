#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q. Given a binary tree, you need to find a pair of two nodes such that their sum of values is equal to target.

Constraints:
1: distance between two nodes should be equal to d
2: both nodes should not be at same level

return true if found any such pair of nodes
Note: tree can contain duplicate values


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

TreeNode* findLCA(TreeNode* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (root->val == n1 || root->val == n2) return root;

    TreeNode* leftLCA = findLCA(root->left, n1, n2);
    TreeNode* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA) return root;  // If both left and right have values, root is LCA

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int findDistanceFromLCA(TreeNode* root, int target, int count) {
    if (root == NULL) return -1;

    if (root->val == target) return count;

    int left = findDistanceFromLCA(root->left, target, count + 1);
    if (left != -1) return left;

    return findDistanceFromLCA(root->right, target, count + 1);
}

int findDistanceBetweenNodes(TreeNode* root, int n1, int n2) {
    TreeNode* lca = findLCA(root, n1, n2);
    
    if (lca == NULL) return -1; // If either node is missing

    int d1 = findDistanceFromLCA(lca, n1, 0);
    int d2 = findDistanceFromLCA(lca, n2, 0);

    return d1 + d2; // Total distance between n1 and n2
}

bool findPair(TreeNode* root, int target, int d) {
    // Time complexity : O(n^2)
    // space complexity : O(n) due to the map and queue

    /* Intuition: 
    I perform a level order traversal  and check for each node if target - curr_node->val is present in my map or not 

    if it is present I will find between 2 nodes,  
    if level are different then I find the distance bewteen 2 nodes and if distance is equal to given d I simple found my pair 
    so return answer. 
    
    conclusion :
    1. I found 2 node equal to given target.
    2. I found 2 node are at different level
    3. I found 2 node are at a distance equal to d. 
    */

    if(root==NULL){
        return false;
    }

    // map to store node and level;
    unordered_map<int, int>mp;
    
    queue<TreeNode*>q;
    q.push(root);
    int level=0;

    // performing level order traversal
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* curr=q.front();
            q.pop();
            int required = target - curr->val;
            mp[curr->val]=level;

            if(mp.find(required) != mp.end()){
                // check if both are in different level
                if (mp[curr->val] != mp[required]){
                    int distance = findDistanceBetweenNodes(root, curr->val, required);

                    // check if distance between 2 nodes is equal to d
                    if(distance==d){
                        cout<<curr->val<<" "<<required<<endl;
                        return true;
                    }
                }
            }

            if(curr->left){
                q.push(curr->left);
            }

            if(curr->right){
                q.push(curr->right);
            }
        }
        level++;
    }
    return false;
}


// ------------------------------------------------------------------------------------ 

int calculateDistance(TreeNode* root, int u, int v, unordered_map<int,int>mp){

    // lowest common ancesstor of 2 node u and v
    TreeNode* LCA = findLCA(root,u,v);

    if(LCA == NULL){
        return -1;
    }

    // Disatnce between 2 node
    int distance = mp[u] + mp[v] - 2*mp[LCA->val];
    return distance;
}


bool optimal_findPair(TreeNode* root, int target, int d){
    // Time complexity: O(n)
    // Space complexity: O(n)

    /* Intuition: 

    In the brute solution, the findDistanceBetweenNodes function is called for every valid pair, which involves finding the LCA and then calculating the distance. This makes the time complexity O(n^2) in the worst case.

    Optimization: 

         1
        /  \
       2    3
      / \  / \
     4   5 6  7

    formula for Disatnce between 2 node: 

        distance = (level[u] + level[v] − 2×level[LCA(u,v)])

        E.g u=4, v=5 
        distance = 2 + 2 - 2*1 = 2

        Q. Why we use 2×level[LCA(u,v)] ?
        Ans: if i use (level[u] + level[v]) then distance becomes 4 (see in diagram) which is wrong, correct ans is 2 that's wgy we use 2×level[LCA(u,v)].
    */

    if(root==NULL){
        return false;
    }

    // map to store node and level;
    unordered_map<int, int>mp;
    
    queue<TreeNode*>q;
    q.push(root);
    int level=0;

    // performing level order traversal
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* curr=q.front();
            q.pop();

            // searching for required in map to form pair - (required, curr->val)
            int required = target - curr->val;

            // map the current node with its level in  
            mp[curr->val]=level;

            // check if required is present in map. 
            // if present check for its level, if level are dfferent.
            // check if distance between these 2 node is equal to d
            // if all true we find our pair
            if(mp.find(required) != mp.end()){
                // check if both are in different level
                if (mp[curr->val] != mp[required]){
                    int distance = calculateDistance(root, curr->val, required, mp);

                    // check if distance between 2 nodes is equal to d
                    if(distance==d){
                        // we find our pair
                        cout<<curr->val<<" "<<required<<endl;
                        return true;
                    }
                }
            }

            // insert left to queue
            if(curr->left){
                q.push(curr->left);
            }

            // insert right to queue
            if(curr->right){
                q.push(curr->right);
            }
        }

        // increment level
        level++;
    }

    // no pair found
    return false;

}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    /* 
         1
        /  \
       2    3
      / \  / \
     6   6 6  7

    */
    
    int target = 7;
    int d = 2;

    // 1. brute solution
    bool brute_result=findPair(root, target, d);
    if (brute_result){
        cout<<"Pair found"<<endl;
    }else {
        cout<<"No pair found"<<endl;
    }

    // ------------------------------------------

    // 2. optimal solution
    bool result=optimal_findPair(root, target, d);
    if (result){
        cout<<"Pair found"<<endl;
    }else {
        cout<<"No pair found"<<endl;
    }
}