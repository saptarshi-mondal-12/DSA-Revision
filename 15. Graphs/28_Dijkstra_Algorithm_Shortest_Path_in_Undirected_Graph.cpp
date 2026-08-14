#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Shortest Path in Undirected Graph | Dijkstra Algorithm | Priority Queue

Given an Undirected Graph having unit weight, find the shortest path from the source to all other nodes in this graph. In this problem statement, we have assumed the source vertex is given. If a vertex is unreachable from the source node, then return -1 for that vertex.

Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.


Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
Output: [4, 3, 0]
Explanation: Shortest Paths:
For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
For 2 to 1 minimum distance will be 3. By following path 2 -> 1
For 2 to 2 minimum distance will be 0. By following path 2 -> 2


Input: V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]], src = 0
Output: [0, 4, 8, 10, 10]
Explanation: Shortest Paths: 
For 0 to 1 minimum distance will be 4. By following path 0 -> 1
For 0 to 2 minimum distance will be 8. By following path 0 -> 2
For 0 to 3 minimum distance will be 10. By following path 0 -> 2 -> 3 
For 0 to 4 minimum distance will be 10. By following path 0 -> 1 -> 4


NOTE - All methods gives same answer - 
    Method 1: Simple BFS using queue Q27. 
    Method 2: Dijkstra Algorithm using priority Queue - min-heap data structure Q28.
    Method 3: Dijkstra Algorithm using set data structure


-----Follow Questions-----

Q1. Why dijkstra algorithm will not work for negative weight cycle?
Ans: Do a dry run on below example and explain the interviewer 
Eg:
        -2
    (0)-----------(1)

Here, we initially mark the source node ‘0’ as 0 and node ‘1’ as INFINITY (as it is unvisited). Now, when we start applying the above algorithm on this we notice that both the nodes are updated each time we come to them again. This is due to the negative weight of ‘-2’ which makes the total distance to the node always lesser than the previous value. Therefore, due to inaccurate results, we assume the graph to always contain positive weights while using Dijkstra's Algorithm.

Its keep on going because in every traversal the distance reduces because of negative weights. it just decreasing, it keep going forever forever. Thats why any graph with negative weight will not work in dijkstra algorithm because it will fall in an infinite for loop. 


Q2. Why priority queue is used ? or why a data structure were you need minimum at first is used ?
Ans: because we always wanted minimum distance at first thst's the reason we took priority queue. We the avoid the exploration of too many paths. We act like a greedy - minimum first.
 

Q3. Why priority queue why not Queue data structure?
Ans: Queue consider all possible paths and take the minimum of them (kind of brute force - going to all paths and figureing out minimum among them  and in priority i will go greedly, i'll go minimum first otherwise we end up exploring too many paths). 

But in priority queue, priority queue set minimum at first so that all other path with greater distance will not consider. that's why minimum distance is prefered in priority queue so that we don't have to emncounter a lot of paths . Queue take lot of time comlexity exploring all paths that why priority queue is used. 



Q4. Time complexity derivation - why (E Log V)
Ans: Where E = Number of edges and V = Number of Nodes.

while(!pq.empty()){ ------------------------------> [v]
    pop()  -------> log(heap size) worst case 

    for(adjacent node){ --------------------------> ne (ne = v-1 ) 
    (if it is a dense graph and each node is connected to all other node means, 1 node connected to everyone how many node one can have i.e total v-1 node ) 

        push()  -----------------------------------> log(heap size)
    }
}

step 1: O(v x {pop from min heap + no of edges on each vertex x push into pq})

step 2: O(v x {log(heap size) + ne x log(heap size)})

step 3: O(v x {log(heap size) x (1 + ne)})             [taking log(heap size) as common]

step 4: O(v x {log(heap size) x (1 + v - 1)})          [ne = v-1, at max each one have v-1 adjacent nodes]

step 5: O(v x v x log(heap size))                      

step 6: O(v^2 x log(heap size))                       [every one is pushing every one ]

step 7: O(v^2 x log(v^2))                   

step 8: O(v^2 x 2 log(v))                  [What is v^2 = total no of nodes]

step 9: O(E x log(v))  time complexity in worst case scenario at dijkstra algorithm



Q. [What is v^2 = total no of nodes] how ? 
Ans Assume there are total 4 node. If one node is connected to 3 (i.e. v-1 node) and there are total v nodes and every one has v-1 edges then total will be (v-1) x v = v^2 edges which is total no of edges E

1 = connected to all other 3 node  1--->2,  1---->3, 1----->4 [v-1]
2 = connected to all other 3 node  2--->1,  2---->3, 2----->4
3 = connected to all other 3 node  3--->1,  3---->2, 3----->4
4 = connected to all other 3 node  4--->1,  4---->2, 4----->3
*/


vector<int>shortestPath(int n, vector<vector<int>>edges, int src){
    // Time complexity: O(E log(V)), Where E = Number of edges and V = Number of Nodes.
    // Space complexity: O(E + V)

    // 1. Creating adjacency list
    vector<vector<pair<int,int>>> adjacencyList(n);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int weight=edges[i][2];

        adjacencyList[u].push_back({weight, v});
        adjacencyList[v].push_back({weight, u});
    }
   

    // Implementing Dijkstra Algorithm using priority Queue
    
    // Create a priority queue for storing the nodes as a pair {dist,node}
    // where dist is the distance from source to the node. 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialising distTo list with a large number to indicate the nodes are unvisited initially.
    // This list contains distance from source to the nodes.
    vector<int>distance(n,1e9);
    
    // Source initialised with dist=0.
    distance[src] = 0; 

    // storing order {node,weight}
    pq.push({0, src});

    // Now, pop the minimum distance node first from the min-heap
    // and traverse for all its adjacent nodes.
    while (!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Check for all adjacent nodes of the popped out
        // element whether the prev dist is larger than current or not.
        for (auto it : adjacencyList[node]){
            int wt = it.first;
            int v = it.second;
            if (dis + wt < distance[v]){
                distance[v] = dis + wt;
    
                // If current distance is smaller, push it into the queue.
                pq.push({dis + wt, v});
            }
        }
    }
    // Return the list containing shortest distances from source to all the nodes.
    return distance; 
}

int main(){
    int n=5;
    vector<vector<int>> edges= {{0, 1, 4}, {0, 2, 8}, {1, 4, 6}, {2, 3, 2}, {3, 4, 10}};
    int src=0;

    vector<int>ans=shortestPath(n,edges, src);
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
}
