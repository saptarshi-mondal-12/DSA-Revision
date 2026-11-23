
/* Q. Diagonal Tree Traversal - AMAZON 2026 

Given a Binary Tree, return the diagonal traversal of the binary tree.

Consider imaginary lines passing between the nodes of the binary tree. All nodes lying on the same diagonal belong to the same diagonal group.
Return a single list containing all the nodes in diagonal order, starting from the topmost diagonal and moving to the next diagonals.
If nodes from the left and right subtrees belong to the same diagonal, the nodes from the left subtree must be included before the nodes from the right subtree.
Examples :

Input : root = [8, 3, 10, 1, 6, N, 14, N, N, 4, 7, 13]
     8
    / \
    3   10
   / \    \
  1   6    14
     / \   /
    4   7 13
Output : [8, 10, 14, 3, 6, 7, 13, 1, 4]


*/

vector<int> diagonal(Node *root) {
    // code here
    vector<int> result;
    if (root == NULL) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* currNode = q.front();
        q.pop();

        while (currNode != NULL) {
            result.push_back(currNode->data);

            if (currNode->left != NULL) {
                q.push(currNode->left);
            }
            currNode = currNode->right;
        }
    }
    return result;
}