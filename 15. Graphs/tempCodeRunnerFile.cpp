int n=adj.size();
    vector<vector<int>>adjacencyList;

    // To change adjacency matrix to adjacency list
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // self nodes are not considered
            if(adj[i][j]==1 && i!=j){
                adjacencyList[i].push_back(j);
                adjacencyList[j].push_back(i);
            }
        }
    }