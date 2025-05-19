#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Floyd Warshall Algorithm 

Definition: 
The Floyd Warshall algorithm is a multi-source shortest path algorithm that helps find the shortest distances between all pairs of nodes in a graph. It works by repeatedly improving the path between every pair of nodes, checking if going through another node gives a shorter route. 

It also helps to detect negative cycles as well. 

In Floyd Warshall's algorithm, we need to check every possible path going via each possible node. And after checking every possible path, we will figure out the shortest path(a kind of brute force approach to find the shortest path).


simple meaning : Get me the shortest path from every node to every other node.

Any path that takes least amount of edge weight is known as shortest path.


Problem Statement: 
The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.

The graph does not contain any negative weight cycles.

NOTE : Do it in place.

Input Format: 
matrix[][] = {{0, 2, -1, -1},{1, 0, 3, -1},{-1, -1, 0, -1},{3, 5, 4, 0} }
Result:
0 2 5 -1 
1 0 3 -1 
-1 -1 0 -1 
3 5 4 0 
Explanation: In this example, the final matrix is storing the shortest distances. For example, matrix[i][j] is storing the shortest distance from node i to j.

Input Format: 
matrix[][] = {{0,25},{-1,0}}
Result:   
0 25  
-1 0
Explanation: In this example, the shortest distance is already given (if it exists).


Intuition: --------------------------------------------------------------------

Basically, the Floyd Warshall algorithm is a multi-source shortest path algorithm and it helps to detect negative cycles as well. The shortest path between node u and v necessarily means the path(from u to v) for which the sum of the edge weights is minimum.

In Floyd Warshall's algorithm, we need to check every possible path going via each possible node. And after checking every possible path, we will figure out the shortest path(a kind of brute force approach to find the shortest path).

Here we will calculate dist[i][j] for every possible node k (k = 0, 1….V, where V = no. of nodes), and will select the minimum value as our result.

                     1
                (2)-----►(4)
               ▲   \     / 
            2 /    3\   / 1
             /   6   ▼ ▼ 
           (0)------►(1)
             \        ▲
            4 \      / 1
               ▼    /
                 (3)

    shortest distance from 0 to 1, i=0, j=1
    d[0][1] = 0 --> 1 = 6
    d[0][1] = 0--->2 + 2--->1 = 5
    d[0][1] = 0--->3 + 3--->1 = 5
    d[0][1] = 0--->4 + 4--->1  = 4  something we need which is precomputed (here precompute value 0--->4 weight is 3 which we have to precompute)

Formula:

matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j])
where i = source node, j = destination node, and k = the node via which we are reaching from i to j.


via means source via/through destination 
for example: i=0,j=3 source=0, destination=3 
   via
0   0   3
0   1   3
0   2   3
0   3   3
0   4   3


Important Interview questions related to Floyd-Warshall

Q1. How to Detect Negative Cycle in a graph using Floyd Warshall Algorithm?
Ans: Negative Cycle: A cycle is called a negative cycle if the sum of all its weights becomes negative. The following illustration is an example of a negative cycle

      -2
   (1)----->(2)
    \       /
     \     / -1
    2 \   /
       \ /
       (3)

    Sum= 2+(-2)+(-1) => -1

We have previously said that the cost of reaching a node from itself must be 0. But in the above graph, if we try to reach node 0 from itself we can follow the path: 0->1->2->0. In this case, the cost to reach node 0 from itself becomes -3 which is less than 0. This is only possible if the graph contains a negative cycle.

So, if we find that the cost of reaching any node from itself is less than 0, we can conclude that the graph has a negative cycle



Q2. How is Floyd-warshall algorithm different from Dijkstra's algorithm?
Ans: 

➖Dijkstra Algorithm:
    1. Dijkstra’s Algorithm is a Single-Source Shortest Path algorithm where we find the shortest distance between source node to all other nodes where we find the shortest distances between all pairs of nodes in a graph

    2. Dijkstra’s Algorithm uses a Greedy approach to find the shortest path from the source to all other vertices. It starts from the source vertex and maintains a set of vertices with known minimum distances from the source. The key idea of the Greedy strategy is selecting the vertex with the currently shortest known distance from the Source and exploring it next. 

    3. Dijkstra's algorithm does not work correctly with graphs that have negative edge weights.

    4. The time complexity of Dijkstra Algorithm depends on the specific implementation and data structures used. It Typically uses a priority queue or min-heap.

    5. It is efficient for finding shortest paths from a single source.

➖Floyd-warshall algorithm: 
    1. while Floyd-warshall algorithm is a multi-Source Shortest Path algorithm.

    2. Floyd Warshall Algorithm uses Dynamic Programming approach to compute shortest distance between all pair of vertices. 

    3. The Floyd-Warshall algorithm can handle graphs with both positive and negative edge weights.

    4. For the Floyd Warshall Algorithm, the time complexity is O(V^3), where V represents the number of vertices in the graph. It involves three nested loops that iterate through all possible pairs of nodes and consider all possible intermediaries, leading to a cubic time complexity.

    5. It is suitable for finding shortest paths between all pairs of vertices.



Q3. How is Floyd-warshall algorithm different from Bellman-Ford algorithm?
Ans: 
➖Bellman-Ford Algorithm:
The Bellman-Ford algorithm is a single-source shortest-path algorithm that works by iteratively relaxing edges in the graph until the shortest path to all vertices is found. It is especially useful for graphs with negative edge weights, as it can detect negative cycles and return a suitable error message. Handles negative edge weights and can detect negative weight cycles. Time Complexity: O(V × E)

➖Floyd-Warshall Algorithm:
The Floyd-Warshall algorithm is a multi-source shortest path algorithm that works by computing the shortest path between all pairs of vertices in the graph using dynamic programming. Can handle negative edge weights, but not negative weight cycles. Time Complexity: O(V³)


Q4. What will happen if we will apply Dijkstra’s algorithm for this purpose?
Ans: If the graph has a negative cycle: We cannot apply Dijkstra’s algorithm to the graph which contains a negative cycle. It will give TLE error in that case.

If the graph does not contain a negative cycle: In this case, we will apply Dijkstra’s algorithm for every possible node to make it work like a multi-source shortest path algorithm like Floyd Warshall. The time complexity of Floyd Warshall is O(V^3) whereas if we apply Dijkstra’s algorithm for the same purpose the time complexity reduces to O(V*(E*logV)) (where v = no. of vertices). 

*/

void shortest_distance(vector<vector<int>> &matrix){
    // Time complexity: O(N^3)
    // Space complexity: O(N^2) we are using matrix
    int n = matrix.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (matrix[i][j] == -1){
                matrix[i][j] = 1e9;
            }
            // self always 0 means diagonal 
            if (i == j)
                matrix[i][j] = 0;
        }
    }

    // via means source via/through destination 
    for (int via = 0; via < n; via++){
        // Pick all vertices as source one by one
        for (int i = 0; i < n; i++){
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < n; j++){
                // shortest path from i to j 
                if(matrix[i][via] != 1e9 && matrix[via][j]!= 1e9){
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
    }


    // In interviw if they ask What if their is a negative cycle ? ---> just return -1
    // for (int i = 0; i < n; i++){
    //     if(matrix[i][i]!= 1e9 && matrix[i][i] < 0 ){
    //         cout<<"Negative cycle Exist"<<endl;
    //         return -1;
    //    }
    // } 
    

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            // if it is not reachable change it to -1
            if (matrix[i][j] == 1e9){
                matrix[i][j] = -1;
            }
        }
    }
}

int main(){
    int V = 4;
    vector<vector<int>> matrix(V, vector<int>(V, -1));
    matrix[0][1] = 2;
    matrix[1][0] = 1;
    matrix[1][2] = 3;
    matrix[3][0] = 3;
    matrix[3][1] = 5;
    matrix[3][2] = 4;

    shortest_distance(matrix);

    for (auto row : matrix){
        for (auto cell : row){
            cout << cell << " ";
        }
        cout << endl;
    }
}