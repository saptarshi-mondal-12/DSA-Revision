#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q. Given a binary tree, you need to find a pair of two nodes such that their sum of values is equal to target. - Amazon 

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
    // Time complexity : O(n^2) due to repeated LCA and distance calculation.
    // space complexity : O(n) due to the map and queue

    /* Intuition: 
    To solve the problem, I use a level-order traversal (BFS) to visit each node in the binary tree. While traversing, I maintain a map that stores the value of each node along with the level at which it was encountered.

    For every node during traversal, I calculate the value needed to form the target sum:
        required = target - current_node->val

    I then check if this required value already exists in the map. If it does, I perform additional checks:

        Different Levels: Ensure that the two nodes are not on the same level.
        Exact Distance: Use the findDistanceBetweenNodes() function to calculate the actual distance between these two nodes.
        Distance Match: If the calculated distance is exactly equal to d, I have found a valid pair and return true.

    Conclusion:
    For a pair of nodes to be valid:
        The sum of their values must equal the target.
        The two nodes must be at different levels in the tree.
        The distance between them must be exactly d.

    If all three conditions are satisfied, I return true.
    */

    if(root==NULL){
        return false;
    }

    // map to store node and their level;
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









// Optimal Soln ------------------------------------------------------------------------------------ 

int calculate_Distance_Between_Nodes(TreeNode* root, int u, int v, unordered_map<int,int>mp){

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

        level[4] = 2, level[5] = 2, LCA(4, 5) = 2 → distance = 2 + 2 − 2×1 = 2
        Path: 4 → 2 → 5 (2 edges) ✅

        So this formula gives the exact number of edges between two nodes using their levels and LCA — without needing to traverse the path between them every time.
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
            // if it is present - then check for level, both level should be dfferent.
            // If both level are different - then check if distance between these 2 node is equal to d
            // if all true we find our pair
            if(mp.find(required) != mp.end()){
                // check if both are in different level
                if (mp[curr->val] != mp[required]){
                    int distance = calculate_Distance_Between_Nodes(root, curr->val, required, mp);

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