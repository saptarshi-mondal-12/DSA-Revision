void dfs(int node, vector<int>&visited, vector<vector<int>> &adj, stack<int> &st){
    visited[node]=1;
    for(auto it: adj[node]){
        if (!visited[it]) {  
            dfs(it, visited, adj, st);
        }
    }
    st.push(node);
}

void dfs3(int node, vector<int>&visited, vector<vector<int>> &reverseAdj){
    visited[node]=1;
    for(auto it: reverseAdj[node]){
        if (!visited[it]){
            dfs3(it, visited, reverseAdj);
        }
    }
}