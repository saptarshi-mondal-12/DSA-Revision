#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q. Given a binary tree, you need to find a pair of two nodes such that their sum of values is equal to target. - Amazon 

Constraints:
1: distance between two nodes should be equal to d
2: both nodes should not be at same level
3. node1->val + node2->val == target

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

// Brute Force Approach --------------------------------------------------------------------------------------------------------

TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return NULL;

    if (root == p || root == q) return root;

    TreeNode* left = findLCA(root->left, p, q);
    TreeNode* right = findLCA(root->right, p, q);

    if (left && right) return root;
    return left ? left : right;
}

int calculate_Distance_Between_Nodes(TreeNode* root, TreeNode* p, TreeNode* q,unordered_map<TreeNode*, int> &levelMap){
    TreeNode* LCA = findLCA(root, p, q);
    if (!LCA) return -1;

    int distance = levelMap[p] + levelMap[q] - 2 * levelMap[LCA];
    return distance;
}

bool brute_findPair(TreeNode* root, int target, int d){
    /* Time complexity: O(n^3)
            1️⃣ Level order traversal = O(n)
            2️⃣ Outer Loop over Map Entries = O(n) In worst case, all node values are distinct. So number of keys in mp = n
            3️⃣ Nested Loops Over Node Pairs = n × n = O(n²)
            4️⃣ Distance Calculation per Pair = O(n)
            Total Time Complexity = O(n) + O(n² × n)  // pair checks × LCA
                                  = O(n³)


       Space complexity: O(n)
            1️⃣ Queue for BFS = O(n)
            2️⃣ Value → Nodes Map = O(n)
            3️⃣ Level Map = O(n)
            4️⃣ Recursion Stack for LCA = O(h) = O(n) in worst case (skewed tree)
            Total Space Complexity = O(n) + O(n) + O(n) + O(n)
                                   = O(n)
    */

    /*Intuition : 
    
        The tree can contain duplicate values, so we cannot rely on values alone to identify nodes.
        Instead, we treat each node as a unique object using its pointer (TreeNode*).

        The problem has three simultaneous constraints:

            1. The sum of node values must be equal to target
            2. The distance between the two nodes must be exactly d
            3. The two nodes must be at different levels

        To handle all three constraints safely and correctly:

            We first store every node with its level
            We group nodes by their values to handle duplicates
            We then try all valid (value, target − value) combinations
            For each candidate pair, we verify:
                they are different nodes
                they are at different levels
                their distance (using LCA) is exactly d

        If any such pair satisfies all constraints, we return true.

        Step 1: Level Order Traversal (Preprocessing)

        Perform level order traversal (BFS) of the tree.
        For each node:

            Store it in a map as
            value → { (level, node pointer) }

            Store its level in levelMap using
            TreeNode* → level

        This preprocessing allows:
            Handling duplicate values
            Fast access to node levels
            Safe distance calculation later

        Step 2: Form Candidate Value Pairs

            For each unique value val1 in the map:
                Compute required = target - val1
                If required does not exist in the map, skip

        This ensures we only check value pairs that can sum to target.

        Step 3: Validate Node Pairs

        For each node pair (node1, node2) where:
            node1->val + node2->val == target

        Check constraints in order:

            1. Nodes must be at different levels
            if(p1.first == p2.first) continue;

            2. Distance between nodes must be exactly d
                Find LCA using pointer-based LCA
                Use level formula:
                    distance = level[node1] + level[node2] − 2 × level[LCA]

        If all checks pass → pair found.

        Step 4: Return Result
            If any valid pair is found → return true
            If all possibilities are exhausted → return false

    */

    if(root==NULL){
        return false;
    }

    // {4 → { level 1 : node(4), level 2 : node(4) }
    unordered_map<int, vector<pair<int, TreeNode*>>> mp;
    unordered_map<TreeNode*, int> levelMap;

    queue<TreeNode*> q;
    q.push(root);
    int level = 1;

    // performing level order traversal
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* curr = q.front();
            q.pop();

            // map the current node with its level
            mp[curr->val].push_back({level, curr});
            levelMap[curr] = level;

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

    // searching for required in map to form pair - (required, curr->val)
    for(auto &x : mp){
        int val1 = x.first;
        int required = target - val1;

        if(mp.find(required) == mp.end()) continue;

        for(auto &p1 : mp[val1]){
            for(auto &p2 : mp[required]){
                TreeNode* node1 = p1.second;
                TreeNode* node2 = p2.second;


                // both level should be different
                if(p1.first == p2.first) continue;

                // check if distance between these 2 node is equal to d
                int distance = calculate_Distance_Between_Nodes(
                    root, node1, node2, levelMap
                );

                if(distance == d){
                    cout << node1->val << " " << node2->val << endl;
                    return true;
                }
            }
        }
    }

    // no pair found
    return false;
}



// Optimal Approach --------------------------------------------------------------------------------------------------------

void buildInfo(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent, unordered_map<TreeNode*, int> &levelMap, unordered_map<int, vector<TreeNode*>> &mp){

    /* Preprocessing:
        - parent of each node
        - level of each node
        - value → list of nodes
    */
 
    queue<TreeNode*> q;
    q.push(root);

    parent[root] = NULL;
    levelMap[root] = 0;

    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();

        mp[curr->val].push_back(curr);

        if(curr->left){
            parent[curr->left] = curr;
            levelMap[curr->left] = levelMap[curr] + 1;
            q.push(curr->left);
        }

        if(curr->right){
            parent[curr->right] = curr;
            levelMap[curr->right] = levelMap[curr] + 1;
            q.push(curr->right);
        }
    }
}

/* Distance using parent pointers (NO LCA recursion) */
int calculate_Distance_Between_Nodes(TreeNode* p, TreeNode* q, unordered_map<TreeNode*, TreeNode*> &parent, unordered_map<TreeNode*, int> &levelMap){
    int dist = 0;

    // bring both nodes to same level
    while(levelMap[p] > levelMap[q]){
        p = parent[p];
        dist++;
    }
    while(levelMap[q] > levelMap[p]){
        q = parent[q];
        dist++;
    }

    // move both up until they meet (LCA)
    while(p != q){
        p = parent[p];
        q = parent[q];
        dist += 2;
    }

    return dist;
}

bool optimal_findPair(TreeNode* root, int target, int d){
    // Time complexity: O(n^2) average
    // Space complexity: O(n)

    /* ✅ Key Optimization Idea (Intuition)

        Your bottleneck was this:
            For every valid value pair → you were calling findLCA()
            findLCA() is O(n)
            Nested inside O(n²) pair checking
                ➡️ Total = O(n³) ❌

        💡 Optimization Strategy

        We eliminate repeated LCA computation by:

            1. Preprocessing once using BFS
                store parent[node]
                store level[node]
                store value → list of nodes

            2. Compute distance in O(height) using parent pointers
                (no LCA recursion per pair)

        So distance becomes:
        O(h) instead of O(n)

        🚀 Optimized Time Complexity

        Preprocessing BFS	O(n)
        Pair generation	O(n²)
        Distance per pair	O(h)
        Total = O(n) + O(n² x h) ==> O(n²) 
    */

    if(root == NULL) return false;

    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, int> levelMap;

    // value → list of nodes
    unordered_map<int, vector<TreeNode*>> mp;

    // preprocessing
    buildInfo(root, parent, levelMap, mp);

    // searching for required in map to form pair - (required, curr->val)
    for(auto &x : mp){
        int val1 = x.first;
        int required = target - val1;

        if(mp.find(required) == mp.end()) continue;

        for(TreeNode* n1 : mp[val1]){
            for(TreeNode* n2 : mp[required]){
                // both nodes should not be same
                if(n1 == n2) continue;

                // both nodes should not be at same level
                if(levelMap[n1] == levelMap[n2]) continue;

                // check if distance between 2 nodes is equal to d
                int distance = calculate_Distance_Between_Nodes(
                    n1, n2, parent, levelMap
                );

                if(distance == d){
                    cout << n1->val << " " << n2->val << endl;
                    return true;
                }
            }
        }
    }

    // no pair found
    return false;
}





int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(4);
    root->left->right->right->right = new TreeNode(6);
    root->left->right->right->right->right = new TreeNode(6);
    root->right->right = new TreeNode(70);

    /* 
    check for below d=5 , target = 10 ans = true
          1
        /  \
       2    3
      / \    \
     4   5    70
          \
           4
            \ 
             6
              \ 
               6
    */

    int target = 10;
    int d = 4;

    // bool result = brute_findPair(root, target, d);
    // if (result){
    //     cout<<"Pair found"<<endl;
    // }else{
    //     cout<<"No pair found"<<endl;
    // }

    bool result = optimal_findPair(root, target, d);
    if (result){
        cout<<"Pair found"<<endl;
    }else{
        cout<<"No pair found"<<endl;
    }
}
