#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Number of Triangles in Directed and Undirected Graphs

Given a Graph, count number of triangles in it. The graph is can be directed or undirected.

Example:

Input: digraph[V][V] = {{0, 0, 1, 0},
                        {1, 0, 0, 1},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0}};
Output: 2


Intuition: ----------------------------------------------------------------------------------------

The idea is to use three nested loops to consider every triplet (i, j, k) and check for the above condition (there is an edge from i to j, j to k and k to i)

However in an undirected graph, the triplet (i, j, k) can be permuted to give six combination (See previous post for details). Hence we divide the total count by 6 to get the actual number of triangles.

In case of directed graph, the number of permutation would be 3 (as order of nodes becomes relevant). Hence in this case the total number of triangles will be obtained by dividing total count by 3. For example consider the directed graph given below

*/

int countTriangle(int graph[4][4], bool isDirected){
    // Time complexity is O(n^3) and can't be reduced any further

    int V = 4;
    // Initialize result
    int count_Triangle = 0;

    // Consider every possible triplet of edges in graph
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            for (int k = 0; k < V; k++){
                // Check the triplet if it satisfies the condition
                if (graph[i][j] && graph[j][k] && graph[k][i]){
                    count_Triangle++;
                }
            }
        }
    }

    // If graph is directed, division is done by 3, else division by 6 is done
    isDirected ? count_Triangle /= 3 : count_Triangle /= 6;

    return count_Triangle;
}

// driver function to check the program
int main(){
    // Create adjacency matrix of an undirected graph
    int graph[4][4] = {{0, 1, 1, 0},
                      {1, 0, 1, 1},
                      {1, 1, 0, 1},
                      {0, 1, 1, 0}};

    // Create adjacency matrix of a directed graph
    int digraph[4][4] = {{0, 0, 1, 0},
                        {1, 0, 0, 1},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0}};

    cout << "The Number of triangles in undirected graph : "<< countTriangle(graph, false);
    cout << "\n\nThe Number of triangles in directed graph : "<< countTriangle(digraph, true);

}