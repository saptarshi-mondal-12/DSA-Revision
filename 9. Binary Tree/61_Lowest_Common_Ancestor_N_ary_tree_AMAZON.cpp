#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Lowest common Ancestor of N-ary tree - AMAZON 2025

*/

class Node {
public:
    string val;
    vector<Node*> children;  // N-ary children
    Node(string x) {
        val = x;
    }
};

Node* LowestCommonAncestor(Node* root, Node* a, Node* b){
    // Time complexiy: O(n) 
    // Space complexity: O(h) auxiliary stack space for recursive

    // 1) Base cases
    if (root == NULL || root == a || root == b) return root;

    // 2) Explore all children and aggregate results
    int count = 0; // how many child subtrees returned a non-null result
    Node* temp = NULL; // store the first non-null result

    for (Node* child : root->children) {
        Node* res = LowestCommonAncestor(child, a, b);
        if (res) {
            count++;
            if (temp == NULL) temp = res; // remember the first hit
        }
    }

    // 3) Decision at this node
    if (count >= 2) return root; // Found a and b in different subtrees
    return temp;

}

int main(){
    // Tree structure (N = 3):
    //            A
    //        /   |   \
    //       B    C    D
    //      / \       / \
    //     E   F     G   H

    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");
    Node* F = new Node("F");
    Node* G = new Node("G");
    Node* H = new Node("H");

    A->children = {B, C, D};
    B->children = {E, F};
    C->children = {};
    D->children = {G, H};

    // Test cases
    Node* lca1 = LowestCommonAncestor(A, E, F);
    cout << "LCA of E and F: " << lca1->val << endl; // Expected: B

    Node* lca2 = LowestCommonAncestor(A, E, G);
    cout << "LCA of E and G: " << lca2->val << endl; // Expected: A

    Node* lca3 = LowestCommonAncestor(A, G, H);
    cout << "LCA of G and H: " << lca3->val << endl; // Expected: D

    return 0;
}